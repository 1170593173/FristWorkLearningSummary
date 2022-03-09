#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestClient.h"
#include <QTcpSocket>


class TestClient : public QMainWindow
{
	Q_OBJECT

public:
	TestClient(QWidget *parent = Q_NULLPTR);
	~TestClient();

	QTcpSocket *socket;
private:
	Ui::TestClientClass ui;

private slots:
void on_pushButton_Connect_clicked();
void on_pushButton_disConnect_clicked();
void on_pushButton_close_clicked();

void on_pushButton_up_pressed();

void on_pushButton_up_released();


void on_pushButton_down_pressed();

void on_pushButton_down_released();

void on_pushButton_left_pressed();

void on_pushButton_left_released();

void on_pushButton_right_pressed();

void on_pushButton_right_released();

};
