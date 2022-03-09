#include "SDR.h"
#include <QtWidgets/QApplication>
#include"MySingleTon-queue.h"
#include"thread_test.h"
#include "MySingleTon-queue.h"
#include "MySingleTon.h"
#include "thread_pool.h"

#include "thread_pool2.h"
#include <iostream> 
#include <random>


/*********************************************队列容器测试：实现任意队列使用，并保证队列唯一；多端队列任务输入，并实现优先级队列********************************************/

/*队里容器中的元素结构体*/
//struct Queue_Element
//{
//	string queue_name;
//	Queue_ElementPtr m_Queue_ElementPtr;
//	mutex *m_queue_mutex;
//};
MySingleTon_queue::Ptr MySingleTon_queue::m_instance_ptr = nullptr;
std::mutex MySingleTon_queue::m_mutex;
//std::mutex MySingleTon_queue::m_mutex_messege;
std::mutex MySingleTon_queue::m_mutex_queue_vector;

std::mutex MySingleTon::m_mutex_messege;
/*存放队列的容器*/
//MySingleTon_queue::Queue_ElementPtr MySingleTon_queue::this_Queue_ElementPtr;
//std::mutex * MySingleTon_queue::this_queue_mutex;

//
void func1(string str) {
	MySingleTon_queue::Queue_Element m_queue;
	//在对应线程内创建接收队列元素的栈区
	//Queue_Element temp
	MySingleTon_queue::Ptr instance = MySingleTon_queue::get_instance();
	m_queue = instance->create_queue("queue2");
	for (int i = 0; i < 1000; ++i) {
		instance->add_event(str, m_queue);
		_sleep(500);
	}

}

void func() {
	MySingleTon_queue::Queue_Element m_queue;
	//在对应线程内创建接收队列元素的栈区
	//Queue_Element temp
	MySingleTon_queue::Ptr instance = MySingleTon_queue::get_instance();
	m_queue = instance->create_queue("queue2");
	for (int i = 0; i < 1000; ++i) {
		instance->add_event("func", m_queue);
		_sleep(500);
	}
	
}


void funcqueueinput1() {
	MySingleTon_queue::Ptr instance = MySingleTon_queue::get_instance();
	MySingleTon_queue::Queue_Element m_queue = instance->create_queue("queue1");
	for (int i = 0; i < 1000; ++i) {
		instance->add_event("funcqueueinput1", m_queue);
		_sleep(10);
	}
}

void funcqueueinput2() {
	MySingleTon_queue::Ptr instance = MySingleTon_queue::get_instance();
	MySingleTon_queue::Queue_Element m_queue = instance->create_queue("queue1");
	for (int i = 0; i < 1000; ++i) {
		instance->add_event("funcqueueinput2", m_queue);
		_sleep(10);
	}
}

void funcqueueoutput() {
	MySingleTon_queue::Ptr m_singleTon = MySingleTon_queue::get_instance();
	MySingleTon_queue::Queue_Element m_queue = m_singleTon->create_queue("queue1");

	for (int i = 0; i < 50;++i)
	{
		string getstr = m_singleTon->get_event(m_queue);
		if (getstr != "")
		{
			cout << m_queue.queue_name + "_" + getstr << endl;
		}

		_sleep(100);
	}

}

//int main(int argc, char *argv[])
//{
//	thread_pool m_thread_pool(3);//定义线程池中的线程数量
//	thread_test testitem;
//	m_thread_pool.add_task(func1); //普通函数加入线程池的方法
//	//m_thread_pool.add_task(testitem);//()重载函数加入线程池的方法
//	m_thread_pool.add_task(bind(&thread_test::testFunc_input, testitem));//类中普通函数加入线程池的方法
//	m_thread_pool.add_task(bind(&thread_test::testFunc_output, testitem));
//

