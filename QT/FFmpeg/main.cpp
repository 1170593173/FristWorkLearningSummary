#include "FFmpeg.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FFmpeg w;
	w.show();
	return a.exec();
}
