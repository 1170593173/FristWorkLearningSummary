#ifndef TESTTASK_H
#define TESTTASK_H

#include <QObject>
#include <chrono>
#include "PoolCore.h"
#include <QThread>
using namespace std;

class TestTask : public QThread
{
	Q_OBJECT

public:
	TestTask();
	TestTask(int infrom, int into);
	//void threadTest(int from, int to);
	void run();
	int countdown(int from, int to);
	~TestTask();
	int from, to;
	

private:
	
	
signals:
	void sendData(int data_);
};

#endif // TESTTASK_H
