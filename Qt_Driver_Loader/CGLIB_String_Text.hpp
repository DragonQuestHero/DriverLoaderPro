#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

//-----------TEXT
class CGLIB_String_Text
{
public:
	CGLIB_String_Text()
	{
		CG_Base64_Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz"
			"0123456789+/";
	}
	~CGLIB_String_Text()=default;
public:
	std::string GET_Left(std::string p, std::string sp,
		int t_size = 0, int on_text = 0)
	{
		//t_size=取出长度 0为全部
		//on_text=是否包含自身 1为包含.0为不包含
		std::string str = p;

		int index = p.find(sp, 0);
		if (index == -1)
		{
			return "";
		}

		//取出全部且包含自身
		if (t_size == 0 && on_text == 1)
		{
			str.erase(index + sp.length());
		}
		//取出指定个数且包含自身
		if (t_size != 0 && on_text == 1)
		{
			str.erase(index + sp.length());
			str.erase(0, str.length() - t_size - sp.length());
		}
		//取出全部且不包含自身
		if (t_size == 0 && on_text == 0)
		{
			str.erase(index);
		}
		//取出指定个数且不包含自身
		if (t_size != 0 && on_text == 0)
		{
			str.erase(index);
			str.erase(0, str.length() - t_size);
		}


		return str;
	}

	std::string GET_Right(std::string p, std::string sp,
		int t_size = 0, int on_text = 0)
	{
		//t_size=取出长度 0为全部
		//on_text=是否包含自身 1为包含.0为不包含
		std::string str = p;

		int index = p.find(sp, 0);
		if (index == -1)
		{
			return "";
		}

		//取出全部且包含自身
		if (t_size == 0 && on_text == 1)
		{
			str.erase(0, index);
		}
		//取出指定个数且包含自身
		if (t_size != 0 && on_text == 1)
		{
			str.erase(0, index);
			str.erase(t_size + sp.length(), p.length() - t_size);
		}
		//取出全部且不包含自身
		if (t_size == 0 && on_text == 0)
		{
			str.erase(0, index + sp.length());
		}
		//取出指定个数且不包含自身
		if (t_size != 0 && on_text == 0)
		{
			str.erase(0, index + sp.length());
			str.erase(t_size, p.length() - t_size);
		}

		return str;
	}

	std::string GET_MID(std::string p, std::string lp, std::string rp)
	{
		std::string str = p;
		int lindex = p.find(lp, 0);
		int rindex = p.find(rp, lindex + lp.length());
		if (lindex == -1 || rindex == -1)
		{
			return "";
		}

		str.erase(0, lindex + lp.length());
		int i = rindex - lindex;
		i = i - lp.length();
		str.erase(rindex - lindex - lp.length());
		return str;
	}
	std::string GET_MID(std::string p, std::string lp, std::string rp,
		int lindex, int &rindex)
	{
		std::string str = p;
		lindex = p.find(lp, rindex);
		rindex = p.find(rp, lindex);
		if (lindex == -1 || rindex == -1)
		{
			return "";
		}
		str.erase(0, lindex + lp.length());
		str.erase(rindex - lindex - lp.length());
		return str;
	}

	std::vector<std::string> Find_ALL(std::string &str,std::string &search)
	{
		using namespace std;
		vector<string> temp;
		int index = -1;
		index = str.find(search, index + 1);
		while (index != -1)
		{
			temp.push_back(to_string(index));
			index = str.find(search, index + 1);
		}
		return temp;
	}
	std::vector<std::string> Find_ALL(std::string str, std::string search)
	{
		using namespace std;
		vector<string> temp;
		int index = -1;
		index = str.find(search, index + 1);
		while (index != -1)
		{
			temp.push_back(to_string(index));
			index = str.find(search, index + 1);
		}
		return temp;
	}

	std::vector<std::string> Split(const std::string &p,
		const std::string &regex)
	{
		std::vector<std::string> resVec;

		if ("" == p)
		{
			return resVec;
		}
		std::string strs = p + regex;
		size_t pos = strs.find(regex);
		size_t size = strs.size();
		while (pos != std::string::npos)
		{
			std::string x = strs.substr(0, pos);
			resVec.push_back(x);
			strs = strs.substr(pos + regex.length(), size);
			pos = strs.find(regex);
		}
		return resVec;
	}

	std::string Replace(std::string &str,
		const std::string &old_value, const std::string &new_value)
	{
		for (std::string::size_type pos(0); pos != std::string::npos; pos += new_value.length()) {
			if ((pos = str.find(old_value, pos)) != std::string::npos)
			{
				str.replace(pos, old_value.length(), new_value);
			}
			else
			{
				break;
			}
		}
		return str;
	}

