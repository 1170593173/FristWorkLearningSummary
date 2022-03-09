#pragma once
#include "Drinks.h"

//需要具体被装饰的类
class BeDescripDrinksType1:public Drinks
{
public:
	BeDescripDrinksType1();
	~BeDescripDrinksType1();

	float GetCost();

};


class BeDescripDrinksType2 :public Drinks
{
public:
	BeDescripDrinksType2();
	~BeDescripDrinksType2();
	
	float GetCost();
};

