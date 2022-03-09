#include "logo.h"



logo::logo(QWidget *m_widget)
{
}


logo::~logo()
{
}

void logo::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	// 设置画笔颜色
	painter.setPen(QPen(QColor(0, 100, 230), 10));

	// 设置字体：微软雅黑、点大小50、斜体
	QFont font;
	font.setFamily("Microsoft YaHei");
	font.setPointSize(40);
	font.setItalic(true);
	painter.setFont(font);

	// 绘制文本
	painter.drawText(rect(), Qt::AlignCenter, "MyTetris");

}