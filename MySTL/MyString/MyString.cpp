#include "MyString.h"

MyString::MyString(const char * str)
{
	if (str == NULL) {
		data = new char[1];
		data = "\0";
	}
	else
	{
		int len = strlen(str);
		data = new char[len+1];
		strcpy(data, str);
	}
}

MyString::MyString(const MyString & other)
{
	int len = strlen(other.data);
	data = new char[len + 1];
	strcpy(data, other.data);
}

MyString & MyString::operator=(const MyString & other)
{
	if (this==&other)
	{
		return *this;
	}
	if (data)
	{
		delete[]data;
	}

	int len = strlen(other.data);
	data = new char[len + 1];
	strcpy(data, other.data);
	return *this;
}

MyString::~MyString()
{
	delete[]data;
}


