#include "QtDLLUser.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtDLLUser w;
    w.show();
    return a.exec();
}
