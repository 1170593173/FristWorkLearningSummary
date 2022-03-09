#include "Decorator.h"

Decorator::Decorator(Person*person)
{
	m_person = person;
}

Decorator::~Decorator()
{
	delete m_person;
}

void Decorator::Show() {
	m_person->Show();
}