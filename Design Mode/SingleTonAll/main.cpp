#include <iostream>
#include <thread>
#include <shared_mutex>
#include <share.h>
using namespace std;

/*存在缺陷的懒汉单例模式：
1、线程不安全
2、存在内存泄漏的风险*/
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


/*解决上述缺陷的懒汉单例模式：
double check 的懒汉单例模式*/

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

/*最优雅的懒汉单例模式：
static 局部变量
"如果当变量在初始化的时候，并发同时进入声明语句，并发线程将会阻塞等待初 始化结束。"
magic static*/
class Singleton3 {
public:     
	~Singleton3() {
		std::cout << "destructor3 called!" << std::endl; 
	}    
	Singleton3(const Singleton3&) = delete;
	Singleton3& operator=(const Singleton3&) = delete;
	static Singleton3& gtetInstance() {//这里最好是用引用，不然会存在泄漏
		static Singleton3 instance;
		return instance;
	} 
private:     
	Singleton3()
	{ 
		std::cout << "constructor3 called!" << std::endl; 
	}
};

/*饿汉单例模式：本身就是线程安全的*/
/*
由于在main函数之前初始化，所以没有线程安全的问题。
但是潜在问题在于no-local static对象 （函数外的static对象）
在不同编译单元中的初始化顺序是未定义的。也即，
static Singleton instance;和static Singleton& getInstance()二者的初始化顺序不确定，
如果在初始化完成之前调 用 getInstance() 方法会返回一个未定义的实例。 
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



/*声明1*/
SingleTon1* SingleTon1::m_instance = NULL;

/*声明2*/
SingleTon2::Ptr SingleTon2::m_instance = NULL;
std::mutex SingleTon2::m_mutex;

/*声明3,
不需要声明！！！！*/

/*声明4*/
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