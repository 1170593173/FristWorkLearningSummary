#include "logo.h"



logo::logo(QWidget *m_widget)
{
}


logo::~logo()
{
}

void logo::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	// ���û�����ɫ
	painter.setPen(QPen(QColor(0, 100, 230), 10));

	// �������壺΢���źڡ����С50��б��
	QFont font;
	font.setFamily("Microsoft YaHei");
	font.setPointSize(40);
	font.setItalic(true);
	painter.setFont(font);

	// �����ı�
	painter.drawText(rect(), Qt::AlignCenter, "MyTetris");

}