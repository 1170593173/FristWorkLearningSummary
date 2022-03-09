#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <QtWidgets/QMainWindow>
#include "ui_threadpool.h"
#include "PoolCore.h"
#include "testtask.h"

class ThreadPool : public QMainWindow
{
	Q_OBJECT

public:
	ThreadPool(QWidget *parent = 0);

	~ThreadPool();
	//void FlashUI();

private:
	Ui::ThreadPoolClass ui;
	TestTask *task_;
	//queue<int>res1;

private slots:
	void slot_getData(int data_);
	void on_pushButton_1_clicked();
	void on_pushButton_2_clicked();

};

#endif // THREADPOOL_H
