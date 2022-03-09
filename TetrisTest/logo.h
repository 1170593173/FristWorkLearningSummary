#pragma once
//#include "C:\Qt\Qt5.11.3\5.11.3\msvc2015_64\include\QtWidgets\qwidget.h"
#include "QtWidgets/qwidget.h"
#include <QPainter>
class logo :
	public QWidget
{
public:
	logo(QWidget *);
	~logo();
	void paintEvent(QPaintEvent *event);
};

