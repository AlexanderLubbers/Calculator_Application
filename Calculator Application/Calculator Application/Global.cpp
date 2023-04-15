#include "Global.h"

LPCWSTR Global::convert_to_lpcwstr(string text)
{
	// Convert the std::string to LPCWSTR
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, text.c_str(), -1, NULL, 0);
	wchar_t* wstr = new wchar_t[size_needed];
	MultiByteToWideChar(CP_UTF8, 0, text.c_str(), -1, wstr, size_needed);
	LPCWSTR result = wstr;
	return wstr;
}


