#include "thread_test.h"

thread_test::thread_test()
{
}


thread_test::~thread_test()
{
}

void thread_test::operator()() {
	//cout << "线程默认开始的位置" << endl;
	m_singleTon = MySingleTon::get_instance();
	for (int i = 0; i < 100; ++i) {
		m_singleTon->add_event("operator");
		_sleep(50);
	}
}

void thread_test::testFunc_input() {
	m_singleTon = MySingleTon::get_instance();
	for (int i = 0; i < 100; ++i) {
		m_singleTon->add_event("testFunc_input");
		_sleep(50);
	}
}

void thread_test::testFunc_output() {
	m_singleTon = MySingleTon::get_instance();
	int count = 5;
	while (count>=0)
	{
		if (m_singleTon->is_empty()) {
 			_sleep(500);
			count--;
		}
		else {
			_sleep(20);
			cout << m_singleTon->get_event() << endl;
		}
	}
}