#include "threadpool.h"
#include <windows.h>


ThreadPool::ThreadPool(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	task_ = new TestTask();
	bool test =connect(task_, SIGNAL(sendData(int)), this, SLOT(slot_getData(int)));
	//FlashUI();
}

ThreadPool::~ThreadPool()
{

}

void ThreadPool::slot_getData(int data_) {

	//res1.push(data_);
	QString str=ui.label_1->text();
	str = str+" "+QString::number(data_);
	ui.label_1->setText(str);
}

void ThreadPool::on_pushButton_1_clicked() {
	task_->from = 10;
	task_->to = 0;
	task_->start();
}
void ThreadPool::on_pushButton_2_clicked() {
	task_->from = 20;
	task_->to = 0;
	task_->start();
}

//void ThreadPool::FlashUI() {
//	QString str = ui.label_1->text();
//	while (true)
//	{
//		if (!res1.empty())
//		{
//			str = str + " " + QString::number(res1.front());
//			res1.pop();
//			ui.label_1->setText(str);
//		}
//		else
//			Sleep(100);
//	}
//}