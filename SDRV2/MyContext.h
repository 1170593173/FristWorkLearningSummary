/*������+�����ࣺ���ݲ�ͬ�Ĳ��ԣ�����������Ӧ���ԵĶ���*/
#pragma once
#include "MySwitch.h"
//#include <shared_mutex>
class MyContext
{
public:
	MyContext(string type);
	MyContext(MySwitch*m_switch);
	~MyContext();
	void DO_GetResult();
private:
	MySwitch*m_switch;
	//MySwitch *m_switch;
};

