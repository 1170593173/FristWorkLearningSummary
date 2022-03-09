#pragma once

#include <vector> 
#include <utility>
#include <queue> 
#include <thread> 
#include <functional> 
#include <mutex>
#include <condition_variable>

class ThreadPool
{
public:
	static const int kInitThreadsSize = 3;
	enum taskPriorityE{level0, level1,level2};
	typedef std::function<void()>Task;//���������ȼ�
	typedef std::pair<taskPriorityE, Task> TaskPair;//�������ȼ�
	ThreadPool();
	~ThreadPool();
	void start();   
	void stop();   
	void addTask(const Task&);   
	void addTask(const TaskPair&);
private:
	ThreadPool(const ThreadPool&);//��ֹ���ƿ���. 
	//const ThreadPool& operator=(const ThreadPool&);
	struct TaskPriorityCmp {
		bool operator()(const ThreadPool::TaskPair p1, const ThreadPool::TaskPair p2) {
			return p1.first > p2.first; //first��Сֵ����     
		}   
	};

	void threadLoop();   
	Task take();
	typedef std::vector<std::thread*> Threads;   

	//���ȶ��еĹؼ����ڣ��Ŷӵ����ȼ�����priority_queue���ᰴ��cmp�Զ���������
	typedef std::priority_queue<TaskPair, std::vector<TaskPair>, TaskPriorityCmp> Tasks;

	Threads m_threads;   
	Tasks m_tasks;
	std::mutex m_mutex;   
	std::condition_variable m_cond;
	bool m_isStarted;
};
