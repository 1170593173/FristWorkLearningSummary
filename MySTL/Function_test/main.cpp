#include <iostream>
#include <functional>
using namespace std;

/*测试std::function功能*/

/*1.调用普通函数*/
//int f(int a, int b)
//{
//	return a + b;
//}

/*2.调用函数对象*/
//function object
//struct functor
//{
//public:
//	int operator() (int a, int b)
//	{
//		return a + b;
//	}
//};

/*4.调用lambda表达式*/

/*5.调用类静态成员函数*/
//class Plus
//{
//public:
//	static int plus(int a, int b)
//	{
//		return a + b;
//	}
//};

/*6.调用类成员函数*/
//class Plus
//{
//public:
//	int plus(int a, int b)
//	{
//		return a + b;
//	}
//};

/*7.调用类公有数据成员*/
//class Plus
//{
//	
//public:
//	Plus(int num_) :num(num_) {}
//	int plus(int a, int b)
//	{
//		return a + b;
//	}
//	int  num;
//};
/*8.通过bind函数调用类成员函数*/
class Plus
{
public:
	int plus(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	/*1.调用普通函数*/
	/*std::function<int(int, int)>func = f;
	cout << func(1, 2) << endl;      
	system("pause");
	return 0;*/

	/*2.调用函数对象*/
	//functor ft;
	//function<int(int, int)> func = ft;
	//cout << func(1, 2) << endl;    //3
	//return 0;


	/*4.调用lambda表达式*/
	//auto f = [](const int a, const int b) {return a + b; };
	//std::function<int(int, int)>func = f;
	//cout << func(1, 2) << endl;      // 3
	//system("pause");
	//return 0;

	/*5.调用类静态成员函数*/
	//function<int(int, int)> f = &Plus::plus;
	//cout << f(1, 2) << endl;     //3
	//system("pause");
	//return 0;


	/*6.调用类成员函数*/
	//Plus p;
	//function<int(Plus&, int, int)> f = &Plus::plus;
	////function<int(const Plus,int, int)> f = &Plus::plus;
	//cout << f(p, 1, 2) << endl;     //3
	//system("pause");
	//return 0;

	/* 7.调用类公有数据成员*/
	//Plus p(22);
	////Plus p(2);
	//function<int(const Plus&)> f = &Plus::num;
	////function<int(const Plus)> f = &Plus::num;
	//cout << f(p) << endl;     //2
	//system("pause");
	//return 0;


	/*8.通过bind函数调用类成员函数*/
	Plus p;
	// 指针形式调用成员函数
	function<int(int, int)> f = bind(&Plus::plus, &p, placeholders::_1, placeholders::_2);// placeholders::_1是占位符
	// 对象形式调用成员函数
	function<int(int, int)> f1 = bind(&Plus::plus, p, placeholders::_1, placeholders::_2);// placeholders::_1是占位符
	cout << f(1, 2) << endl;     //3
	cout << f1(1, 2) << endl;     //3
	system("pause");
	return 0;
}

