#include "QT_Driver_Loader.h"

QT_Driver_Loader::QT_Driver_Loader(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.OutPut_TextEdit->setFocusPolicy(Qt::NoFocus);
	this->setFixedSize(this->width(), this->height());

	Input_QButtonGroup = new QButtonGroup();
	Output_QButtonGroup = new QButtonGroup();
	Input_QButtonGroup->addButton(ui.Input_Ascii_Button);
	Input_QButtonGroup->addButton(ui.Input_Unicode_Button);
	Input_QButtonGroup->addButton(ui.Input_Hex_Button);

	Output_QButtonGroup->addButton(ui.Output_Ascii_Button);
	Output_QButtonGroup->addButton(ui.Output_Unicode_Button);
	Output_QButtonGroup->addButton(ui.Output_Hex_Button);

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

	QObject::connect(ui.Send_Button, SIGNAL(clicked()), this, SLOT(SLOT_Send()));

	ui.Input_Ascii_Button->clicked(true);
	ui.Input_Size_LineEdit->setText("1024");
	ui.Output_Size_LineEdit->setText("1024");
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
	if (FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		_Driver_Load->_Last_Error,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(char*)&temp,
		0,
		NULL))
	{
		ui.Error_Lable->setText(QString::fromLocal8Bit(temp));
		LocalFree(temp);
	}
}

void QT_Driver_Loader::SLOT_Register_Driver()
{
	bool result = false;
	if (ui._Nt_Load_checkBox->isChecked())
	{
		result = _Driver_Load->Nt_Register_Driver();
	}
	else if (ui.MiniFilter_checkBox->isChecked())
	{
		result = _Driver_Load->Minifilter_Register_Driver();
	}
	else
	{
		result = _Driver_Load->Register_Driver();
	}


	if (result == false)
	{
		Error_Out();
	}
	else
	{
		ui.Error_Lable->setText("Register SUCCESS");
	}
}

void QT_Driver_Loader::SLOT_Start_Driver()
{
	bool result = false;
	if (ui._Nt_Load_checkBox->isChecked())
	{
		result = _Driver_Load->Nt_Start_Driver();
	}
	else
	{
		result = _Driver_Load->Start_Driver();
	}

	if (result == false)
	{
		Error_Out();
	}
	else
	{
		ui.Error_Lable->setText("Start SUCCESS");
	}
}

void QT_Driver_Loader::SLOT_Stop_Driver()
{
	bool result = false;
	if (ui._Nt_Load_checkBox->isChecked())
	{
		result = _Driver_Load->Nt_Stop_Driver();
	}
	else
	{
		result = _Driver_Load->Stop_Driver();
	}

	if (result)
	{
		Error_Out();
	}
	else 
	{
		ui.Error_Lable->setText("Stop SUCCESS");
	}
}

void QT_Driver_Loader::SLOT_UnRegister_Driver()
{
	bool result = false;
	if (ui._Nt_Load_checkBox->isChecked())
	{
		result = _Driver_Load->Nt_UnRegister_Driver();
	}
	else
	{
		result = _Driver_Load->UnRegister_Driver();
	}

	if (result)
	{
		Error_Out();
	}
	else
	{
		ui.Error_Lable->setText("UnRegister SUCCESS");
	}
}

void QT_Driver_Loader::SLOT_Send()
{
	HANDLE handle = CreateFileA("\\\\.\\Protect_Process", GENERIC_READ | GENERIC_WRITE, 0,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (!handle)
	{
		Error_Out();
		return;
	}

	unsigned long Control_Code;
	if (ui.Hex_checkBox->isChecked())
	{
		Control_Code = strtoul(ui.Control_LineEdit->text().toStdString().data(), nullptr, 16);
	}
	else
	{
		Control_Code = stol(ui.Control_LineEdit->text().toStdString());
	}

	unsigned long Input_Lenght = stol(ui.Input_Size_LineEdit->text().toStdString());
	unsigned long Output_Lenght = stol(ui.Output_Size_LineEdit->text().toStdString());
	char *Input_Buffer = new char[Input_Lenght]();
	char *Output_Buffer = new char[Output_Lenght]();

	if (ui.Input_Ascii_Button->isChecked())
	{
		memcpy(Input_Buffer, ui.Input_lineEdit->text().toStdString().data(), ui.Input_lineEdit->text().length());
	}
	if (ui.Input_Unicode_Button->isChecked())
	{
		wstring temp_str = CGLIB_Common::C_TO_W(ui.Input_lineEdit->text().toStdString().data());
		memcpy(Input_Buffer, temp_str.data(), temp_str.length() * 2);
	}

	unsigned long temp_lenght = 0;
	if (DeviceIoControl(handle, Control_Code, Input_Buffer, Input_Lenght, Output_Buffer, Output_Lenght, &temp_lenght, nullptr))
	{
		ui.Error_Lable->setText("DeviceIoControl SUCCESS");
		string temp_str = CGLIB_Common::W_TO_C((wchar_t*)Output_Buffer);
		ui.OutPut_TextEdit->setPlainText(temp_str.data());
	}
	else
	{
		Error_Out();
	}
}