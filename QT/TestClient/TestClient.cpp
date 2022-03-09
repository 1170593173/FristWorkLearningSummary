#include "TestClient.h"
#include "winsock2.h"
#include "string"
#include <iostream>
#include <QApplication>

TestClient::TestClient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	socket = new QTcpSocket();
	//QObject::connect(socket, &QTcpSocket::readyRead, this, &TestClient::on_pushButton_Connect_clicked);

}


TestClient::~TestClient()
{
	delete socket;
}

void TestClient::on_pushButton_Connect_clicked()
{
	socket->abort();
	socket->connectToHost("192.168.43.194", 9001); //这里修改为你树莓派的IP，端口是服务端里设置的
	//socket->connectToHost("10.81.59.128", 9000); //这里修改为你树莓派的IP，端口是服务端里设置的
	if (!socket->waitForConnected(30000))
		ui.label->setText("connect Fail");
	else
		ui.label->setText("connect Successfully");
	
}


void TestClient::on_pushButton_disConnect_clicked()
{
	socket->write("QUIT");
	ui.label->setText("NOT Connect");
}


void TestClient::on_pushButton_close_clicked() {
	socket->write("CLOSE");
	ui.label->setText("NOT Connect");
	this->window()->close();
}

void TestClient::on_pushButton_up_pressed()
{
	socket->write("UPUP");
}

void TestClient::on_pushButton_up_released()
{
	socket->write("STOP");
}



void TestClient::on_pushButton_down_pressed()
{
	socket->write("DOWN");
}

void TestClient::on_pushButton_down_released()
{
	socket->write("STOP");
}

void TestClient::on_pushButton_left_pressed()
{
	socket->write("LEFT");
}

void TestClient::on_pushButton_left_released()
{
	socket->write("STOP");
}

void TestClient::on_pushButton_right_pressed()
{
	socket->write("RIGHT");
}

void TestClient::on_pushButton_right_released()
{
	socket->write("STOP");
}
