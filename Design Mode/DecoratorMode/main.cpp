#include<iostream>
#include "Person.h"
#include"Decorator.h"
#include"ConcreteDecorator.h"
using namespace std;

int main() {
	cout << "��һ��װ��" << endl;
	/*����һ�������ָ��*/
	Person *person_A = new PersonA("Li");/*����personA�Ĺ��캯��*/


	/*����ConcreteDecoratorA�Ĺ��캯��*/
	Person *m_basicPerson = new ConcreteDecoratorA(person_A);//������Ҫע�⣺���ȵ���ConcreteDecoratorA���캯����Ȼ�����乹�캯������ʾ�Ķ�������丸��Ĺ��캯��

	m_basicPerson = new ConcreteDecoratorB(m_basicPerson);
	m_basicPerson = new ConcreteDecoratorC(m_basicPerson);
	/*�����show��Ҫ�����ǣ���ʹ�û���ָ����в��ָ���ʱ��
	�����յ���ĳ�������show��ʱ�򣬽�����в����ã�����Ϊʲô������ã���û��̫���ģ������ջ����ȵ���person��show
	�����ε��ø����㼶��show*/
	m_basicPerson->Show();

	cout << "�ڶ���װ��" << endl;
	Person *person_B= new PersonB("Zhao");
	m_basicPerson = new ConcreteDecoratorB(person_B);
	m_basicPerson = new ConcreteDecoratorC(m_basicPerson);
	m_basicPerson = new ConcreteDecoratorA(m_basicPerson);
	m_basicPerson->Show();


	getchar();
	return 0;
}