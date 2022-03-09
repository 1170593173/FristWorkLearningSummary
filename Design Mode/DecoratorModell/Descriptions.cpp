#include "Descriptions.h"

Descriptions::Descriptions()
{
}

Descriptions::Descriptions(Drinks * m_drink)
{
	this->Type1 = m_drink;
}

Descriptions::~Descriptions()
{
}

bool Descriptions::SendMessage()
{
	return false;
}

