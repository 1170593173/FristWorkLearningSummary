#include<iostream>
#include "Person.h"
#include"Decorator.h"
#include"ConcreteDecorator.h"
using namespace std;

int main() {
	cout << "第一套装饰" << endl;
	/*定义一个基类的指针*/
	Person *person_A = new PersonA("Li");/*调用personA的构造函数*/


	/*调用ConcreteDecoratorA的构造函数*/
	Person *m_basicPerson = new ConcreteDecoratorA(person_A);//这里需要注意：首先调用ConcreteDecoratorA构造函数，然后在其构造函数中显示的定义调用其父类的构造函数

	m_basicPerson = new ConcreteDecoratorB(m_basicPerson);
	m_basicPerson = new ConcreteDecoratorC(m_basicPerson);
	/*这里的show需要做的是：在使用基类指针进行层层指向的时候，
	在最终调用某个子类的show的时候，将会进行层层调用（这里为什么会层层调用，是没有太懂的），最终会首先调用person的show
	再依次调用各个层级的show*/
	m_basicPerson->Show();

	cout << "第二套装饰" << endl;
	Person *person_B= new PersonB("Zhao");
	m_basicPerson = new ConcreteDecoratorB(person_B);
	m_basicPerson = new ConcreteDecoratorC(m_basicPerson);
	m_basicPerson = new ConcreteDecoratorA(m_basicPerson);
	m_basicPerson->Show();


	getchar();
	return 0;
}