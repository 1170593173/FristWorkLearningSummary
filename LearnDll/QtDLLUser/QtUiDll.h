#pragma once

#include <QWidget>

#include <QtCore/qglobal.h>

#include "qtuidll_global.h"
#include "ui_QtUiDll.h"

#ifndef BUILD_STATIC
# if defined(QTEXTDLL_LIB)
#  define QTEXTDLL_EXPORT Q_DECL_EXPORT
# else
#  define QTEXTDLL_EXPORT Q_DECL_IMPORT
# endif
#else
# define QTEXTDLL_EXPORT
#endif

class QTUIDLL_EXPORT QtUiDll:public QWidget
{
public:
    QtUiDll(QWidget *parent =Q_NULLPTR);

	virtual int add_UI(int a, int b);
	Ui::Form ui;

	bool isclosed = false;
private slots:
	void m_close();
private:
	//Ui::QtUiDll ui;
	
	//Ui::QtUiDll ui;
};


extern "C" {
	QTUIDLL_EXPORT QWidget *getObj();
}