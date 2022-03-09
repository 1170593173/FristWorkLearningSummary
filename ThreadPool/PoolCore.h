#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <future>

class PoolCore
{
public:
	//explicit指定构造函数或转换函数 (C++11起)为显式, 即它不能用于隐式转换和复制初始化.
	explicit PoolCore(size_t threadNum);
	~PoolCore();

	//函数模板、可变参数模板
	template<typename F, typename... Args>
	//返回类型后置，auto getSum(int a, int b)->int;这里的返回类型后置返回的是future对象，future具体的参数使用函数推断标识符对f(args...)进行推断
	auto submit(F&& f, Args&&... args) -> std::future<decltype(f(args...))> {
		//首先使用packaged_task对f(args...)返回值类型进行封装，目的是在另外的线程中异步的获取到打包后的函数返回值，
		//然后对packaged_task构造智能指针，目的是便于赋值、拷贝和析构，
		//使用bind对函数与参数进行绑定，产生一个新的可调用实体
		auto taskPtr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(
			std::bind(std::forward<F>(f), std::forward<Args>(args)...)
			);
		{
			//尝试获取任务线程的线程锁，对调用的句柄taskPtr进行封装，封装为void ()类型，并塞入对应的任务队列
			std::unique_lock<std::mutex> ul(mtx_);
			if (stop_) { throw std::runtime_error("submit on stopped ThreadPool"); }
			tasks_.emplace([taskPtr]() { (*taskPtr)(); });
			//离开作用域，unique_lock对锁进行自动解锁，主要目的是防止 人为忘记解锁或出现异常导致忘记解锁
		}
		//条件变量通知其他线程可以进行锁的竞争
		cv_.notify_one();
		//taskPtr本质上是futrue<>类型的，可以通过get_future来获取对应的绑定的promise的结果或者packed_task的返回结果
		return taskPtr->get_future();
	}

private:
	bool stop_;
	std::vector<std::thread>workers_;//工作队列，由多个线程组成的队列
	std::queue<std::function<void()>>tasks_;//任务队列
	std::mutex mtx_;
	std::condition_variable cv_;
};

