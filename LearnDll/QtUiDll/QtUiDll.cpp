#include "QtUiDll.h"

QtUiDll::QtUiDll(QWidget *parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	/*Qt4���ӷ�ʽ���źŷ����ߣ��źţ��źŽ����ߣ�������(Ŀǰ������)*/
	bool hh=connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(m_close()));//// 
	/*Qt5���·�����������а�ȫ���(Ŀǰ����)*/
	hh = connect(ui.pushButton, &QPushButton::clicked, this, &QtUiDll::m_close);// Qt5���·�����������а�ȫ���
}

int QtUiDll::add_UI(int a, int b) {
	return a + b;
}

QWidget * getObj() {
	return new QtUiDll();
}

void QtUiDll::m_close() {
	isclosed = true;
	this->close();
}