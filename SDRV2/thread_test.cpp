#include "thread_test.h"

thread_test::thread_test()
{
}


thread_test::~thread_test()
{
}


//用对象开启线程的入口
void thread_test::operator()() {
	//cout << "线程默认开始的位置" << endl;
	m_singleTon = MySingleTon_queue::get_instance();
	MySingleTon_queue::Queue_Element m_queue=m_singleTon->create_queue("queue2");
	//MySingleTon_queue::Queue_Element m_queue = m_singleTon->get_queue("queue2");
	for (int i = 0; i < 1000; ++i) {
		m_singleTon->add_event("operator", m_queue);
		_sleep(500);
	}

	//m_singleTon = MySingleTon_queue::get_instance();
	//int count = 5;
	//while (count >= 0)
	//{
	//	if (m_singleTon->is_empty()) {
	//		_sleep(500);
	//		count--;
	//	}
	//	else {
	//		_sleep(20);
	//		cout << m_singleTon->get_event() << endl;
	//	}
	//}

}

void thread_test::testFunc_input() {
	m_singleTon = MySingleTon_queue::get_instance();
	MySingleTon_queue::Queue_Element m_queue = m_singleTon->create_queue("queue2");
	for (int i = 0; i < 1000; ++i) {
		m_singleTon->add_event("testFunc_input", m_queue);
		_sleep(500);
	}
}

void thread_test::testFunc_output() {
	m_singleTon = MySingleTon_queue::get_instance();
	MySingleTon_queue::Queue_Element m_queue = m_singleTon->create_queue("queue2");
	//MySingleTon_queue::Queue_Element m_queue = m_singleTon->get_queue("queue2");
	int count = 5;
	while (true)
	{
		string getstr = m_singleTon->get_event(m_queue);
		if (getstr!="")
		{
			cout << m_queue.queue_name+"_" +getstr << endl;
			count = 5;
		}
		else {
			count--;
			if (count<=0)
			{
				//break;
			}
		}
		_sleep(50);
	}
}