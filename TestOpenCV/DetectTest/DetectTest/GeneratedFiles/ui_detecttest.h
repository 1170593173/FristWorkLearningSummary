/********************************************************************************
** Form generated from reading UI file 'detecttest.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTTEST_H
#define UI_DETECTTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectTestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DetectTestClass)
    {
        if (DetectTestClass->objectName().isEmpty())
            DetectTestClass->setObjectName(QStringLiteral("DetectTestClass"));
        DetectTestClass->resize(600, 400);
        menuBar = new QMenuBar(DetectTestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        DetectTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DetectTestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DetectTestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DetectTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DetectTestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DetectTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DetectTestClass->setStatusBar(statusBar);

        retranslateUi(DetectTestClass);

        QMetaObject::connectSlotsByName(DetectTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *DetectTestClass)
    {
        DetectTestClass->setWindowTitle(QApplication::translate("DetectTestClass", "DetectTest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetectTestClass: public Ui_DetectTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTTEST_H
