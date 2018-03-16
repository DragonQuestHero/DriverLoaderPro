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
		this, SLOT(SLOT_Start_Driver()));
	QObject::connect(ui.Stop_Driver_Button, SIGNAL(clicked()),
		this, SLOT(SLOT_Stop_Driver()));
	QObject::connect(ui.UnRegister_Driver_Button, SIGNAL(clicked()),
		this, SLOT(SLOT_UnRegister_Driver()));
}

void QT_Driver_Loader::SLOT_Open_File()
{
	QFileDialog file_path;
	QString temp_str = file_path.getOpenFileName();
	if (_Driver_Load->Init(temp_str.toStdString()) == true)
	{
		ui.Driver_Path_lineEdit->setText(temp_str);
	}
}

void QT_Driver_Loader::Error_Out()
{
	char *temp = nullptr;
	if (FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER
		| FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		_Driver_Load->_Last_Error,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		temp,
		0,
		NULL))
	{
		ui.Error_Lable->setText(temp);
	}
}

void QT_Driver_Loader::SLOT_Register_Driver()
{
	if (_Driver_Load->Register_Driver() == false)
	{
		Error_Out();
	}
	ui.Error_Lable->setText("Register SUCCESS");
}

void QT_Driver_Loader::SLOT_Start_Driver()
{
	if (_Driver_Load->Start_Driver() == false)
	{
		Error_Out();
	}
	ui.Error_Lable->setText("Start SUCCESS");
}

void QT_Driver_Loader::SLOT_Stop_Driver()
{
	if (_Driver_Load->Stop_Driver())
	{
		Error_Out();
	}
	ui.Error_Lable->setText("Stop SUCCESS");
}

void QT_Driver_Loader::SLOT_UnRegister_Driver()
{
	if (_Driver_Load->UnRegister_Driver())
	{
		Error_Out();
	}
	ui.Error_Lable->setText("UnRegister SUCCESS");
}