#include "QT_Driver_Loader.h"
#include <QtWidgets/QApplication>

#ifdef NDEBUG
#include <QtPlugin>
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
#endif // DEBUG


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QT_Driver_Loader w;
	w.show();
	return a.exec();
}
