#pragma once

#include<Windows.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#define BUTTON_PRESSED 1

#define WS_WINDOW (WS_THICKFRAME | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU)
using namespace std;
class History
{
public:
	int init_history(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    static void create_buttons(HWND hwnd);
	static void writer();
	static void clearer();
};

