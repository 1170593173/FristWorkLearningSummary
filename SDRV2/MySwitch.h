/*������֧�����ࣺ�Բ�ͬ������£����ֲ��Եķ�װ��*/
#pragma once
#include<iostream>
using namespace std;

class MySwitch
{
public:
	MySwitch();
	virtual ~MySwitch();
	virtual void algorithmInterface() = 0;
};

/*-------------------------------------------------*/
class Init:public MySwitch
{
public:
	Init();
	~Init();
	void algorithmInterface();
private:

};

/*-------------------------------------------------*/
class Load_Config :public MySwitch
{
public:
	Load_Config();
	~Load_Config();
	void algorithmInterface();
private:
};

/*-------------------------------------------------*/
class No_Action :public MySwitch
{
public:
	No_Action();
	~No_Action();
	void algorithmInterface();
private:
};