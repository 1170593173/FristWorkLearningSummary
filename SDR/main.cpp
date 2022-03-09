#include "SDR.h"
#include <QtWidgets/QApplication>
#include"MySingleTon-queue.h"
#include "MySingleTon.h"

MySingleTon_queue::Ptr MySingleTon_queue::m_instance_ptr = nullptr;
std::mutex MySingleTon_queue::m_mutex;
std::mutex MySingleTon_queue::m_mutex_messege;
//std::mutex MySingleTon::m_mutex_messege;

std::mutex MySingleTon::m_mutex_messege;
void func() {
	MySingleTon_queue::Ptr instance = MySingleTon_queue::get_instance();
	for (int i = 0; i < 100; ++i) {
		instance->add_event("func");
		_sleep(50);
	}
}

int main(int argc, char *argv[])
{
	//thread_pool m_thread_pool(3);//�����̳߳��е��߳�����
	//thread_test testitem;
	//m_thread_pool.add_task(func); //��ͨ���������̳߳صķ���
	//m_thread_pool.add_task(testitem);//()���غ��������̳߳صķ���
	//m_thread_pool.add_task(bind(&thread_test::testFunc_input, testitem));//������ͨ���������̳߳صķ���
	//m_thread_pool.add_task(bind(&thread_test::testFunc_output, testitem));



	/*thread_test test1;
	thread m_thread1(test1);
	thread m_thread2(&thread_test::testFunc_input, &test1);
	thread m_thread3(&thread_test::testFunc_output, &test1);
	thread m_thread4(func);
	m_thread1.join();
	m_thread2.join();
	m_thread3.join();
	m_thread4.join();*/

	QApplication a(argc, argv);

	SDR_Engine SDR_Engine_test1;
	thread m_thread(&SDR_Engine::run, &SDR_Engine_test1);
	SDR w;
	w.show();

	if (m_thread.joinable()) {
		m_thread.detach();
		//m_thread.join();
	}
	return a.exec();
}
