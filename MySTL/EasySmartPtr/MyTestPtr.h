#pragma once
#include<iostream>
using namespace std;

class MyTestPtr
{
public:
	MyTestPtr();
	~MyTestPtr();
};

class Point
{
public:
	Point(int xVal = 0, int yVal = 0) :x(xVal), y(yVal) { }
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int xVal) { x = xVal; }
	void setY(int yVal) { y = yVal; }

private:
	int x, y;

};

class U_Ptr
{
private:

	friend class SmartPtr;
	U_Ptr(Point *ptr) :p(ptr), count(1) { }
	~U_Ptr() { delete p; }

	int count;
	Point *p;
};

class SmartPtr
{
public:
	/*当创建类的新对象时，初始化指针，并将引用计数设置为1*/
	SmartPtr(Point *ptr) :rp(new U_Ptr(ptr)) { }

	/*当对象作为另一个对象的副本时，复制构造函数复制副本指针，并增加与指针相应的引用计数（加1）*/
	//SmartPtr(const SmartPtr &sp) :rp(sp.rp) 
	SmartPtr(const SmartPtr &sp) 
	{ 
		rp = sp.rp;
		++rp->count; 
	}

	/*使用赋值操作符对一个对象进行赋值时，处理复杂一点：
	先使左操作数的指针的引用计数减1（为何减1：因为指针已经指向别的地方），如果减1后引用计数为0，则释放指针所指对象内存。
	然后增加右操作数所指对象的引用计数（为何增加：因为此时做操作数指向对象即右操作数指向对象）。*/
	SmartPtr& operator=(const SmartPtr& rhs) {
		++rhs.rp->count;
		if (--rp->count == 0)
			delete rp;
		rp = rhs.rp;
		return *this;
	}

	/*析构函数：调用析构函数时，析构函数先使引用计数减1，如果减至0则delete对象。*/
	~SmartPtr() {
		if (--rp->count == 0)
			delete rp;
		else
			std::cout << "还有" << rp->count << "个指针指向基础对象" << endl;
	}

private:
	U_Ptr *rp;
};
