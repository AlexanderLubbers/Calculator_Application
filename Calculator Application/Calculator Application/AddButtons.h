#pragma once
#include "Windows.h"
#include "resource.h"
#include <objidl.h>
#include <gdiplus.h>
//using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

class AddButtons {
public:
	HWND h_Sqroot;
	void button(HWND hWnd, LPARAM lParam);
	
};

