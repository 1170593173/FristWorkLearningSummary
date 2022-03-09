#include "SDR_Engine.h"


enum Test
{
	Start,Pause,Settings,LOG,Cancel
}m_test;

SDR_Engine::SDR_Engine()
{
}
SDR_Engine::~SDR_Engine()
{
}

typedef uint64_t hash_t;
//typedef std::uint64_t hash_t;
//constexpr hash_t prime = 0x100000001B3ull;
//constexpr hash_t basis = 0xCBF29CE484222325ull;

//hash_t hash_(string s)
//{
//	char const* str = s.c_str();
//	hash_t ret{ basis };
//	while (*str) {ret ^= *str;ret *= prime;str++;}
//	return ret;
//}

//constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis)
//{
//	return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime) : last_value;
//}

void SDR_Engine::run() {
	MySingleTon::Ptr instance = MySingleTon::get_instance();
	string str_event = "";
	while (true)
	{
		str_event = instance->get_event();
		Core(str_event);
		if (str_event == "Cancel") {
			break;
		}
		_sleep(50);
	}
}

void SDR_Engine::Core(string str_event) {
	switch (m_test)
	{
	case Start:
		cout << str_event << endl;
		break;
	case Pause:
		cout << str_event << endl;
		break;
	case Settings:
		cout << str_event << endl;
		break;
	case LOG:
		cout << str_event << endl;
		break;
	case Cancel:
		cout << str_event << endl;
		break;
	default:

		break;
	}
}