#include "QT_Driver_Loader.h"

QT_Driver_Loader::QT_Driver_Loader(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	_Driver_Load = new Driver_Load();
	QObject::connect(ui.Open_File_Button, SIGNAL(clicked()), this, SLOT(SLOT_Open_File()));
	QObject::connect(ui.Register_Driver_Button, SIGNAL(clicked()), 
		this, SLOT(SLOT_Register_Driver()));
	QObject::connect(ui.Start_Driver_Button, SIGNAL(clicked()),
		this, SLOT(SLOT_Stop_Driver()));
}

void QT_Driver_Loader::SLOT_Open_File()
{
	QFileDialog file_path;
	QString temp_str = file_path.getOpenFileName();
	ui.Driver_Path_lineEdit->setText(temp_str);
	_Driver_Load->Init(temp_str.toStdString());
}

void QT_Driver_Loader::SLOT_Register_Driver()
{
	_Driver_Load->Register_Driver();
}

void QT_Driver_Loader::SLOT_Stop_Driver()
{
	_Driver_Load->Start_Driver();
}