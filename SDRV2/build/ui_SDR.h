/********************************************************************************
** Form generated from reading UI file 'SDR.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SDR_H
#define UI_SDR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SDRClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QTableView *tableView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SDRClass)
    {
        if (SDRClass->objectName().isEmpty())
            SDRClass->setObjectName(QStringLiteral("SDRClass"));
        SDRClass->resize(957, 645);
        centralWidget = new QWidget(SDRClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 1, 1, 1);

        SDRClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SDRClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 957, 23));
        SDRClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SDRClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SDRClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SDRClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SDRClass->setStatusBar(statusBar);

        retranslateUi(SDRClass);

        QMetaObject::connectSlotsByName(SDRClass);
    } // setupUi

    void retranslateUi(QMainWindow *SDRClass)
    {
        SDRClass->setWindowTitle(QApplication::translate("SDRClass", "SDR", nullptr));
        pushButton->setText(QApplication::translate("SDRClass", "Start", nullptr));
        pushButton_2->setText(QApplication::translate("SDRClass", "Pause", nullptr));
        pushButton_3->setText(QApplication::translate("SDRClass", "Settings", nullptr));
        pushButton_4->setText(QApplication::translate("SDRClass", "LOG", nullptr));
        pushButton_5->setText(QApplication::translate("SDRClass", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SDRClass: public Ui_SDRClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SDR_H
