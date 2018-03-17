#pragma once
#include <iostream>
#include <string>
#include <ctime>

#include <Stringapiset.h>
#include <WinBase.h>
#include <time.h>

class CGLIB_Common
{
public:
	CGLIB_Common()=default;
	~CGLIB_Common() = default;

	static bool C_TO_W(std::string str, std::wstring &result)
	{
		DWORD strsize = MultiByteToWideChar(CP_ACP, 0, str.data(), -1, NULL, 0);
		wchar_t *pwstr = new wchar_t[strsize];
		MultiByteToWideChar(CP_ACP, 0, str.data(), -1, pwstr, strsize);
		result = pwstr;
		delete[] pwstr;
		return true;
	}

	static std::wstring C_TO_W(std::string str)
	{
		std::wstring result;
		DWORD strsize = MultiByteToWideChar(CP_ACP, 0, str.data(), -1, NULL, 0);
		wchar_t *pwstr = new wchar_t[strsize];
		MultiByteToWideChar(CP_ACP, 0, str.data(), -1, pwstr, strsize);
		result = pwstr;
		delete[] pwstr;
		return result;
	}

	static bool W_TO_C(std::wstring str, std::string &result)
	{
		DWORD strsize = WideCharToMultiByte(CP_ACP, 0, str.data(), -1, NULL, 0, NULL, NULL);
		char *pstr = new char[strsize];
		WideCharToMultiByte(CP_ACP, 0, str.data(), -1, pstr, strsize, NULL, NULL);
		result = pstr;
		return true;
	}

	static std::string W_TO_C(std::wstring str)
	{
		std::string result;
		DWORD strsize = WideCharToMultiByte(CP_ACP, 0, str.data(), -1, NULL, 0, NULL, NULL);
		char *pstr = new char[strsize];
		WideCharToMultiByte(CP_ACP, 0, str.data(), -1, pstr, strsize, NULL, NULL);
		result = pstr;
		return result;
	}

	static bool I_TO_C(int i, std::string &result)//‘› ±±£¡Ù
	{
		result = const_cast<char*>(std::string(std::to_string(i)).c_str());
		return true;
	}

	static __int64 Get_UNIX()
	{
		return std::time(nullptr);
	}

	static bool UNIX_TO_String(int UNXI_Time, std::string &result)
	{
		__int64 Temp = UNXI_Time;
		char str[64];
		tm struct_time = *localtime((time_t *)&Temp);
		strftime(str, sizeof(str), "%Y-%m-%d %H:%M:%S", &struct_time);
		result = str;
		return true;
	}

	static bool UNIX_TO_String(__int64 UNXI_Time, std::string &result)
	{
		char str[64];
		tm struct_time = *localtime((time_t *)&UNXI_Time);
		strftime(str, sizeof(str), "%Y-%m-%d %H:%M:%S", &struct_time);
		result = str;
		return true;
	}

	static bool UNIX_TO_String2(__int64 UNXI_Time, std::string &result)
	{
		result = std::asctime(std::localtime(&UNXI_Time));
		return true;
	}

#ifdef _MSC_VER
	static void Console_Out_Put(std::string str)
	{
		OutputDebugStringA(const_cast<char*>(str.data()));
	}

	static void Console_Out_Put(std::wstring str)
	{
		OutputDebugStringW(const_cast<wchar_t*>(str.data()));
	}
#endif
private:
};