	std::string Replace_ALL(std::string &str,
		const std::string &old_value, const std::string &new_value)
	{
		while (true) {
			std::string::size_type pos(0);
			if ((pos = str.find(old_value)) != std::string::npos)
			{
				str.replace(pos, old_value.length(), new_value);
			}
			else
			{
				break;
			}
		}
		return str;
	}

	//转换后的字符串是否大写
	std::string String_TO_HEX(const std::string& s, bool upper_case = true)
	{
		std::ostringstream ret;
		for (std::string::size_type i = 0; i < s.length(); ++i)
			ret << std::hex << std::setfill('0') << std::setw(2) << (upper_case ? std::uppercase : std::nouppercase) << (int)(unsigned char)s[i];
		return ret.str();
	}
	 
	std::string HEX_TO_String(const std::string& input)
	{
		if (input == "")
		{
			return input;
		}
		static const char* const lut = "0123456789ABCDEF";
		size_t len = input.length();
		if (len & 1) return "odd length";

		std::string output;
		output.reserve(len / 2);
		for (size_t i = 0; i < len; i += 2)
		{
			char a = input[i];
			const char* p = std::lower_bound(lut, lut + 16, a);
			if (*p != a) return "not a hex digit";

			char b = input[i + 1];
			const char* q = std::lower_bound(lut, lut + 16, b);
			if (*q != b) return "not a hex digit";

			output.push_back(((p - lut) << 4) | (q - lut));
		}
		return output;
	}

	std::string Base64_Encode(const std::string& str)
	{
		if (str == "")
		{
			return str;
		}
		unsigned char const* bytes_to_encode = reinterpret_cast<const unsigned char*>(str.c_str());
		unsigned int in_len = str.length();
		std::string ret;
		int i = 0;
		int j = 0;
		unsigned char char_array_3[3];
		unsigned char char_array_4[4];

		while (in_len--) {
			char_array_3[i++] = *(bytes_to_encode++);
			if (i == 3) {
				char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
				char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
				char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
				char_array_4[3] = char_array_3[2] & 0x3f;

				for (i = 0; (i < 4); i++)
					ret += CG_Base64_Chars[char_array_4[i]];
				i = 0;
			}
		}

		if (i)
		{
			for (j = i; j < 3; j++)
				char_array_3[j] = '\0';

			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for (j = 0; (j < i + 1); j++)
				ret += CG_Base64_Chars[char_array_4[j]];

			while ((i++ < 3))
				ret += '=';

		}
		return ret;
	}

	std::string Base64_Decode(const std::string& encoded_string)
	{
		if (encoded_string == "")
		{
			return encoded_string;
		}
		int in_len = encoded_string.size();
		int i = 0;
		int j = 0;
		int in_ = 0;
		unsigned char char_array_4[4], char_array_3[3];
		std::string ret;

		while (in_len-- && (encoded_string[in_] != '=') && IS_Base64(encoded_string[in_])) {
			char_array_4[i++] = encoded_string[in_]; in_++;
			if (i == 4) {
				for (i = 0; i < 4; i++)
					char_array_4[i] = CG_Base64_Chars.find(char_array_4[i]);

				char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
				char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
				char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

				for (i = 0; (i < 3); i++)
					ret += char_array_3[i];
				i = 0;
			}
		}

		if (i) {
			for (j = i; j < 4; j++)
				char_array_4[j] = 0;

			for (j = 0; j < 4; j++)
				char_array_4[j] = CG_Base64_Chars.find(char_array_4[j]);

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
		}
		return ret;
	}

	bool IS_Base64(unsigned char c) {
		return (isalnum(c) || (c == '+') || (c == '/'));
	}

	std::string URL_Encode(const std::string &str)
	{
		if (str == "")
		{
			return str;
		}
		//RFC 3986 section 2.3 Unreserved Characters (January 2005)
		const std::string unreserved = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_.~";

		std::string escaped = "";
		for (size_t i = 0; i < str.length(); i++)
		{
			if (unreserved.find_first_of(str[i]) != std::string::npos)
			{
				escaped.push_back(str[i]);
			}
			else
			{
				escaped.append("%");
				char buf[3];
				sprintf_s(buf, "%.2X", (unsigned char)str[i]);//(unsigned char)
				escaped.append(buf);
			}
		}
		return escaped;
	}

	std::string Case_Upper(const std::string &str)
	{
		std::string result = str;
		transform(result.begin(), result.end(), result.begin(), toupper);
		return result;
	}

	std::string Case_Lower(const std::string &str)
	{
		std::string result = str;
		transform(result.begin(), result.end(), result.begin(), tolower);
		return result;
	}

private:
	std::string CG_Base64_Chars;
};
//-----------TEXT