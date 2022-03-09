#include"FactoryMethod.h"

int main() {
	IFactory* factroy = new UndergraduateFactory();
	baseClass *Person= factroy->createInstence();
	
	Person->BuyRice();
	Person->Sweep();
	Person->Wash();



	/*一下是关于C++多态的一些思考，与工厂方法模式无关*/
	/*
	这里提出一个思考：
	baseClass作为基类，Undergraduate做为继承基类的的子类，
	其中需要被继承的函数（方法）都被声明为了虚函数，
	但是 我在子类中新定义的函数，采用基类的指针是不能使用子类的基类没有的方法的；
	这里的逻辑不理解

	baseClass *Person = new Undergraduate();
	Person->Test();*/

	/*子类调用父类方法*/
	Undergraduate*UnPerson = new Undergraduate();
	UnPerson->baseClass::BuyRice();
	UnPerson->BuyRice();
	//Person->Test();
	system("pause");
	return 0;
}