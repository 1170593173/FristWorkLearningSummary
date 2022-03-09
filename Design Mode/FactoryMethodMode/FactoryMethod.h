#pragma once
#include<iostream>
using namespace std;
class baseClass
{
public:
	virtual void Sweep() {
		cout << "扫地" << endl;
	}
	virtual void Wash() {
		cout << "洗衣服" << endl;
	}
	virtual void BuyRice() {
		cout << "买米" << endl;
	}
private:

};

class Undergraduate :public baseClass {
public:
	void Sweep() {
		cout << "大学生扫地" << endl;
	}
	void Wash() {
		cout << "大学生洗衣服" << endl;
	}
	void BuyRice() {
		cout << "大学生买米" << endl;
	}

	void test() {
		cout << "大学生念报纸" << endl;
	}
};

class Volunteer :public baseClass {
public:
	void test() {
		cout << "做饭" << endl;
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
