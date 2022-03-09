#pragma once
#include "Descriptions.h"
#include <iostream>

//装饰类的具体实现类
class BeDescriptionType1:public Descriptions
{
public:
	BeDescriptionType1();
	BeDescriptionType1(Drinks *in_drink);
	~BeDescriptionType1();

	std::string GetDescription();
	float GetCost();
	bool SendMessage();
private:
	Drinks *m_drink;
};


class BeDescriptionType2 :public Descriptions
{
public:
	BeDescriptionType2();
	BeDescriptionType2(Drinks *in_drink);
	~BeDescriptionType2();

	string GetDescription();
	float GetCost();
	bool SendMessage();
private:
	Drinks *m_drink;
};

