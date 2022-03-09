#include "ConcreteDecorator.h"

ConcreteDecoratorA::~ConcreteDecoratorA()
{
}
void ConcreteDecoratorA::Show() {
	Decorator::Show();
	AddDecorate();
}

void ConcreteDecoratorA::AddDecorate() {
	cout << "����" << endl;
}

/*------------------------------------------------------------*/

ConcreteDecoratorB::~ConcreteDecoratorB()
{
}
void ConcreteDecoratorB::Show() {
	Decorator::Show();
	AddDecorate();
}

void ConcreteDecoratorB::AddDecorate() {
	cout << "����" << endl;
}

/*------------------------------------------------------------*/
ConcreteDecoratorC::~ConcreteDecoratorC()
{
}
void ConcreteDecoratorC::Show() {
	Decorator::Show();
	AddDecorate();
}

void ConcreteDecoratorC::AddDecorate() {
	cout << "����" << endl;
}