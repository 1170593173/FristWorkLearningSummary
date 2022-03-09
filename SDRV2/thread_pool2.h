#pragma once 
#include <functional> 
#include <future> 
#include <mutex> 
#include <queue> 
#include <thread> 
#include <utility> 
#include <vector> 
#include "SafeQueue.h" //�������
class ThreadPool {
private:
	class ThreadWorker {//�����̹߳�����
	private:
		int m_id; //����id
		ThreadPool * m_pool;//�����̳߳�
	public:
		//���캯��
		ThreadWorker(ThreadPool * pool, const int id)
			: m_pool(pool), m_id(id) 
		{
		}
		//����`()`����

		void operator()() {
			std::function<void()> func; //�������������func
			bool dequeued; //�Ƿ�����ȡ��������Ԫ��
						   //�ж��̳߳��Ƿ�رգ�û�йرգ�ѭ����ȡ
			while (!m_pool->m_shutdown) {
				{
					//Ϊ�̻߳����������������ʹ����̵߳����ߺͻ���
					std::unique_lock<std::mutex> lock(m_pool->m_conditional_mutex);
					//����������Ϊ�գ�������ǰ�߳�
					if (m_pool->m_queue.empty()) {
						m_pool->m_conditional_lock.wait(lock); //�ȴ���������֪ͨ�������߳�
					}
					//ȡ����������е�Ԫ��
					dequeued = m_pool->m_queue.dequeue(func);
				}
				//����ɹ�ȡ����ִ�й�������
				if (dequeued) {
					func();
				}
			}
		}
	};

	bool m_shutdown; //�̳߳��Ƿ�ر�
	SafeQueue<std::function<void()>> m_queue;//ִ�к�����ȫ���У����������
	std::vector<std::thread> m_threads; //�����̶߳���
	std::mutex m_conditional_mutex;//�߳��������������
	std::condition_variable m_conditional_lock; //�̻߳����������߳̿��Դ������߻��߻���״̬

public:
	//�̳߳ع��캯��
	ThreadPool(const int n_threads)
		: m_threads(std::vector<std::thread>(n_threads)), m_shutdown(false) {
	}
	ThreadPool(const ThreadPool &) = delete; //�������캯��������ȡ��Ĭ�ϸ��๹�캯��

	ThreadPool(ThreadPool &&) = delete; // �������캯����������ֵ����

	ThreadPool & operator=(const ThreadPool &) = delete; // ��ֵ����

	ThreadPool & operator=(ThreadPool &&) = delete; //��ֵ����

													// Inits thread pool

	void init() {
		for (int i = 0; i < m_threads.size(); ++i) {
			m_threads[i] = std::thread(ThreadWorker(this, i));//���乤���߳�

		}
	}

	// Waits until threads finish their current task and shutdowns the pool
	void shutdown() {
		m_shutdown = true;
		m_conditional_lock.notify_all(); //֪ͨ �������й����߳�

		for (int i = 0; i < m_threads.size(); ++i) {
			if (m_threads[i].joinable()) { //�ж��߳��Ƿ����ڵȴ�
				m_threads[i].join();  //���̼߳���ȴ�����
			}
		}
	}

	// Submit a function to be executed asynchronously by the pool
	//�̵߳���Ҫ����������ʹ���˺��÷������ͣ��Զ��жϺ�������ֵ

/*
�������ͺ��ã�
���˹��캯���������������⣬������������Ҫ��ȷ�����ķ������ͣ��ڴ�ͳ��C����C++�У���������������������ӣ�
int getSum(int a, int b);
��һ��int���Ǻ����ķ������ͣ������������ķ���ֵ����Ϊ���������µ�C++11�Ժ�����Ҳ��������������
auto getSum(int a, int b)->int;
��ԭ���ŷ���ֵ���͵�λ��дauto���ں������������Ժ��һ��'->'�ٸ���д�����ķ���ֵ���͡����ַ�ʽ��Ч����һ���ġ�
*/


	//ģ�壺�����������������ص�����F���Լ���������Args
	template<typename F, typename...Args>
	auto submit(F&& f, Args&&... args) -> future<decltype(f(args...))> {//����1��2
		// Create a function with bounded parameters ready to execute
		// 
		//����3
		std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);//���Ӻ����Ͳ������壬���⺯������,��������ֵ����

																												// Encapsulate it into a shared ptr in order to be able to copy construct // assign 
																												//��װ��ȡ������󣬷�������һ���̲߳鿴���
		
		//std::packaged_task ��װһ���ɵ��õĶ��󣬲��������첽��ȡ�ÿɵ��ö�������Ľ��
		//std::make_shared ��������ָ��shared_ptr,ָ��󶨵�package_task��package_task�����첽��ȡ���
		func();
		//����4
		auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);

		// Wrap packaged task into void function
		//����lambda���ʽ������һ����������

		//����5
		std::function<void()> wrapper_func = [task_ptr]() {
			(*task_ptr)();
		};

		// ����ͨ�ð�ȫ�����������ѹ�밲ȫ����
		//����6
		m_queue.enqueue(wrapper_func);

		// ����һ���ȴ��е��߳�
		//����6
		m_conditional_lock.notify_one();

		// ������ǰע�������ָ��
		//����7
		return task_ptr->get_future();
	}


	/*submit�ܽ᣺
	Ϊ��ʵ�ֿ����������������������������ⷵ��ֵ�ĺ���������������������
	����1��ʹ������Ӧ�ķ������ͺ��ã���ģ�廯����ֵ��ʵ�����䲻ͬ�������͵ĺ���������������������ȡreturnֵ(���ﻹ���ڴ����������)
	����2������ʹ���˿ɱ�ģ����������������˶�Ӧ�ķ���ֵ����ģ���Լ��������ģ�壬���еĺ������ģ����õ��ǿɱ�ģ��
	����3��ʹ��bind��������f�����args���а󶨣�����function��װ����ָ�룬
	����4��Ϊ�˽���տ�ʼ�Ļ�ȡ�������ķ���ֵ�����⣬ʹ��futrueͷ�ļ��е�packaged_task����һ��function��װ�õĺ���ָ����а�װ���Ա㹲��״̬(shared state)�����ڱ�������ķ���ֵ����������ָ��ָ��packaged_task
	
	����5������ͳһ��������function<void()>����ָ���packaged_task���а�װ���ڰ�װ�У�ʹ��lambda���ʽ������ָ��ָ��ĺ������е��ã���ˣ���װ�õ�ָ����ܵ�����Ӧ�ĺ����ˣ�
	����6������Ӧ��function<void()>����ָ��������������
	����7��ͨ��get_future����� packaged_task ����״̬������� future ���󣬹��ⲿʹ�ã�
	*/
};