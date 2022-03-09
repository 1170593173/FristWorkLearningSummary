#include "thread_pool.h"
#include <assert.h>
#include <iostream>
#include <sstream>


/*---------------------------------------------------------------------------------------------*/
/*�����̳߳ض����ʱ�򣬻��ִ��start()����*/
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

/*start()���������������߳������Ĵ�С�������������߳�
������ڵ���������ǣ�Ϊʲô�̳߳��е������̶߳������У�
����ȷʵ�ǿ��������е��̣߳����������񻺴����У��������������Ҳ���ǿյĻ���take()���������������̵߳�
Ҳ����ֻ�������񻺴��д��������ʱ���̳߳��е��̲߳Ż���յ�����������֪ͨ����ʼִ��*/
void thread_pool::start()
{
	assert(m_threads.empty());
	m_is_started = true;
	m_threads.reserve(m_init_threads_size);
	for (int i = 0; i < m_init_threads_size; ++i)
	{
		//���ֲ��������ڿ�ʼִ���߳��𣿺��񲻻��������߳�
		//bind��ʾ���ǲ����󶨣���thread_loop��Ϊ�߳����
		m_threads.push_back(new std::thread(std::bind(&thread_pool::thread_loop, this)));
		//(*m_threads.begin() + i)->join();

	}

}
/*������������ʱ�򣬻�������߳̽�������*/
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

/*�̵߳Ŀ�ʼ������ִ�лص����������ô����񻺴���ȡ����������*/
void thread_pool::thread_loop()
{
	__SOLA_LOG(debug, "thread_pool::threadLoop() tid : " + get_tid() + " start.");
	while (m_is_started)
	{
		/*take()���������񻺴������ȡ�����񣬷��ص���ָ����������ָ��*/
		task_t task = take();
		if (task)//�жϷ��ص�ָ���Ƿ�Ϊ��
		{
			/*ͨ������ָ���������������ִ��*/
			task();
		}
	}
	__SOLA_LOG(debug, "thread_pool::threadLoop() tid : " + get_tid() + " exit.");
}

/*����ӿڣ��û�������������������Ľӿں���*/
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

/*ȡ������ĺ���*/
thread_pool::task_t thread_pool::take()
{
	std::unique_lock<std::mutex> lock(m_mutex);
	//always use a while-loop, due to spurious wakeup
	/*��Ҫ��wait����ѭ���У���Ϊ������ٻ��ѵ�����*/
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
