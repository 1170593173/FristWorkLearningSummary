#include "BeDescription.h"

BeDescriptionType1::BeDescriptionType1()
{
}

BeDescriptionType1::BeDescriptionType1(Drinks * in_drink)
{
	this->m_drink = in_drink;
}

BeDescriptionType1::~BeDescriptionType1()
{
	delete m_drink;
}

string BeDescriptionType1::GetDescription()
{
	return m_drink->GetDescription() + ",Mocha";
	//return string();
}

float BeDescriptionType1::GetCost()
{
	return 0.2 + m_drink->GetCost();
	//return 0.0f;
}

bool BeDescriptionType1::SendMessage()
{
	if (!m_drink->SendMessage()) {
		cout << "SendMessage frist V1" << endl;
		return false;
	}
	return false;
}




BeDescriptionType2::BeDescriptionType2()
{
}

BeDescriptionType2::BeDescriptionType2(Drinks * in_drink)
{
	this->m_drink = in_drink;
}

BeDescriptionType2::~BeDescriptionType2()
{
	delete m_drink;
}

string BeDescriptionType2::GetDescription()
{
	return m_drink->GetDescription() + ",Soy";
}

float BeDescriptionType2::GetCost()
{
	return 0.6 + m_drink->GetCost();
}

bool BeDescriptionType2::SendMessage()
{
	if (!m_drink->SendMessage()) {
		cout << "SendMessage second V1" << endl;
		return false;
	}
	return false;
	//return false;
}
