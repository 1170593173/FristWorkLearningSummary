#include <iostream>
#include <functional>
using namespace std;

/*����std::function����*/

/*1.������ͨ����*/
//int f(int a, int b)
//{
//	return a + b;
//}

/*2.���ú�������*/
//function object
//struct functor
//{
//public:
//	int operator() (int a, int b)
//	{
//		return a + b;
//	}
//};

/*4.����lambda���ʽ*/

/*5.�����ྲ̬��Ա����*/
//class Plus
//{
//public:
//	static int plus(int a, int b)
//	{
//		return a + b;
//	}
//};

/*6.�������Ա����*/
//class Plus
//{
//public:
//	int plus(int a, int b)
//	{
//		return a + b;
//	}
//};

/*7.�����๫�����ݳ�Ա*/
//class Plus
//{
//	
//public:
//	Plus(int num_) :num(num_) {}
//	int plus(int a, int b)
//	{
//		return a + b;
//	}
//	int  num;
//};
/*8.ͨ��bind�����������Ա����*/
class Plus
{
public:
	int plus(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	/*1.������ͨ����*/
	/*std::function<int(int, int)>func = f;
	cout << func(1, 2) << endl;      
	system("pause");
	return 0;*/

	/*2.���ú�������*/
	//functor ft;
	//function<int(int, int)> func = ft;
	//cout << func(1, 2) << endl;    //3
	//return 0;


	/*4.����lambda���ʽ*/
	//auto f = [](const int a, const int b) {return a + b; };
	//std::function<int(int, int)>func = f;
	//cout << func(1, 2) << endl;      // 3
	//system("pause");
	//return 0;

	/*5.�����ྲ̬��Ա����*/
	//function<int(int, int)> f = &Plus::plus;
	//cout << f(1, 2) << endl;     //3
	//system("pause");
	//return 0;


	/*6.�������Ա����*/
	//Plus p;
	//function<int(Plus&, int, int)> f = &Plus::plus;
	////function<int(const Plus,int, int)> f = &Plus::plus;
	//cout << f(p, 1, 2) << endl;     //3
	//system("pause");
	//return 0;

	/* 7.�����๫�����ݳ�Ա*/
	//Plus p(22);
	////Plus p(2);
	//function<int(const Plus&)> f = &Plus::num;
	////function<int(const Plus)> f = &Plus::num;
	//cout << f(p) << endl;     //2
	//system("pause");
	//return 0;


	/*8.ͨ��bind�����������Ա����*/
	Plus p;
	// ָ����ʽ���ó�Ա����
	function<int(int, int)> f = bind(&Plus::plus, &p, placeholders::_1, placeholders::_2);// placeholders::_1��ռλ��
	// ������ʽ���ó�Ա����
	function<int(int, int)> f1 = bind(&Plus::plus, p, placeholders::_1, placeholders::_2);// placeholders::_1��ռλ��
	cout << f(1, 2) << endl;     //3
	cout << f1(1, 2) << endl;     //3
	system("pause");
	return 0;
}

