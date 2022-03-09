#pragma once 
#include <functional> 
#include <future> 
#include <mutex> 
#include <queue> 
#include <thread> 
#include <utility> 
#include <vector> 
#include "SafeQueue.h" //任务队列
class ThreadPool {
private:
	class ThreadWorker {//内置线程工作类
	private:
		int m_id; //工作id
		ThreadPool * m_pool;//所属线程池
	public:
		//构造函数
		ThreadWorker(ThreadPool * pool, const int id)
			: m_pool(pool), m_id(id) 
		{
		}
		//重载`()`操作

		void operator()() {
			std::function<void()> func; //定义基础函数类func
			bool dequeued; //是否正在取出队列中元素
						   //判断线程池是否关闭，没有关闭，循环提取
			while (!m_pool->m_shutdown) {
				{
					//为线程环境锁加锁，互访问工作线程的休眠和唤醒
					std::unique_lock<std::mutex> lock(m_pool->m_conditional_mutex);
					//如果任务队列为空，阻塞当前线程
					if (m_pool->m_queue.empty()) {
						m_pool->m_conditional_lock.wait(lock); //等待条件变量通知，开启线程
					}
					//取出任务队列中的元素
					dequeued = m_pool->m_queue.dequeue(func);
				}
				//如果成功取出，执行工作函数
				if (dequeued) {
					func();
				}
			}
		}
	};

	bool m_shutdown; //线程池是否关闭
	SafeQueue<std::function<void()>> m_queue;//执行函数安全队列，即任务队列
	std::vector<std::thread> m_threads; //工作线程队列
	std::mutex m_conditional_mutex;//线程休眠锁互斥变量
	std::condition_variable m_conditional_lock; //线程环境锁，让线程可以处于休眠或者唤醒状态

public:
	//线程池构造函数
	ThreadPool(const int n_threads)
		: m_threads(std::vector<std::thread>(n_threads)), m_shutdown(false) {
	}
	ThreadPool(const ThreadPool &) = delete; //拷贝构造函数，并且取消默认父类构造函数

	ThreadPool(ThreadPool &&) = delete; // 拷贝构造函数，允许右值引用

	ThreadPool & operator=(const ThreadPool &) = delete; // 赋值操作

	ThreadPool & operator=(ThreadPool &&) = delete; //赋值操作

													// Inits thread pool

	void init() {
		for (int i = 0; i < m_threads.size(); ++i) {
			m_threads[i] = std::thread(ThreadWorker(this, i));//分配工作线程

		}
	}

	// Waits until threads finish their current task and shutdowns the pool
	void shutdown() {
		m_shutdown = true;
		m_conditional_lock.notify_all(); //通知 唤醒所有工作线程

		for (int i = 0; i < m_threads.size(); ++i) {
			if (m_threads[i].joinable()) { //判断线程是否正在等待
				m_threads[i].join();  //将线程加入等待队列
			}
		}
	}

	// Submit a function to be executed asynchronously by the pool
	//线程的主要工作函数，使用了后置返回类型，自动判断函数返回值

/*
返回类型后置：
除了构造函数和析构函数以外，函数声明都需要明确函数的返回类型，在传统的C或者C++中，函数声明大致是这个样子：
int getSum(int a, int b);
第一个int就是函数的返回类型，它表明函数的返回值类型为整数。在新的C++11以后，我们也可以这样声明：
auto getSum(int a, int b)->int;
在原来放返回值类型的位置写auto，在函数声明结束以后接一个'->'再跟着写函数的返回值类型。两种方式的效果是一样的。
*/


	//模板：定义了用来函数返回的类型F，以及不定参数Args
	template<typename F, typename...Args>
	auto submit(F&& f, Args&&... args) -> future<decltype(f(args...))> {//步骤1、2
		// Create a function with bounded parameters ready to execute
		// 
		//步骤3
		std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);//连接函数和参数定义，特殊函数类型,避免左、右值错误

																												// Encapsulate it into a shared ptr in order to be able to copy construct // assign 
																												//封装获取任务对象，方便另外一个线程查看结果
		
		//std::packaged_task 包装一个可调用的对象，并且允许异步获取该可调用对象产生的结果
		//std::make_shared 创建智能指针shared_ptr,指向绑定的package_task，package_task用于异步获取结果
		func();
		//步骤4
		auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);

		// Wrap packaged task into void function
		//利用lambda表达式，返回一个函数对象

		//步骤5
		std::function<void()> wrapper_func = [task_ptr]() {
			(*task_ptr)();
		};

		// 队列通用安全封包函数，并压入安全队列
		//步骤6
		m_queue.enqueue(wrapper_func);

		// 唤醒一个等待中的线程
		//步骤6
		m_conditional_lock.notify_one();

		// 返回先前注册的任务指针
		//步骤7
		return task_ptr->get_future();
	}


	/*submit总结：
	为了实现可以任意参数，任意参数个数、任意返回值的函数都能塞入任务容器中
	步骤1、使用了相应的返回类型后置，来模板化返回值，实现适配不同返回类型的函数塞入任务容器，并获取return值(这里还存在待解决的问题)
	步骤2、函数使用了可变模版参数函数，定义了对应的返回值参数模板以及函数入参模板，其中的函数入参模板采用的是可变模板
	步骤3、使用bind，将函数f与参数args进行绑定，并用function包装函数指针，
	步骤4、为了解决刚开始的获取任务函数的返回值的问题，使用futrue头文件中的packaged_task对上一步function包装好的函数指针进行包装，以便共享状态(shared state)，用于保存任务的返回值，并用智能指针指向packaged_task
	
	步骤5、进行统一操作，用function<void()>函数指针对packaged_task进行包装，在包装中，使用lambda表达式对智能指针指向的函数进行调用，因此，封装好的指针就能调用相应的函数了，
	步骤6、将对应的function<void()>函数指针塞入任务容器
	步骤7、通过get_future获得与 packaged_task 共享状态相关联的 future 对象，供外部使用；
	*/
};