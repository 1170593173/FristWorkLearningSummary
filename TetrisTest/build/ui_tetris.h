/********************************************************************************
** Form generated from reading UI file 'tetris.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TETRIS_H
#define UI_TETRIS_H

#include <Mainblock_Area.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <logo.h>
#include <nextblock_area.h>

QT_BEGIN_NAMESPACE

class Ui_TetrisClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    logo *widget_4;
    QGridLayout *gridLayout;
    QLabel *label_nextbox;
    QLabel *label_get;
    QLabel *label_scope;
    QLabel *label;
    Nextblock_Area *widget_3;
    Mainblock_Area *widget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_left;
    QPushButton *pushButton;
    QPushButton *pushButton_overturn;
    QPushButton *pushButton_right;
    QPushButton *pushButton_down;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TetrisClass)
    {
        if (TetrisClass->objectName().isEmpty())
            TetrisClass->setObjectName(QStringLiteral("TetrisClass"));
        TetrisClass->resize(494, 721);
        centralWidget = new QWidget(TetrisClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_4 = new logo(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));

        horizontalLayout->addWidget(widget_4);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_nextbox = new QLabel(widget);
        label_nextbox->setObjectName(QStringLiteral("label_nextbox"));
        label_nextbox->setLayoutDirection(Qt::LeftToRight);
        label_nextbox->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(label_nextbox, 0, 1, 1, 1);

        label_get = new QLabel(widget);
        label_get->setObjectName(QStringLiteral("label_get"));
        label_get->setLayoutDirection(Qt::LeftToRight);
        label_get->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_get, 1, 0, 1, 1);

        label_scope = new QLabel(widget);
        label_scope->setObjectName(QStringLiteral("label_scope"));
        label_scope->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_scope, 1, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);

        horizontalLayout->addLayout(gridLayout);

        widget_3 = new Nextblock_Area(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));

        horizontalLayout->addWidget(widget_3);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);

        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(widget);

        widget_2 = new Mainblock_Area(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));

        verticalLayout_3->addWidget(widget_2);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 5);

        verticalLayout_2->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_left = new QPushButton(centralWidget);
        pushButton_left->setObjectName(QStringLiteral("pushButton_left"));

        horizontalLayout_3->addWidget(pushButton_left);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_overturn = new QPushButton(centralWidget);
        pushButton_overturn->setObjectName(QStringLiteral("pushButton_overturn"));

        horizontalLayout_3->addWidget(pushButton_overturn);

        pushButton_right = new QPushButton(centralWidget);
        pushButton_right->setObjectName(QStringLiteral("pushButton_right"));

        horizontalLayout_3->addWidget(pushButton_right);


        verticalLayout->addLayout(horizontalLayout_3);

        pushButton_down = new QPushButton(centralWidget);
        pushButton_down->setObjectName(QStringLiteral("pushButton_down"));

        verticalLayout->addWidget(pushButton_down);


        verticalLayout_2->addLayout(verticalLayout);

        TetrisClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TetrisClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 494, 23));
        TetrisClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TetrisClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TetrisClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TetrisClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TetrisClass->setStatusBar(statusBar);

        retranslateUi(TetrisClass);

        QMetaObject::connectSlotsByName(TetrisClass);
    } // setupUi

    void retranslateUi(QMainWindow *TetrisClass)
    {
        TetrisClass->setWindowTitle(QApplication::translate("TetrisClass", "Tetris", nullptr));
        label_nextbox->setText(QApplication::translate("TetrisClass", "next", nullptr));
        label_get->setText(QApplication::translate("TetrisClass", "\345\276\227\345\210\206", nullptr));
        label_scope->setText(QApplication::translate("TetrisClass", "0", nullptr));
        label->setText(QApplication::translate("TetrisClass", "\345\205\263\345\215\2411", nullptr));
        pushButton_left->setText(QApplication::translate("TetrisClass", "left", nullptr));
        pushButton->setText(QApplication::translate("TetrisClass", "rotate", nullptr));
        pushButton_overturn->setText(QApplication::translate("TetrisClass", "overturn", nullptr));
        pushButton_right->setText(QApplication::translate("TetrisClass", "right", nullptr));
        pushButton_down->setText(QApplication::translate("TetrisClass", "down", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TetrisClass: public Ui_TetrisClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TETRIS_H
