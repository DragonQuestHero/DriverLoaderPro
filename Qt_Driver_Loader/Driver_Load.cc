#include "Driver_Load.h"

bool Driver_Load::Init(std::string Driver_Path)
{
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	_splitpath(Driver_Path.data(), drive, dir, fname, ext);
	_Driver_Name = fname;
	_Driver_Path = Driver_Path;
	if (std::string(ext)==".sys")
	{
		return true;
	}
	if (Sys_File > 0)
	{
		return true;
	}
	QMessageBox::information(nullptr, "Error", "u fucking kidding me?just choose .sys file!");
	Sys_File++;
	return false;
}

bool Driver_Load::Get_Driver_Handle()
{
	if (!_Server_Handle)
	{
		_Server_Handle = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
		if (!_Server_Handle)
		{
			_Last_Error = GetLastError();
			return false;
		}

	}
	if (!_Drive_Handle)
	{
		_Drive_Handle = OpenServiceA(_Server_Handle,
			_Driver_Name.data(), SERVICE_ALL_ACCESS);
		if (!_Drive_Handle)
		{
			_Last_Error = GetLastError();
			return false;
		}
	}
}

bool Driver_Load::Register_Driver()
{
	_Server_Handle = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!_Server_Handle)
	{
		_Last_Error = GetLastError();
		return false;
	}
	_Drive_Handle = CreateServiceA(_Server_Handle,
		_Driver_Name.data(), _Driver_Name.data(),
		SERVICE_ALL_ACCESS, SERVICE_KERNEL_DRIVER, SERVICE_DEMAND_START, SERVICE_ERROR_IGNORE,
		_Driver_Path.data(), NULL, NULL, NULL, NULL, NULL);
	if (!_Drive_Handle)
	{
		_Last_Error = GetLastError();
		return false;
	}
	return true;
}

bool Driver_Load::Start_Driver()
{
	Get_Driver_Handle();
	if (!StartServiceA(_Drive_Handle, NULL, NULL))
	{
		_Last_Error = GetLastError();
		return false;
	}
	return true;
}

bool Driver_Load::Stop_Driver()
{
	Get_Driver_Handle();
	SERVICE_STATUS status;
	status.dwWin32ExitCode = ERROR_SERVICE_SPECIFIC_ERROR;
	if (!ControlService(_Drive_Handle,
		SERVICE_CONTROL_STOP, &status))
	{
		_Last_Error = GetLastError();
		return false;
	}
	if (status.dwCurrentState == SERVICE_STOP_PENDING || status.dwCurrentState == SERVICE_STOPPED)
	{
		_Last_Error = status.dwServiceSpecificExitCode;
		return false;
	}
	return true;
}

bool Driver_Load::UnRegister_Driver()
{
	Get_Driver_Handle();
	if (!DeleteService(_Drive_Handle))
	{
		_Last_Error = GetLastError();
		return false;
	}
	return true;
}

