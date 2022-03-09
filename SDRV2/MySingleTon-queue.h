#pragma once
#include<iostream>
#include<memory>
#include<mutex>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<list>
using namespace std;


/*线程安全、内存安全的懒汉式单例 （智能指针，锁）*/
class MySingleTon_queue
{
public:

	typedef std::shared_ptr<MySingleTon_queue>Ptr;
	typedef std::deque<std::string>* Queue_ElementPtr;

	struct Queue_Element
	{
		string queue_name;
		MySingleTon_queue::Queue_ElementPtr m_Queue_ElementPtr;
		mutex *m_queue_mutex;
	};
	~MySingleTon_queue();
	MySingleTon_queue(MySingleTon_queue&) = delete;//禁止掉拷贝函数
	MySingleTon_queue& operator=(const MySingleTon_queue&) = delete;//禁止掉=运算符进行赋值
	static Ptr get_instance() {
		// "double checked lock"
		if (m_instance_ptr == nullptr) {
			std::lock_guard<std::mutex> lk(m_mutex);
			if (m_instance_ptr == nullptr) {
				m_instance_ptr = std::shared_ptr<MySingleTon_queue>(new MySingleTon_queue);
			}
		}
		return m_instance_ptr;
	}



	/*对队列的操作函数*/
	bool add_event(const std::string &new_event, const std::string &queue_name, int priority = 0);
	std::string get_event(const std::string &queue_name);
	bool clear_event(const std::string &queue_name);
	bool is_empty(const std::string &queue_name);

	/*函数重载*/
	bool add_event(const std::string &new_event, const Queue_Element &m_queue,int priority=0);
	//bool priority_add_event(const std::string &new_event, const Queue_Element &m_queue);
	std::string get_event(const Queue_Element &m_queue);
	bool clear_event(const Queue_Element &m_queue);
	bool is_empty(const Queue_Element &m_queue);

	/*对队列容器的操作函数*/
	MySingleTon_queue::Queue_Element create_queue(const std::string &queue_name);
	bool delete_queue(const std::string &queue_name);
	Queue_Element get_queue(const std::string &queue_name);

	
	//Queue_Element get_queue(const Queue_Element &m_queue);

private:
	MySingleTon_queue() {
		std::cout << "constructor called!" << std::endl;
	}
	//MySingleTon_queue(const int &queue_size) {
	//	std::cout << "constructor called!" << std::endl;
	//}

	//std::deque<std::string>m_queue;
	static Ptr m_instance_ptr;
	static std::mutex m_mutex;//单例创建的时候使用

	static std::mutex m_mutex_queue_vector;//在对队列容器进行写时加锁


	//static Queue_ElementPtr this_Queue_ElementPtr;//单例中唯一的指针
	//static mutex * this_queue_mutex;//但单例中唯一的加锁

	//存放的内容为Queue_Element
	std::list<Queue_Element>Queue_List;
};

/*懒汉式单例(magic static )——局部静态变量*/
//class MySingleTon
//{
//public:
//	~MySingleTon() {
//		std::cout << "destructor called!" << std::endl;
//	}
//	MySingleTon(const MySingleTon&) = delete;
//	MySingleTon& operator=(const MySingleTon&) = delete;
//	static MySingleTon& get_instance() {
//		static MySingleTon instance;
//		return instance;
//	}
//private:
//	MySingleTon() {
//		std::cout << "constructor called!" << std::endl;
//	}
//};