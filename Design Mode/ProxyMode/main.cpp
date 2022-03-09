#include <iostream>
#include"ProxyPattern.h"
//int show(int number)
//{
//	std::cout << "Current Number is :" + number << std::endl;
//	return 1;
//}
//int main(...)
//{
//	int(*func)(int b);
//	func = show;
//	IMutiUser<int, decltype(func), IMutiImplement<int, decltype(func), void>>* temp = new IMutiProxy<int, decltype(func), IMutiImplement<int, decltype(func), void>>();
//	temp->T();
//	temp->GetReturnType();
//	system("pause");
//	return 0;
//}

int main() {
	ProxyPlayerVip0 pro5;
	pro5.Play1();
	pro5.Play2();
	pro5.Play3();

	ProxyPlayerVip1 pro1;
	pro1.Play1();
	pro1.Play2();
	pro1.Play3();
	system("pause");
	return 0;
}