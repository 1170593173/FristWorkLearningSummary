#include <iostream>
#include<mutex>
#include<thread>
#include <condition_variable>
#include<deque>

using namespace std;

mutex m_mutex;
condition_variable g_cv;
//缓冲区
deque<int>m_deque;
const int MAX_NUM = 30;
int g_next_index = 0;

//生产者，消费者最大数量
const int producter_thread_num = 3;
const int consumer_thread_num = 3;

void product_thread(int thread_id) {
	while (true) {
		this_thread::sleep_for(chrono::milliseconds(500));
		unique_lock<mutex>lk(m_mutex);
		g_cv.wait(lk, [] {return m_deque.size() <= MAX_NUM; });
		g_next_index++;
		m_deque.push_back(g_next_index);
		cout << "product_thread:" << thread_id << "product data:" << g_next_index;
		cout << "queue size:" << m_deque.size() << endl;
		g_cv.notify_all();
	}
}

void consumer_thread(int thread_id) {
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(550));
		//加锁
		std::unique_lock <std::mutex> lk(m_mutex);
		//检测条件是否达成
		g_cv.wait(lk, [] { return !m_deque.empty(); });
		/*这里的操作类似于：
			while(m_deque.empty()){ //在队列为空的时候，就会进入循环，但是会被wait阻塞线程，假如被被虚假唤醒了，但是由于while的存在，会首先检查一遍队列，防止数据为空但是使用队列
				g_cv.wait(lk);
			}
		*/


		/*虚假唤醒：
		生产者线程不断生产数据并放入g_deque中，
		10个消费者线程不断从g_deque中获取数据并删除。
		没有数据的时候消费者线程调用wait函数阻塞当前线程，
		当生产者数据放入g_deque之后调用notify_all函数唤醒
		所有等待的线程。因为是10个消费者线程共同竞争数据，
		所以最终只有一个线程得到数据，另外9个线程被唤醒之
		后发现g_deque为空继续调用wait函数阻塞自己，这就导
		致了一个虚假唤醒的概念:明明当前线程已经被唤醒了，
		却得不到需要的数据。*/

		

		//互斥操作，消息数据
		int data = m_deque.front();
		m_deque.pop_front();
		std::cout << "\tconsumer_thread: " << thread_id << " consumer data: ";
		std::cout << data << " deque size: " << m_deque.size() << std::endl;
		//唤醒其他线程
		g_cv.notify_all();
		
	}
}

int main() {
	
	std::thread arrRroducerThread[producter_thread_num];
	std::thread arrConsumerThread[consumer_thread_num];

	for (int i = 0; i < producter_thread_num; i++)
	{
		arrRroducerThread[i] = std::thread(product_thread, i);
	}

	for (int i = 0; i < consumer_thread_num; i++)
	{
		arrConsumerThread[i] = std::thread(consumer_thread, i);
	}

	for (int i = 0; i < producter_thread_num; i++)
	{
		arrRroducerThread[i].join();
	}

	for (int i = 0; i < consumer_thread_num; i++)
	{
		arrConsumerThread[i].join();
	}

	return 0;
}