#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtDLLUser.h"

class QtDLLUser : public QMainWindow
{
    Q_OBJECT

public:
    QtDLLUser(QWidget *parent = Q_NULLPTR);
	void loadDll();
private slots:
	void m_close();
private:
    Ui::QtDLLUserClass ui;
};
