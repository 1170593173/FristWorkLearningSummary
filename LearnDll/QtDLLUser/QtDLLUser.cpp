#include "QtDLLUser.h"
#include "QtUiDll.h"
#include <QLibrary>
//#include "QtUiDll.h"
#include <iostream>

typedef QtUiDll *(*Get_Obj)();
QtUiDll *g_obj = NULL;
QtDLLUser::QtDLLUser(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	
	loadDll();
	//bool jj=connect(g_obj->ui.pushButton, SIGNAL(clicked()), this, SLOT(m_close()));
}

void QtDLLUser::loadDll() {
	QLibrary testlib("QtUiDll.dll");
	if (testlib.load())
	{
		Get_Obj get_Obj = (Get_Obj)testlib.resolve("getObj");
		if (get_Obj)
		{
			g_obj = get_Obj();
			int sum = g_obj->add_UI(1,2);
			std::cout<< sum << std::endl;
			int aaaa = 0;
			g_obj->show();
			//g_obj->close();
			QString sss=g_obj->ui.label->text();
		}
	}
}
void QtDLLUser::m_close() {
	g_obj->close();
}