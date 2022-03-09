#pragma once
#include<iostream>
#include<memory>
#include<mutex>
#include<string>
#include<vector>
#include<queue>
#include<deque>


/*线程安全、内存安全的懒汉式单例 （智能指针，锁）*/
class MySingleTon_queue
{
public:
	typedef std::shared_ptr<MySingleTon_queue>Ptr;
	~MySingleTon_queue() {
		std::cout << "destructor called!" << std::endl;
	}
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

	void add_event(const std::string &new_event);
	std::string get_event();
	void clear_event();
	bool is_empty();

private:
	MySingleTon_queue(){
		std::cout << "constructor called!" << std::endl;
	}
	MySingleTon_queue(const int &queue_size){
		std::cout << "constructor called!" << std::endl;
	}

	std::deque<std::string>m_queue;
	/*std::vector<std::string>messege_queue;
	int _in, _out, messege_size;*/
	static Ptr m_instance_ptr;
	static std::mutex m_mutex;
	static std::mutex m_mutex_messege;
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