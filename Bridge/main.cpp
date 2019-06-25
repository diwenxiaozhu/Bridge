#include "Bridge.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Bridge w;
	w.show();
	return a.exec();
}
