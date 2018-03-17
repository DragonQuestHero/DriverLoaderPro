#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QT_Driver_Loader.h"

#include <QFileDialog>

#include "Driver_Load.h"

#include "CGLIB_Common.hpp"

using namespace std;

class QT_Driver_Loader : public QMainWindow
{
	Q_OBJECT

public:
	QT_Driver_Loader(QWidget *parent = Q_NULLPTR);
public:
	
private:
	QButtonGroup *Input_QButtonGroup = nullptr;
	QButtonGroup *Output_QButtonGroup = nullptr;
private:
	void Error_Out();
private:
	Ui::QT_Driver_LoaderClass ui;
	Driver_Load *_Driver_Load;
public slots:
	void SLOT_Open_File();
	void SLOT_Register_Driver();
	void SLOT_Start_Driver();
	void SLOT_Stop_Driver();
	void SLOT_UnRegister_Driver();
	void SLOT_Send();
signals:

};
