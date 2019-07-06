#include "Bridge.h"
#include <QtWidgets/QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QPixmap pixmap(":/Bridge/bridge.jpg");
	QSplashScreen splash(pixmap);//³ÌÐòÆô¶¯»­Ãæ
	for (qint64 i = 5555555; i > 0; i--)
		splash.show();
	Bridge w;
	splash.finish(&w);
	w.show();
	return a.exec();
}
