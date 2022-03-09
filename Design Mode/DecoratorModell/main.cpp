#include <iostream>
using namespace std;
#include "BeDescripDrinks.h"
#include "BeDescription.h"



int main() {
	Drinks *m_drink1 = new BeDescripDrinksType1();
	cout << m_drink1->GetDescription() <<"  "<< m_drink1->GetCost()<<endl;


	//在实现的过程中，根据多态性，会层层调用上述基类，类似于递归
	Drinks *m_drink2 = new BeDescripDrinksType1();
	m_drink2 = new BeDescriptionType1(m_drink2);
	m_drink2=new BeDescriptionType2(m_drink2);
	cout << m_drink2->GetDescription() << "  " << m_drink2->GetCost() << m_drink2 ->SendMessage()<< endl;

	//这里的装饰模式可以用作流程的选定与控制，可以通过装饰配置具体的流程

	Drinks *m_drink3 = new BeDescripDrinksType2();
	m_drink3 = new BeDescriptionType1(m_drink3);
	m_drink3 = new BeDescriptionType2(m_drink3);
	cout << m_drink3->GetDescription() << "  " << m_drink3->GetCost() << m_drink3->SendMessage()<< endl;

	getchar();
	return 0;
}