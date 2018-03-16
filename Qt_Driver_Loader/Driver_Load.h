#pragma once
#include <string>

#include <windows.h>

#include <QMessageBox>

class Driver_Load
{
public:
	Driver_Load() = default;
	~Driver_Load() = default;
private:
	bool Get_Driver_Handle();
public:
	bool Init(std::string Driver_Path);
	bool Register_Driver();
	bool Start_Driver();
	bool UnRegister_Driver();
	bool Stop_Driver();
public:
	unsigned long _Last_Error = 0;
private:
	std::string _Driver_Name;
	std::string _Driver_Path;
	SC_HANDLE _Drive_Handle = 0;
	SC_HANDLE _Server_Handle = 0;
	int Sys_File = 0;
};

