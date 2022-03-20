#pragma once
//#include "C:\Qt\Qt5.11.3\5.11.3\msvc2015_64\include\QtWidgets\qwidget.h"
#include "QtWidgets/qwidget.h"
#include <QTimer>
#include "blocks.h"
#include <memory>
//blocks::state;
using namespace std;

class Mainblock_Area :
	public QWidget
{
	Q_OBJECT
public:
	Mainblock_Area(QWidget*);
	~Mainblock_Area();
	
	void paintEvent(QPaintEvent *event);

	static int block_x, block_y;
	static int flag;
	static int swicth;

	static std::vector<std::vector<OneBlock>>MainGroup;
	static std::vector<std::vector<OneBlock>>OldMainGroup;

	static std::shared_ptr<blocks>b_ptr;
	static std::shared_ptr<DrawGrid>g_ptr;

	void GetScope();
public slots:
	void MainUpdate();

private:
	
	

	QTimer *timer;
	
public slots:
	void rotate();
	void overturn();
	void down();

	void translationtoLeft();
	void translationtoRight();
signals:
	void OnTheBottom();
	void SingelGetScope(int addScope);
	
};

