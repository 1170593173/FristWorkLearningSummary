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


/*�̰߳�ȫ���ڴ氲ȫ������ʽ���� ������ָ�룬����*/
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
	MySingleTon_queue(MySingleTon_queue&) = delete;//��ֹ����������
	MySingleTon_queue& operator=(const MySingleTon_queue&) = delete;//��ֹ��=��������и�ֵ
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



	/*�Զ��еĲ�������*/
	bool add_event(const std::string &new_event, const std::string &queue_name, int priority = 0);
	std::string get_event(const std::string &queue_name);
	bool clear_event(const std::string &queue_name);
	bool is_empty(const std::string &queue_name);

	/*��������*/
	bool add_event(const std::string &new_event, const Queue_Element &m_queue,int priority=0);
	//bool priority_add_event(const std::string &new_event, const Queue_Element &m_queue);
	std::string get_event(const Queue_Element &m_queue);
	bool clear_event(const Queue_Element &m_queue);
	bool is_empty(const Queue_Element &m_queue);

	/*�Զ��������Ĳ�������*/
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
	static std::mutex m_mutex;//����������ʱ��ʹ��

	static std::mutex m_mutex_queue_vector;//�ڶԶ�����������дʱ����


	//static Queue_ElementPtr this_Queue_ElementPtr;//������Ψһ��ָ��
	//static mutex * this_queue_mutex;//��������Ψһ�ļ���

	//��ŵ�����ΪQueue_Element
	std::list<Queue_Element>Queue_List;
};

/*����ʽ����(magic static )�����ֲ���̬����*/
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