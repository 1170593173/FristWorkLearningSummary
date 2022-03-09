#ifndef DETECTTEST_H
#define DETECTTEST_H

#include <QtWidgets/QMainWindow>
#include "ui_detecttest.h"
#include <opencv.hpp>

class DetectTest : public QMainWindow
{
	Q_OBJECT

public:
	DetectTest(QWidget *parent = 0);
	~DetectTest();

private:
	Ui::DetectTestClass ui;
};

#endif // DETECTTEST_H
