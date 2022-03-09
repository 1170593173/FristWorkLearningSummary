#include <iostream>
#include<mutex>
#include<thread>
#include <condition_variable>
#include<deque>

using namespace std;

mutex m_mutex;
condition_variable g_cv;
//������
deque<int>m_deque;
const int MAX_NUM = 30;
int g_next_index = 0;

//�����ߣ��������������
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
		//����
		std::unique_lock <std::mutex> lk(m_mutex);
		//��������Ƿ���
		g_cv.wait(lk, [] { return !m_deque.empty(); });
		/*����Ĳ��������ڣ�
			while(m_deque.empty()){ //�ڶ���Ϊ�յ�ʱ�򣬾ͻ����ѭ�������ǻᱻwait�����̣߳����类����ٻ����ˣ���������while�Ĵ��ڣ������ȼ��һ����У���ֹ����Ϊ�յ���ʹ�ö���
				g_cv.wait(lk);
			}
		*/


		/*��ٻ��ѣ�
		�������̲߳����������ݲ�����g_deque�У�
		10���������̲߳��ϴ�g_deque�л�ȡ���ݲ�ɾ����
		û�����ݵ�ʱ���������̵߳���wait����������ǰ�̣߳�
		�����������ݷ���g_deque֮�����notify_all��������
		���еȴ����̡߳���Ϊ��10���������̹߳�ͬ�������ݣ�
		��������ֻ��һ���̵߳õ����ݣ�����9���̱߳�����֮
		����g_dequeΪ�ռ�������wait���������Լ�����͵�
		����һ����ٻ��ѵĸ���:������ǰ�߳��Ѿ��������ˣ�
		ȴ�ò�����Ҫ�����ݡ�*/

		

		//�����������Ϣ����
		int data = m_deque.front();
		m_deque.pop_front();
		std::cout << "\tconsumer_thread: " << thread_id << " consumer data: ";
		std::cout << data << " deque size: " << m_deque.size() << std::endl;
		//���������߳�
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