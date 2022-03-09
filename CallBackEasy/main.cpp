#include <iostream>
using namespace std;

//定义函数指针，假设是系统的内部代码
int(*fp)(int, int);

//调用函数指针的函数,假设是系统内部源代码
int fun(int a, int b, int c) {
	//fp(a, b);
	return fp(a, b);
}

//假设g是程序员手动实现
int g(int a, int b) {
	return a + b;
}
//假设h是程序员手动实现
int h(int a, int b) {
	return a - b;
}

int main() {

	//只需要将函数指针p指向不同的函数，便能实现由系统回调不同的程序员实现的代码；
	fp = g;//必须指向之后使用
	cout << fun(5, 3, 1) << endl;
	fp = h;
	cout << fun(9, 7, 5)<< endl;
	getchar();
	return 0;
}