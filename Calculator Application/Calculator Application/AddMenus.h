#pragma once
#include <Windows.h>

#define MENU_HELP 1
#define FILE_MENU_SETTINGS 2
#define FILE_MENU_EXIT 3
#define FILE_MENU_BUTTON_DETAILS 4


class AddMenus
{
public:
	void AddMenuBar(HWND hWnd);
};

