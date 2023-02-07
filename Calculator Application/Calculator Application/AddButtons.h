#pragma once
#include "windows.h"
#include "resource.h"
//#include "gdiplus.h"
#pragma comment (lib,"Gdiplus.lib")

class AddButtons {
public:
	void button(HWND hWnd);
	//Gdiplus::Bitmap* LoadImageFromResource(HMODULE hMod, const wchar_t* resid, const wchar_t* restype, HWND hWnd);
};

