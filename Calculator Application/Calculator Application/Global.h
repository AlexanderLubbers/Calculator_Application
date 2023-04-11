#pragma once

#include <iostream>

#include <Windows.h>

using namespace std;
class Global
{
public:
	LPCWSTR convert_to_lpcwstr(string text);
	bool startup = true;
	auto convert_to_int(string text);
};

