#include <iostream>
#include <thread>
#include <shared_mutex>
#include <share.h>
using namespace std;

/*����ȱ�ݵ���������ģʽ��
1���̲߳���ȫ
2�������ڴ�й©�ķ���*/
class SingleTon1
{
public:
	~SingleTon1() {
		cout << "destructor1 called!" << endl;
	}
	static SingleTon1*gtetInstance() {
		if (m_instance == NULL)
		{
			m_instance = new SingleTon1();
		}
		return m_instance;
	}
private:
	SingleTon1() {
		cout << "constructor1 called!" << endl;
	}
	SingleTon1(SingleTon1&) = delete;
	SingleTon1& operator=(const SingleTon1&) = delete;
	static SingleTon1* m_instance;
};


/*�������ȱ�ݵ���������ģʽ��
double check ����������ģʽ*/

class SingleTon2
{
public:
	typedef std::shared_ptr<SingleTon2> Ptr;

	~SingleTon2() {
		cout << "destructor2 called!" << endl;
	}
	static Ptr gtetInstance() {
		if (m_instance == NULL)
		{
			std::lock_guard<mutex>lk(m_mutex);
			if (m_instance == NULL) {
				m_instance = Ptr(new SingleTon2());
			}
			
		}
		return m_instance;
	}
private:
	SingleTon2() {
		cout << "constructor2 called!" << endl;
	}
	SingleTon2(SingleTon2&) = delete;
	SingleTon2& operator=(const SingleTon2&) = delete;
	static Ptr m_instance;
	static mutex m_mutex;
};

/*�����ŵ���������ģʽ��
static �ֲ�����
"����������ڳ�ʼ����ʱ�򣬲���ͬʱ����������䣬�����߳̽��������ȴ��� ʼ��������"
magic static*/
class Singleton3 {
public:     
	~Singleton3() {
		std::cout << "destructor3 called!" << std::endl; 
	}    
	Singleton3(const Singleton3&) = delete;
	Singleton3& operator=(const Singleton3&) = delete;
	static Singleton3& gtetInstance() {//��������������ã���Ȼ�����й©
		static Singleton3 instance;
		return instance;
	} 
private:     
	Singleton3()
	{ 
		std::cout << "constructor3 called!" << std::endl; 
	}
};

/*��������ģʽ����������̰߳�ȫ��*/
/*
������main����֮ǰ��ʼ��������û���̰߳�ȫ�����⡣
����Ǳ����������no-local static���� ���������static����
�ڲ�ͬ���뵥Ԫ�еĳ�ʼ��˳����δ����ġ�Ҳ����
static Singleton instance;��static Singleton& getInstance()���ߵĳ�ʼ��˳��ȷ����
����ڳ�ʼ�����֮ǰ�� �� getInstance() �����᷵��һ��δ�����ʵ���� 
*/
class Singleton4 { 
private:  
	static Singleton4 instance;
	~Singleton4() {
		std::cout << "destructor4 called!" << std::endl;
	}
	Singleton4(){
		std::cout << "constructor4 called!" << std::endl;
	}

	Singleton4(const Singleton4&)=delete;
	Singleton4& operator=(const Singleton4&)=delete;
public:  
	static Singleton4& getInstance()
	{ 
		return instance; 
	} 
};



/*����1*/
SingleTon1* SingleTon1::m_instance = NULL;

/*����2*/
SingleTon2::Ptr SingleTon2::m_instance = NULL;
std::mutex SingleTon2::m_mutex;

/*����3,
����Ҫ������������*/

/*����4*/
Singleton4 Singleton4::instance;

int main() {
	SingleTon1* instance1 = SingleTon1::gtetInstance();
	SingleTon1* instance1_2 = SingleTon1::gtetInstance();

	
	SingleTon2::Ptr instance2 = SingleTon2::gtetInstance();
	SingleTon2::Ptr instance2_2 = SingleTon2::gtetInstance();

	Singleton3 &instance3 = Singleton3::gtetInstance();
	Singleton3 & instance3_2 = Singleton3::gtetInstance();

	Singleton4 &instance4 = Singleton4::getInstance();
	Singleton4 & instance4_2 = Singleton4::getInstance();

	return 0;
}