#include "MyContext.h"

//typedef uint64_t hash_t;
//constexpr hash_t prime = 0x100000001B3ull;
//constexpr hash_t basis = 0xCBF29CE484222325ull;
//
///*switch×Ö·û´®´¦Àí*/
//hash_t hash_(string s)
//{
//	char const* str = s.c_str();
//	hash_t ret{ basis };
//	while (*str) { ret ^= *str; ret *= prime; str++; }
//	return ret;
//}constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis)
//{
//	return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime) : last_value;
//}


enum MyEnum
{
	E_Init, E_LoadConfig
}m_enum;

MyContext::MyContext(MySwitch*m_switch)
{
	this->m_switch = m_switch;
	//m_switch=new 
}

MyContext::MyContext(string type) {
	MySwitch * zh;
	switch (m_enum)
	{
	case E_Init:
		zh = new Init();
		this->m_switch = zh;
		break;
	case E_LoadConfig:
		zh = new Load_Config();
		this->m_switch = zh;
		break;
	default:
		zh = new No_Action();
		this->m_switch = zh;
		break;
	}
}

void MyContext::DO_GetResult() {
	this->m_switch->algorithmInterface();
}
MyContext::~MyContext()
{
	delete this->m_switch;
}
