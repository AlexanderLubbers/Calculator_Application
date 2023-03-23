#pragma once
#include<Windows.h>
#include "AddMenus.h"
#include "AddButtons.h"
#include "Calculator_Screen.h"

class HandleCommand
{
public:
	void handle_command(HWND hWnd, WPARAM wParam);
};

