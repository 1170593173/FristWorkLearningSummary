/*上下文+工厂类：根据不同的策略，工厂生产对应策略的对象*/
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

