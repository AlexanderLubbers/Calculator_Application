#pragma once

#include <fstream>
#include <sstream>
#include <cstring>

#include <Windows.h>

using namespace std;

class BackgroundHandler
{
public:
	void handle_background(HWND hwnd);
};