#include <iostream>
using namespace std;

//���庯��ָ�룬������ϵͳ���ڲ�����
int(*fp)(int, int);

//���ú���ָ��ĺ���,������ϵͳ�ڲ�Դ����
int fun(int a, int b, int c) {
	//fp(a, b);
	return fp(a, b);
}

//����g�ǳ���Ա�ֶ�ʵ��
int g(int a, int b) {
	return a + b;
}
//����h�ǳ���Ա�ֶ�ʵ��
int h(int a, int b) {
	return a - b;
}

int main() {

	//ֻ��Ҫ������ָ��pָ��ͬ�ĺ���������ʵ����ϵͳ�ص���ͬ�ĳ���Աʵ�ֵĴ��룻
	fp = g;//����ָ��֮��ʹ��
	cout << fun(5, 3, 1) << endl;
	fp = h;
	cout << fun(9, 7, 5)<< endl;
	getchar();
	return 0;
}