/********************************************************************************
** Form generated from reading UI file 'threadpool.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREADPOOL_H
#define UI_THREADPOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThreadPoolClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QLabel *label_1;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ThreadPoolClass)
    {
        if (ThreadPoolClass->objectName().isEmpty())
            ThreadPoolClass->setObjectName(QStringLiteral("ThreadPoolClass"));
        ThreadPoolClass->resize(842, 572);
        centralWidget = new QWidget(ThreadPoolClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_1 = new QPushButton(centralWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        label_1 = new QLabel(centralWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_1, 1, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        ThreadPoolClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ThreadPoolClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 842, 23));
        ThreadPoolClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ThreadPoolClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ThreadPoolClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ThreadPoolClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ThreadPoolClass->setStatusBar(statusBar);

        retranslateUi(ThreadPoolClass);

        QMetaObject::connectSlotsByName(ThreadPoolClass);
    } // setupUi

    void retranslateUi(QMainWindow *ThreadPoolClass)
    {
        ThreadPoolClass->setWindowTitle(QApplication::translate("ThreadPoolClass", "ThreadPool", nullptr));
        pushButton_1->setText(QApplication::translate("ThreadPoolClass", "\345\244\204\347\220\206\344\273\273\345\212\2411", nullptr));
        pushButton_2->setText(QApplication::translate("ThreadPoolClass", "\345\244\204\347\220\206\344\273\273\345\212\2412", nullptr));
        label_1->setText(QApplication::translate("ThreadPoolClass", "\344\273\273\345\212\241\344\270\200\347\273\223\346\236\234", nullptr));
        label_2->setText(QApplication::translate("ThreadPoolClass", "\344\273\273\345\212\241\344\272\214\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThreadPoolClass: public Ui_ThreadPoolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREADPOOL_H
