#include "ConcreteDecorator.h"

ConcreteDecoratorA::~ConcreteDecoratorA()
{
}
void ConcreteDecoratorA::Show() {
	Decorator::Show();
	AddDecorate();
}

void ConcreteDecoratorA::AddDecorate() {
	cout << "¿ã×Ó" << endl;
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
	cout << "³ÄÉÀ" << endl;
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
	cout << "ÍâÌ×" << endl;
}