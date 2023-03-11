#pragma once
#include <Windows.h>

#define MENU_HELP 1
#define FILE_MENU_EXIT 2
#define FILE_MENU_SETTINGS 3

class AddMenus
{
public:
	void AddMenuBar(HWND hWnd);
};

