#pragma once
#include <iostream>
using namespace std;
//�Ծ�ģ��
class TestPaper
{
public:
	void TestQuestion1();
	void TestQuestion2();
	void TestQuestion3();
	virtual ~TestPaper()
	{
	}
	TestPaper()
	{
	}
public:
	virtual char answer1() = 0;
	virtual char answer2() = 0;
	virtual char answer3() = 0;
};



//ѧ��A���Ծ�

class TestPaperA :public TestPaper
{
public:
	TestPaperA()
	{
	}
	~TestPaperA()
	{
	}
public:
	char answer1() { return 'C'; }
	char answer2() { return 'C'; }
	char answer3() { return 'C'; }
};


//ѧ��B���Ծ�
class TestPaperB :public TestPaper
{
public:
	TestPaperB()
	{
	}
	~TestPaperB()
	{
	}
public:
	char answer1() { return 'A'; }
	char answer2() { return 'B'; }
	char answer3() { return 'D'; }
};