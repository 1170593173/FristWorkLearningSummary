#include <iostream>
#include "MyTestPtr.h"
using namespace  std;

/*
智能指针中的引用计数在不断拷贝和构造的过程中，如何保持一致的？https://www.cnblogs.com/QG-whz/p/4777312.html
回答上述问题：为了实现智能指针对普通指针的管理，需要使用引用计数来对持有该普通指针的对象进行计数，那么最直观的管理方式肯定是需要在智能指针类中
实现自定义构造函数、拷贝构造函数、赋值构造函数、析构函数等，在构造函数中对引用计数进行初始化为1，在拷贝构造函数、赋值构造函数中对引用计数进行拷贝
但是，需要注意一点的是，如果在拷贝与赋值运算符重载函数中，对引用计数进行简单的值传递（深拷贝）是没有意义的，需要使用浅拷贝对引用计数进行转移或者说赋值
(其实，这里不光是引用计数的维护，智能指针所维护的普通指针也要这样做)
相应的参考文档是：https://blog.csdn.net/qq_40995354/article/details/81225283
*/

int main() {
	//定义一个基础对象类指针
	Point *pa = new Point(10, 20);
	Point *pb = new Point(11, 22);

	//定义三个智能指针类对象，对象都指向基础类对象pa
	//使用花括号控制三个指针指针的生命期，观察计数的变化

	{
		SmartPtr sptr1(pa);//此时计数count=1
		//SmartPtr sptrtest(pa);
		SmartPtr sptrll(pb);//此时就是在采用赋值操作符对一个对象进行赋值，首先检查指向Pa的count的数量，如果为1了，就析构
		//sptrll.rp->count;
		sptr1 = sptrll;
		{
			SmartPtr sptr2(sptr1); //调用复制构造函数，此时计数为count=2
			{
				SmartPtr sptr3 = sptr1; //调用赋值操作符，此时计数为conut=3
			}
			//此时count=2
		}
		//此时count=1；
	}
	//此时count=0；pa对象被delete掉

	cout << pa->getX() << endl;

	system("pause");
	return 0;
}