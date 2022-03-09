#pragma once
#include <string>
using namespace std;

//Drink类作为饮料类的纯抽象基类
class Drinks
{
public:
	Drinks();
	virtual ~Drinks();
	string description;
	virtual string  GetDescription();
	virtual float GetCost()=0;
	virtual bool SendMessage();
private: 
	
};

