#pragma once
#include <iostream>
#include<thread>
#include"MySingleTon.h"
using namespace std;

class thread_test
{
public:
	thread_test();
	~thread_test();

	void operator()();
	void testFunc_input();
	void testFunc_output();
	thread_test(int i):m_i(i){}
private:
	int m_i;
	MySingleTon::Ptr m_singleTon;

};

