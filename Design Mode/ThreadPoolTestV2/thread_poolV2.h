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
	typedef std::function<void()>Task;//不存在优先级
	typedef std::pair<taskPriorityE, Task> TaskPair;//存在优先级
	ThreadPool();
	~ThreadPool();
	void start();   
	void stop();   
	void addTask(const Task&);   
	void addTask(const TaskPair&);
private:
	ThreadPool(const ThreadPool&);//禁止复制拷贝. 
	//const ThreadPool& operator=(const ThreadPool&);
	struct TaskPriorityCmp {
		bool operator()(const ThreadPool::TaskPair p1, const ThreadPool::TaskPair p2) {
			return p1.first > p2.first; //first的小值优先     
		}   
	};

	void threadLoop();   
	Task take();
	typedef std::vector<std::thread*> Threads;   

	//优先队列的关键所在，排队的优先级在于priority_queue，会按照cmp自动进行排序
	typedef std::priority_queue<TaskPair, std::vector<TaskPair>, TaskPriorityCmp> Tasks;

	Threads m_threads;   
	Tasks m_tasks;
	std::mutex m_mutex;   
	std::condition_variable m_cond;
	bool m_isStarted;
};
