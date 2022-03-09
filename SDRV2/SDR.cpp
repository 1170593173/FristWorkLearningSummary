#include "SDR.h"
#include <thread>
SDR::SDR(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	instance->create_queue("queue1");
	//instance->create_queue
}

void SDR::on_pushButton_clicked() {
	instance->add_event("Init","queue1",1);
}

void SDR::on_pushButton_2_clicked() {
	instance->add_event("Load Config", "queue1",1);
}

void SDR::on_pushButton_3_clicked() {
	instance->add_event("Settings", "queue1",1);
}

void SDR::on_pushButton_4_clicked() {
	instance->add_event("LOG", "queue1",1);
}
void SDR::on_pushButton_5_clicked() {
	instance->add_event("Cancel", "queue1",1);
}

