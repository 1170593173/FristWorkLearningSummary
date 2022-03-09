#pragma once
#include<iostream>
using namespace std;
class baseClass
{
public:
	virtual void Sweep() {
		cout << "ɨ��" << endl;
	}
	virtual void Wash() {
		cout << "ϴ�·�" << endl;
	}
	virtual void BuyRice() {
		cout << "����" << endl;
	}
private:

};

class Undergraduate :public baseClass {
public:
	void Sweep() {
		cout << "��ѧ��ɨ��" << endl;
	}
	void Wash() {
		cout << "��ѧ��ϴ�·�" << endl;
	}
	void BuyRice() {
		cout << "��ѧ������" << endl;
	}

	void test() {
		cout << "��ѧ���ֽ" << endl;
	}
};

class Volunteer :public baseClass {
public:
	void test() {
		cout << "����" << endl;
	}
};




class IFactory
{
public:
	virtual baseClass* createInstence() = 0;
};

class UndergraduateFactory :public IFactory{
public:
	baseClass* createInstence() {
		return new Undergraduate();
	}
};

class VolunteerFactory :public IFactory {
public:
	baseClass* createInstence() {
		return new Volunteer();
	}
};
