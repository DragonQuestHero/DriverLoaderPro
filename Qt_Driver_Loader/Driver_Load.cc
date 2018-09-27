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

bool Driver_Load::Minifilter_Register_Driver()
{
	_Server_Handle = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!_Server_Handle)
	{
		_Last_Error = GetLastError();
		return false;
	}
	_Drive_Handle = CreateServiceA(_Server_Handle,
		_Driver_Name.data(), _Driver_Name.data(),
		SERVICE_ALL_ACCESS, SERVICE_FILE_SYSTEM_DRIVER, SERVICE_DEMAND_START, SERVICE_ERROR_IGNORE,
		_Driver_Path.data(), NULL, NULL, NULL, NULL, NULL);
	if (!_Drive_Handle)
	{
		_Last_Error = GetLastError();
		return false;
	}

	std::string temp_str;
	HKEY phkResult;
	temp_str = "SYSTEM\\ControlSet001\\Services\\" + _Driver_Name;
	if (ERROR_SUCCESS == RegOpenKeyExA(HKEY_LOCAL_MACHINE, temp_str.data(), 0, KEY_ALL_ACCESS, &phkResult))
	{
		RegSetValueExA(phkResult, "DependOnService", 0, REG_MULTI_SZ, (BYTE*)"FltMgr", 7);
		temp_str = _Driver_Name + " Driver";
		RegSetValueExA(phkResult, "Description", 0, REG_SZ, (BYTE*)temp_str.data(), temp_str.length());
		RegSetValueExA(phkResult, "Group", 0, REG_SZ, (BYTE*)"FSFilter Activity Monitor", 26);
		DWORD temp_value = 3;
		RegSetValueExA(phkResult, "SupportedFeatures", 0, REG_DWORD, (LPBYTE)&temp_value, sizeof(DWORD));
		temp_value = 2;
		RegSetValueExA(phkResult, "Tag", 0, REG_DWORD, (BYTE*)&temp_value, 4);
		temp_value = 2;
		RegSetValueExA(phkResult, "Type", 0, REG_DWORD, (BYTE*)&temp_value, 4);

		RegCreateKeyA(phkResult, "Instances", &phkResult);
		temp_str = _Driver_Name + " Instance";
		RegSetValueExA(phkResult, "DefaultInstance", 0, REG_SZ, (BYTE*)temp_str.data(), temp_str.length());

		temp_str = _Driver_Name + " Instance";
		RegCreateKeyA(phkResult, temp_str.data(), &phkResult);
		RegSetValueExA(phkResult, "Altitude", 0, REG_SZ, (BYTE*)"325107", 7);
		temp_value = 4;
		RegSetValueExA(phkResult, "Flags", 0, REG_DWORD, (BYTE*)&temp_value, 4);
		RegCloseKey(phkResult);
	}
	else
	{
		_Last_Error = GetLastError();
		return false;
	}
	return true;
}

bool Driver_Load::Nt_Register_Driver()
{
	
}
