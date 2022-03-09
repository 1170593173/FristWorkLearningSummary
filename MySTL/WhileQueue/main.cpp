#include <iostream>
#include <share.h>
#include <memory>
#include <thread>
#include <string>
#include <windows.h>
#include <mutex>
#include <condition_variable>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int value) :val(value), next(nullptr) {};
};


class CircleQueue
{
public:
	CircleQueue();
	~CircleQueue();
	int insert = 0,read=0;
	bool InsertValue(int&val,string&detail){
		if (insert+1==read||(insert==99&&read==0))
		{
			detail = "the queue is full";
			return false;
		}
		m_queue[insert] = val;
		insert++;
		if (insert>=99)
		{
			insert = 0;
		}
		return true;
	};

	bool GetValue(int &getVal, string&detail) {
		if (read==insert)
		{
			detail = "the queue is empty";
			return false;
		}
		getVal = m_queue[read];
		read++;
		if (read>=99)
		{
			read = 0;
		}
		return true;
	}
	mutex m_lock;

private:
	int *m_queue;
	
};

CircleQueue::CircleQueue()
{
	m_queue = new int[100]{ 0 };
}

CircleQueue::~CircleQueue()
{
	delete[] m_queue;
}

CircleQueue m_Circle;

std::condition_variable cond;
void threadinsert(/*CircleQueue m_Circle*/) {
	string detial;
	for (int i = 0; i < 1000;++i)
	{
		//m_Circle.m_lock.lock();
		//while(!m_Circle.InsertValue(i, detial))
		//{
		//	Sleep(1000);
		//	cout << detial<<endl;
		//}
		//m_Circle.m_lock.unlock();
		unique_lock<mutex>locker(m_Circle.m_lock);
		while (!m_Circle.InsertValue(i, detial))
		{
			//如果插入失败表示的是队列已满
			cond.wait(locker);
			cout << detial << endl;
		}
		locker.unlock();
		//在插入之后，通知任意一个线程开启
		cond.notify_one();//目前存在一个疑问，这里的notify会不会唤醒上面的wait呢
		Sleep(10);

		//while (true)
		//{
		//	m_Circle.m_lock.lock();
		//	
		//	if (m_Circle.InsertValue(i, detial))
		//	{
		//		m_Circle.m_lock.unlock();
		//		break;
		//	}
		//	m_Circle.m_lock.unlock();
		//	cout << detial << endl;
		//	Sleep(100);
		//}
		//Sleep(10);
	}
}

void threadGet(/*CircleQueue m_Circle*/) {
	string detial;
	int data;
	for (int i = 0; i < 1000; ++i)
	{

		unique_lock<mutex>locker(m_Circle.m_lock);

		while (!m_Circle.GetValue(data, detial))
		{
			//当数组为空的时候，wait
			cond.wait(locker);
		}
		locker.unlock();
		cout << detial << "data:" << data << endl;
		//在插入之后，通知任意一个线程开启
		cond.notify_one();//目前存在一个疑问，这里的notify会不会唤醒上面的wait呢
		Sleep(1);





		//m_Circle.m_lock.lock();

		//while (!m_Circle.GetValue(data, detial))
		//{
		//	Sleep(10);
		//	cout << detial << endl;
		//}
		//cout << detial << "data:" << data << endl;
		//m_Circle.m_lock.unlock();
		//Sleep(10);
	}
}

int main() {

	/*有一定的bug，会出现insert==read==0的情况*/

	thread t1(threadinsert);
	thread t2(threadGet);
	t1.join();
	t2.join();
	getchar();
	return 0;
}