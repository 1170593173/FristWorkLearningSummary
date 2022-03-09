#pragma once
#include <iostream>
#include <string >
using namespace std;

/*��װ��Ļ���*/
class Person
{
public:
	Person();
	virtual ~Person();
	//Person(string name);
	virtual void Show()=0;
private:
	string name;

};

class PersonA:public Person
{
public:
	PersonA(string name) :m_name(name) {};
	virtual ~PersonA();
	void Show() {
		cout << m_name << "��װ��" << endl;
	}

private:
	string m_name;
};

class PersonB :public Person
{
public:
	PersonB(string name) :m_name(name) {};
	virtual ~PersonB();
	void Show() {
		cout << m_name << "��װ��" << endl;
	}

private:
	string m_name;
};
