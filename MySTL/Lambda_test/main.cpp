#include <iostream>
#include <functional>
using namespace std;
//void print_num(int a) {
//	cout << a << endl;
//}
int main() 
{
	/*�����ⲿ����*/
	int a = 123;
	auto f = [a] { cout << a << endl; };
	f(); // �����123
	//��ͨ���������塱����ġ�()���������
	[](int a) {cout << a << endl; }(123);

	/*1.ֵ����*/
	a = 123;
	auto f1 = [a] { cout << a << endl; };
	a = 321;
	f1(); // �����123

	/*���ò���*/
	a = 123;
	auto f2 = [&a] { cout << a << endl; };
	a = 321;
	f2(); // �����321

	/*��ʽ����*/

	/*��ʽֵ����*/
	a = 123;
	auto f3 = [=] { cout << a << endl; };    // ֵ����
	a = 321;
	f3(); // �����123

	/*��ʽ���ò���*/
	a = 123;
	auto f4 = [&] { cout << a << endl; };    // ���ò���
	a = 321;
	f4(); // �����321

	getchar();


	/*����
	������
	1.�����б��в�����Ĭ�ϲ���
	2.��֧�ֿɱ����
	3.���в��������в�����*/
	//int m = [](int x) { return [](int y) { return y * 2; }(x)+6; }(5);
	//std::cout << "m:" << m << std::endl;            ����//���m:16

	//std::cout << "n:" << [](int x, int y) { return x + y; }(5, 4) <<endl;            //���n:9

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