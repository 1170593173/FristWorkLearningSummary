#include "BeDescripDrinks.h"

BeDescripDrinksType1::BeDescripDrinksType1()
{
	description = "Type1";
	//cost = 1.5;
}
BeDescripDrinksType1::~BeDescripDrinksType1()
{
}
float BeDescripDrinksType1::GetCost() {
	return 3.00;
}




BeDescripDrinksType2::BeDescripDrinksType2()
{
	description = "Type2";
	//cost = 2.6;
}

BeDescripDrinksType2::~BeDescripDrinksType2()
{
}
float BeDescripDrinksType2::GetCost() {
	return 4.00;
}
