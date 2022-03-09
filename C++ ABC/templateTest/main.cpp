#include<iostream>
#include"point.h"
#include <functional> 
#include <future> 
#include <mutex> 
#include <queue> 
#include <thread> 
#include <utility> 
#include <vector> 
#include <iostream>
using namespace std;

template<typename T> void Swap(T *a, T *b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

/*类的模板的使用：
最大的注意点：一定要注意在.h与.cpp必须在同一个文件中*/



/***********************************函数模板参数实验*******************************************/
template <class... T>
void f(T... args) {
	cout << sizeof...(args) << endl;
}

std::function<void()>m_fun;

/*可变参数模板*/
template<typename F, typename...Args>
//函数后置返回，返回 futrue<待定> 类型
auto submit(F&& f, Args&&... args) -> future<decltype(f(args...))> {

	//连接函数和参数定义，特殊函数类型,避免左、右值错误
	std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);

	//使用packaged_task生成future，用于异步动作同步，然后用智能指针指向futrue
	auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);

	// Wrap packaged task into void function
	//利用lambda表达式，返回一个函数对象
	std::function<void()> wrapper_func = [task_ptr]() {
		(*task_ptr)();
	};
	//设置函数指针，用于外部调用
	m_fun = wrapper_func;
	//返回futrue<待定>
	return task_ptr->get_future();
}

/*测试用例：正常变换入参与return*/
int test(int a, int b) {
	std::cout << "test" << endl;
	return 1;
}

/*测试用例：正常变换入参与return*/
string test1(int a, string s) {
	std::cout << a << "+" << s.c_str() << endl;
	return s;
}

/*测试用例：引用入参与voidreturn*/
void test2(int &a, int b) {
	a = b;
}

int main() {
	/*********************************可变参数模板的使用***************************************
	这些操作的目的在于，将不同的函数，归一到同一类型的函数指针，以备后续调用，同时使用futrue获取执行后的return值，目前主要用于线程池的任务容器来添加任务
	*/
	f();        //0
	f(1, 2);    //2
	f(1, 2.5, "");    //3

	auto future1 = submit(test, 1, 2);
	m_fun();
	auto ssss = future1.get();

	auto future2 = submit(test1, 520, "111");
	m_fun();
	auto ssss2 = future2.get();

	int a;
	auto future3 = submit(test2, std::ref(a), 123);
	m_fun();
	future3.get();

	/*可变参数模板的实际参数展开*/
	/*****************/



	/*********************************函数模板的使用****************************************/
	//交换 int 变量的值
	int n1 = 100, n2 = 200;
	Swap(&n1, &n2);
	cout << n1 << ", " << n2 << endl;

	//交换 float 变量的值
	float f1 = 12.5, f2 = 56.93;
	Swap(&f1, &f2);
	cout << f1 << ", " << f2 << endl;

	//交换 char 变量的值
	char c1 = 'A', c2 = 'B';
	Swap(&c1, &c2);
	cout << c1 << ", " << c2 << endl;

	//交换 bool 变量的值
	bool b1 = false, b2 = true;
	Swap(&b1, &b2);
	cout << b1 << ", " << b2 << endl;

	/**************************************类模板的使用**************************************/

	char *temp = new char[100];
	temp = "yyy";

	Point<int, int> p1(10, 20);
	//auto i = p1.getX();
	cout << "x=" << p1.getX() << ", y=" << p1.getY() << endl;
	Point<int, char*> p2(10, temp);
	cout << "x=" << p2.getX() << ", y=" << p2.getY() << endl;
	Point<char*, char*> *p3 = new Point<char*, char*>(temp, temp);
	cout << "x=" << p3->getX() << ", y=" << p3->getY() << endl;
	return 0;
}