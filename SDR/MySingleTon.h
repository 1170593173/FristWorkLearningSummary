#pragma once
#include<iostream>
#include<memory>
#include<mutex>
#include<string>
#include<vector>


/*�̰߳�ȫ���ڴ氲ȫ������ʽ���� ������ָ�룬����*/
class MySingleTon
{
public:
	typedef std::shared_ptr<MySingleTon>Ptr;
	~MySingleTon() {
		std::cout << "destructor called!" << std::endl;
	}
	MySingleTon(MySingleTon&) = delete;//��ֹ����������
	MySingleTon& operator=(const MySingleTon&) = delete;//��ֹ��=��������и�ֵ
	static Ptr get_instance() {
		// "double checked lock"
		if (m_instance_ptr == nullptr) {
			std::lock_guard<std::mutex> lk(m_mutex);
			if (m_instance_ptr == nullptr) {
				m_instance_ptr = std::shared_ptr<MySingleTon>(new MySingleTon);
			}
		}
		return m_instance_ptr;
	}

	void add_event(const std::string &new_event);
	std::string get_event();
	void clear_event();
	bool is_empty();

private:
	MySingleTon():_in(0), _out(0), messege_size(1000){
		messege_queue.resize(1000,"");
		std::cout << "constructor called!" << std::endl;
	}
	MySingleTon(const int &queue_size):_in(0), _out(0),messege_size(queue_size) {
		messege_queue.resize(queue_size, "");
		std::cout << "constructor called!" << std::endl;
	}


	std::vector<std::string>messege_queue;
	int _in, _out, messege_size;
	static Ptr m_instance_ptr;
	static std::mutex m_mutex;
	static std::mutex m_mutex_messege;
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