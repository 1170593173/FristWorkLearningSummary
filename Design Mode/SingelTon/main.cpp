#include "SDR.h"
#include <QtWidgets/QApplication>
#include"MySingleTon.h"
#include"thread_test.h"

MySingleTon::Ptr MySingleTon::m_instance_ptr = nullptr;
std::mutex MySingleTon::m_mutex;
std::mutex MySingleTon::m_mutex_messege;

void func() {
	MySingleTon::Ptr instance = MySingleTon::get_instance();
	for (int i = 0; i < 100; ++i) {
		instance->add_event("func");
		_sleep(50); 
	}
}

int main(int argc, char *argv[])
{
	//thread_test test1;
	//thread m_thread1(test1);
	//thread m_thread2(&thread_test::testFunc_input, &test1);
	//thread m_thread3(&thread_test::testFunc_output, &test1);
	//thread m_thread4(func);
	//m_thread1.join();
	//m_thread2.join();
	//m_thread3.join();
	//m_thread4.join();

	QApplication a(argc, argv);
	SDR_Engine SDR_Engine_test1;
	thread m_thread(&SDR_Engine::run, &SDR_Engine_test1);


	SDR w;
	w.show();
	return a.exec();
}
