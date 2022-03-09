#pragma once
//#include "Drinks.h"
#include "Drinks.h"

//装饰类的抽象基类，继承最根本的基类
class Descriptions :public Drinks
{
public:
	Descriptions();
	Descriptions(Drinks *m_drink);
	~Descriptions();
	virtual string  GetDescription()=0;
	virtual bool SendMessage();
private:
	Drinks *Type1;
};

