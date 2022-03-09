#include <iostream>
#include <functional>
using namespace std;
//void print_num(int a) {
//	cout << a << endl;
//}
int main() 
{
	/*捕获外部变量*/
	int a = 123;
	auto f = [a] { cout << a << endl; };
	f(); // 输出：123
	//或通过“函数体”后面的‘()’传入参数
	[](int a) {cout << a << endl; }(123);

	/*1.值捕获*/
	a = 123;
	auto f1 = [a] { cout << a << endl; };
	a = 321;
	f1(); // 输出：123

	/*引用捕获*/
	a = 123;
	auto f2 = [&a] { cout << a << endl; };
	a = 321;
	f2(); // 输出：321

	/*隐式捕获*/

	/*隐式值捕获*/
	a = 123;
	auto f3 = [=] { cout << a << endl; };    // 值捕获
	a = 321;
	f3(); // 输出：123

	/*隐式引用捕获*/
	a = 123;
	auto f4 = [&] { cout << a << endl; };    // 引用捕获
	a = 321;
	f4(); // 输出：321

	getchar();


	/*反例
	不允许：
	1.参数列表中不能有默认参数
	2.不支持可变参数
	3.所有参数必须有参数名*/
	//int m = [](int x) { return [](int y) { return y * 2; }(x)+6; }(5);
	//std::cout << "m:" << m << std::endl;            　　//输出m:16

	//std::cout << "n:" << [](int x, int y) { return x + y; }(5, 4) <<endl;            //输出n:9

	//auto gFunc = [](int x) -> function<int(int)> { return [=](int y) { return x + y; }; };
	//auto lFunc = gFunc(4);
	//std::cout << lFunc(5) << std::endl;

	//auto hFunc = [](const function<int(int)>& f, int z) { return f(z) + 1; };
	//auto a = hFunc(gFunc(7), 8);

	//int a = 111, b = 222;
	//auto func = [=, &b]()mutable { a = 22; b = 333; std::cout << "a:" << a << " b:" << b << std::endl; };

	//func();
	//std::cout << "a:" << a << " b:" << b << std::endl;

	//a = 333;
	//auto func2 = [=, &a] { a = 444; std::cout << "a:" << a << " b:" << b << std::endl; };
	//func2();

	//auto func3 = [](int x) ->function<int(int)> { return [=](int y) { return x + y; }; };


	//std::function<void(int x)> f_display_42 = [](int x) { print_num(x); };
	//f_display_42(44);
}