#pragma once
#include "Decorator.h"

/*����װ����*/
class ConcreteDecoratorA:public Decorator
{
public:
	
	ConcreteDecoratorA(Person* person) :Decorator(person) {};//��ʽ��ָ�����ø�����Ǹ����캯�����������ڹ����������ʱ��ָ�����ȵ��õ����ǻ������һ�����캯����
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
