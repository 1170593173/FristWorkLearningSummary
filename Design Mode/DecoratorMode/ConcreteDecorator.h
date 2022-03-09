#pragma once
#include "Decorator.h"

/*具体装饰类*/
class ConcreteDecoratorA:public Decorator
{
public:
	
	ConcreteDecoratorA(Person* person) :Decorator(person) {};//显式的指定调用父类的那个构造函数（作用是在构造派生类的时候，指定首先调用的是那基类的那一个构造函数）
	~ConcreteDecoratorA();
	void Show();
private:
	void AddDecorate();
};
/*------------------------------------------------------------*/

class ConcreteDecoratorB :public Decorator
{
public:
	ConcreteDecoratorB(Person* person) :Decorator(person) {};
	~ConcreteDecoratorB();
	void Show();
private:
	void AddDecorate();
};

/*------------------------------------------------------------*/

class ConcreteDecoratorC :public Decorator
{
public:
	ConcreteDecoratorC(Person* person) :Decorator(person) {};
	~ConcreteDecoratorC();
	void Show();
private:
	void AddDecorate();
};
