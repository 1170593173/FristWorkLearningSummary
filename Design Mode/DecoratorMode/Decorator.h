#pragma once
#include "Person.h"

/*װ����*/
class Decorator:public Person
{
public:
	Decorator(Person* m_person);
	virtual ~Decorator();
	virtual void Show();
private:
	Person *m_person;
};

