#pragma once

//#include <QtWidgets>
#include <QtWidgets/QMainWindow>
#include "ui_SDR.h"
#include<thread>
#include<iostream>
#include"MySingleTon.h"
#include"SDR_Engine.h"
using namespace std;
class SDR : public QMainWindow
{
	Q_OBJECT

public:
	SDR(QWidget *parent = Q_NULLPTR);
public slots :
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();
	void on_pushButton_5_clicked();

private:
	Ui::SDRClass ui;
	MySingleTon::Ptr instance = MySingleTon::get_instance();
};
