#include "thread_pool.h"
#include <assert.h>
#include <iostream>
#include <sstream>


/*---------------------------------------------------------------------------------------------*/
/*创建线程池对象的时候，会对执行start()函数*/
thread_pool::thread_pool(int init_size)
	:m_init_threads_size(init_size),
	m_mutex(),
	m_cond(),
	m_is_started(false)
{
	start();
}

thread_pool::~thread_pool()
{
	if (m_is_started)
	{
		stop();
	}
}

/*start()函数将开启定义线程容器的大小，并开启所有线程
这里存在的最大疑问是：为什么线程池中的所有线程都在运行？
这里确实是开启了所有的线程，但是在任务缓存区中，如果不存在任务，也就是空的话，take()函数将会阻塞本线程的
也就是只有在任务缓存中存在任务的时候，线程池中的线程才会对收到条件变量的通知，开始执行*/
void thread_pool::start()
{
	assert(m_threads.empty());
	m_is_started = true;
	m_threads.reserve(m_init_threads_size);
	for (int i = 0; i < m_init_threads_size; ++i)
	{
		//这种操作就是在开始执行线程吗？好像不会阻塞主线程
		//bind表示的是参数绑定，将thread_loop作为线程入口
		m_threads.push_back(new std::thread(std::bind(&thread_pool::thread_loop, this)));
		//(*m_threads.begin() + i)->join();

	}

}
/*当对象被析构的时候，会对所有线程进行销毁*/
void thread_pool::stop()
{
	__SOLA_LOG(debug, "thread_pool::stop() stop.");
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		m_is_started = false;
		m_cond.notify_all();
		__SOLA_LOG(debug, "thread_pool::stop() notifyAll().");
	}

	for (threads_t::iterator it = m_threads.begin(); it != m_threads.end(); ++it)
	{
		(*it)->join();
		delete *it;
	}
	m_threads.clear();
}

/*线程的开始函数，执行回调函数，调用从任务缓存中取出来的任务*/
void thread_pool::thread_loop()
{
	__SOLA_LOG(debug, "thread_pool::threadLoop() tid : " + get_tid() + " start.");
	while (m_is_started)
	{
		/*take()函数从任务缓存队列中取出任务，返回的是指向任务函数的指针*/
		task_t task = take();
		if (task)//判断返回的指针是否为空
		{
			/*通过函数指针调用任务函数进行执行*/
			task();
		}
	}
	__SOLA_LOG(debug, "thread_pool::threadLoop() tid : " + get_tid() + " exit.");
}

/*对外接口：用户往任务队列中添加任务的接口函数*/
void thread_pool::add_task(const task_t& task)
{
	std::unique_lock<std::mutex> lock(m_mutex);
	/*while(m_tasks.isFull())
	{//when m_tasks have maxsize
	cond2.notify_one();
	}
	*/
	m_tasks.push_back(task);
	m_cond.notify_one();
}

//void thread_pool::add_task(const task_s& task)
//{
//	std::unique_lock<std::mutex> lock(m_mutex);
//	/*while(m_tasks.isFull())
//	{//when m_tasks have maxsize
//	cond2.notify_one();
//	}
//	*/
//	m_taskss.push_back(task);
//	//m_taskss.push_back(task);
//	m_cond.notify_one();
//}

/*取出任务的函数*/
thread_pool::task_t thread_pool::take()
{
	std::unique_lock<std::mutex> lock(m_mutex);
	//always use a while-loop, due to spurious wakeup
	/*需要将wait放在循环中，因为存在虚假唤醒的现象*/
	while (m_tasks.empty() && m_is_started)
	{
		__SOLA_LOG(debug, "thread_pool::take() tid : " + get_tid() + " wait.");
		m_cond.wait(lock);
	}

	__SOLA_LOG(debug, "thread_pool::take() tid : " + get_tid() + " wakeup.");

	task_t task;
	tasks_t::size_type size = m_tasks.size();
	if (!m_tasks.empty() && m_is_started)
	{
		task = m_tasks.front();
		m_tasks.pop_front();
		assert(size - 1 == m_tasks.size());
		/*if (TaskQueueSize_ > 0)
		{
		cond2.notify_one();
		}*/
	}
	return task;
}
