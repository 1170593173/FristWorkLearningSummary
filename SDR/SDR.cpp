#include "SDR.h"
#include <thread>
SDR::SDR(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void SDR::on_pushButton_clicked() {
	instance->add_event("Init");
}

void SDR::on_pushButton_2_clicked() {
	instance->add_event("Load Config");
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