//	///*之前存在过一个问题：在使用队列的时候，如果不创建可能获取不到，因为线程执行的顺序不太固定*/
//
//	///**************************************************************************
//	//Author: chuck.liu
//	//Date:2021-08-19
//	//Description:
//	//测试单例模式构建的队列容器，首先测试了对容器添加一个指定名称的队列，进行读取与删除；
//	//然后添加两个或者多个指定名称的队列，多线程的对多个队列进行读取与删除；
//	//**************************************************************************/
//	//thread_test test1;
//	//thread m_thread4(func);
//	//thread m_thread1(test1);
//	//thread m_thread2(&thread_test::testFunc_input, &test1);
//	//thread m_thread3(&thread_test::testFunc_output, &test1);
//	//
//	//thread m_thread5(funcqueueinput1);
//	//thread m_thread6(funcqueueinput2);
//	//thread m_thread7(funcqueueoutput);
//
//	//m_thread4.join();
//	//m_thread1.join();
//	//m_thread2.join();
//	//m_thread3.join();
//	//
//	//m_thread5.join();
//	//m_thread6.join();
//	//m_thread7.join();
//	///***************************************************************************/
//
//
//	///**************************************************************************
//	//Author: chuck.liu
//	//Date:2021-08-19
//	//Description:
//	//测试使用队列，用户操作与程序产生的消息同时作为生产者，
//	//可以设定用户操作为高优先级，优先处理对应的事件；
//	//**************************************************************************/
//	//SDR_Engine SDR_Engine_test1;
//	//thread m_thread(&SDR_Engine::run, &SDR_Engine_test1);
//	//if (m_thread.joinable()) {
//	//	m_thread.detach();
//	//	//m_thread.join();
//	//}
//	///***************************************************************************/
//
//
//	QApplication a(argc, argv);
//	SDR w;
//	w.show();
//	return a.exec();
//
//	//return 0;
//	
//}
/*********************************************队列容器测试：实现任意队列使用，并保证队列唯一；多端队列任务输入，并实现优先级队列********************************************/



/*************************************************************************线程池测试*************************************************************************************/
std::random_device rd; //真实随机数产生器
std::mt19937 mt(rd()); //生成计算随机数mt;

std::uniform_int_distribution<int> dist(-1000, 1000);//生成-1000到1000之间的离散均匀分部数
auto rnd = std::bind(dist, mt);


//
void testjj(int i,string te) {
	std::cout << te << "_" << to_string(i) << endl;
}
 
//设置线程睡眠时间
void simulate_hard_computation() {
	std::this_thread::sleep_for(std::chrono::milliseconds(2000 + rnd()));
}

// 添加两个数字的简单函数并打印结果
void multiply(const int a, const int b) {
	simulate_hard_computation();
	const int res = a * b;
	std::cout << a << " * " << b << " = " << res << std::endl;
}

//添加并输出结果
void multiply_output(int & out, const int a, const int b) {
	simulate_hard_computation();
	out = a * b;
	std::cout << a << " * " << b << " = " << out << std::endl;
}

// 结果返回
int multiply_return(const int a, const int b) {
	simulate_hard_computation();
	const int res = a * b;
	std::cout << a << " * " << b << " = " << res << std::endl;
	return res;
}


int main() {
	// 创建3个线程的线程池
	ThreadPool pool(3);

	// 初始化线程池
	pool.init();

	// 提交乘法操作，总共30个
	for (int i = 1; i < 3; ++i) {
		for (int j = 1; j < 10; ++j) {
			pool.submit(multiply, i, j);
			pool.submit(testjj, j, "testjj");
		}
	}

	// 使用ref传递的输出参数提交函数
	int output_ref;
	auto future1 = pool.submit(multiply_output, std::ref(output_ref), 5, 6);

	// 等待乘法输出完成
	future1.get();
	std::cout << "Last operation result is equals to " << output_ref << std::endl;

	/*************************************************************************************/

	// 使用return参数提交函数
	auto future2 = pool.submit(multiply_return, 5, 3);
	// 等待乘法输出完成
	int res = future2.get();
	std::cout << "Last operation result is equals to " << res << std::endl;

	//关闭线程池
	pool.shutdown();
	getchar();
	return 0;
}
/*************************************************************************线程池测试*************************************************************************************/