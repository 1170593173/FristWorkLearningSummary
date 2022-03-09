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
	/*����������¶���ʱ����ʼ��ָ�룬�������ü�������Ϊ1*/
	SmartPtr(Point *ptr) :rp(new U_Ptr(ptr)) { }

	/*��������Ϊ��һ������ĸ���ʱ�����ƹ��캯�����Ƹ���ָ�룬��������ָ����Ӧ�����ü�������1��*/
	//SmartPtr(const SmartPtr &sp) :rp(sp.rp) 
	SmartPtr(const SmartPtr &sp) 
	{ 
		rp = sp.rp;
		++rp->count; 
	}

	/*ʹ�ø�ֵ��������һ��������и�ֵʱ��������һ�㣺
	��ʹ���������ָ������ü�����1��Ϊ�μ�1����Ϊָ���Ѿ�ָ���ĵط����������1�����ü���Ϊ0�����ͷ�ָ����ָ�����ڴ档
	Ȼ�������Ҳ�������ָ��������ü�����Ϊ�����ӣ���Ϊ��ʱ��������ָ������Ҳ�����ָ����󣩡�*/
	SmartPtr& operator=(const SmartPtr& rhs) {
		++rhs.rp->count;
		if (--rp->count == 0)
			delete rp;
		rp = rhs.rp;
		return *this;
	}

	/*����������������������ʱ������������ʹ���ü�����1���������0��delete����*/
	~SmartPtr() {
		if (--rp->count == 0)
			delete rp;
		else
			std::cout << "����" << rp->count << "��ָ��ָ���������" << endl;
	}

private:
	U_Ptr *rp;
};
