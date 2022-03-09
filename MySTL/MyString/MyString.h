#pragma once
#include<stdio.h>
#include <string.h>
class MyString
{
public:
	MyString(const char*str);
	MyString(const MyString &other);
	MyString&operator=(const MyString &other);
	~MyString();
private:
	char *data;
};


class MyStringtest
{
public:
	MyStringtest() {

	}

private:
	const char *data22 = "ok";
	const char *data="ssssss";
};