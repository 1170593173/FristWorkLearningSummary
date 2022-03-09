#include "TestClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestClient w;
	w.show();
	return a.exec();
}
