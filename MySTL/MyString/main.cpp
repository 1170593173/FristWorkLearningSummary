#include <iostream>
#include "MyString.h"
using namespace std;

int main() {
	MyString m_string("12345");
	MyString m_string1 = m_string;
	MyString m_string2(m_string);

	printf("%s,%s,%s\r\n", m_string, m_string1, m_string2);


	MyStringtest jj;
	printf("%s", jj);
	getchar();

	return 0;
}