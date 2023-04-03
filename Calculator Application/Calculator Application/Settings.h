#pragma once
#include <Windows.h>
#include <commctrl.h>  
#pragma comment(lib, "comctl32.lib")
class Settings
{
public:
	int init_settings(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
};

