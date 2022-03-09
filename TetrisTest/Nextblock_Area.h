#pragma once
//#include "C:\Qt\Qt5.11.3\5.11.3\msvc2015_64\include\QtWidgets\qwidget.h"
#include "QtWidgets/qwidget.h"
//#include <QPaint>
#include <QWidget>
#include <QPainter>
#include "blocks.h"
#include <memory>
#include <QTimer>
#include <stdlib.h>
#include <time.h> 

//struct OneBlock
//{
//	QPoint p_start;
//	float w, h;
//	bool 
//};

class Nextblock_Area :
	public QWidget
{
	Q_OBJECT
public:
	Nextblock_Area(QWidget*);
	~Nextblock_Area();

	void paintEvent(QPaintEvent *event);

	//绘制边框
	void draw_frame();
	//绘制下一个方块
	void draw_block();
	static int previouFlag;
	static int flag;
private:
	//blocks *yy;
	//std::shared_ptr<blocks>pp=std::make_shared<blocks>();
	std::shared_ptr<blocks>b_ptr;
	std::shared_ptr<DrawGrid>g_ptr;

	std::vector<std::vector<OneBlock>>group;
	

	QTimer *timer;

	
public slots:
	void SetFlag();

};

