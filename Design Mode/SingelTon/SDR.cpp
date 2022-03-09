#include "SDR.h"
#include <thread>

SDR::SDR(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	std::thread ss;


	/*thread_test test1;
	thread m_thread1(test1);
	thread m_thread2(&thread_test::testFunc_input, &test1);
	thread m_thread3(&thread_test::testFunc_output, &test1);
	thread m_thread4(func);
	m_thread1.join();
	m_thread2.join();
	m_thread3.join();
	m_thread4.join();*/
}

void SDR::on_pushButton_clicked() {
	instance->add_event("Start");
}

void SDR::on_pushButton_2_clicked() {
	instance->add_event("Pause");
}

void SDR::on_pushButton_3_clicked() {
	instance->add_event("Settings");
}

void SDR::on_pushButton_4_clicked() {
	instance->add_event("LOG");
}
void SDR::on_pushButton_5_clicked() {
	instance->add_event("Cancel");
}



