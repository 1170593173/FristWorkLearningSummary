#include "QtUiDll.h"

QtUiDll::QtUiDll(QWidget *parent)
	:QWidget(parent)
{
	ui.setupUi(this);
	/*Qt4连接方式，信号发送者，信号，信号接受者，处理函数(目前不可用)*/
	bool hh=connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(m_close()));//// 
	/*Qt5的新方法，编译会有安全监测(目前可以)*/
	hh = connect(ui.pushButton, &QPushButton::clicked, this, &QtUiDll::m_close);// Qt5的新方法，编译会有安全监测
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