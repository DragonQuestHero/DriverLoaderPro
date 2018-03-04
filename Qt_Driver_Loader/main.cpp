#include "QT_Driver_Loader.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QT_Driver_Loader w;
	w.show();
	return a.exec();
}
