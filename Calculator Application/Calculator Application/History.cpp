#include "History.h"
#include <CommCtrl.h>
#include <objidl.h>
#include <gdiplus.h>
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"") 
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

int History::init_history(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//initilize the settings window
	WNDCLASSEX history;
	ZeroMemory(&history, sizeof(WNDCLASSEX));
	history.cbSize = sizeof(WNDCLASSEX);
	history.lpfnWndProc = WindowProc;
	history.hInstance = hInstance;
	history.hCursor = LoadCursor(NULL, IDC_ARROW);
	history.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	history.lpszClassName = L"History Window";
	history.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(NULL));
	RegisterClassEx(&history);

	//create the settings window
	HWND hSettings_wnd = CreateWindowEx(0, L"History Window", L"History", WS_WINDOW, 400, 100, 800, 800, NULL, NULL, hInstance, NULL);
	ShowWindow(hSettings_wnd, nCmdShow);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT History::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
	{
		create_buttons(hwnd);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);


		// Create a new font
		LOGFONT lf = { 0 };
		lf.lfHeight = 25; // set font height to a certain amount of pixels
		lf.lfWeight = FW_NORMAL;
		lf.lfCharSet = DEFAULT_CHARSET;
		lstrcpy(lf.lfFaceName, TEXT("Arial"));
		HFONT hFont = CreateFontIndirect(&lf);
		HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
		HGDIOBJ hOldPen = SelectObject(hdc, hPen);

		SelectObject(hdc, hFont);

		// Set the starting point
		MoveToEx(hdc, 0, 120, NULL);

		// Draw the line
		LineTo(hdc, 800, 120);

		MoveToEx(hdc, 580, 120, NULL);
		LineTo(hdc, 580, 800);
		
		TextOut(hdc, 10, 93, L"Equation", 8);
		TextOut(hdc, 645, 93, L"Answer", 6);
		// Clean up
		SelectObject(hdc, hOldPen);
		DeleteObject(hPen);

		HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

		SelectObject(hdc, hOldFont);
		DeleteObject(hFont);
		ReleaseDC(hwnd, hdc);

		EndPaint(hwnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_COMMAND:
	{

	}
		break;
	case WM_CTLCOLORBTN: //In order to make those edges invisble when we use RoundRect(),
	{                //we make the color of our button's background match window's background
		return (LRESULT)GetSysColorBrush(COLOR_WINDOW + 1);
	}
	break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void History::create_buttons(HWND hwnd)
{
	DWORD dwStyle = WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON;
	HINSTANCE hInstance = GetModuleHandle(NULL);
	UINT Tool_Tip_Flag = TTF_IDISHWND | TTF_SUBCLASS;
	
	HWND button = CreateWindow(L"BUTTON", L"Clear History", dwStyle, 650, 25, 100, 50, hwnd, (HMENU)BUTTON_PRESSED, NULL, NULL);

	HWND hButtonToolTip = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hwnd, NULL, hInstance, NULL);

	TOOLINFO toolInfo = { 0 };
	toolInfo.cbSize = sizeof(toolInfo);
	toolInfo.hwnd = hwnd; // Handle to the parent window
	toolInfo.uFlags = Tool_Tip_Flag;
	toolInfo.uId = (UINT_PTR)button; // Handle to the control to associate the ToolTip with
	toolInfo.lpszText = (LPWSTR)(L"Click this button to delete answer and equation history");
	SendMessage(hButtonToolTip, TTM_ADDTOOL, 0, (LPARAM)&toolInfo);

	SendMessage(hButtonToolTip, TTM_SETMAXTIPWIDTH, 0, 500); // Set the maximum width of the ToolTip to 200 pixels
	SendMessage(hButtonToolTip, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500)); // Set the initial delay time to 500 milliseconds
	SendMessage(hButtonToolTip, TTM_SETTITLE, TTI_INFO, (LPARAM)L"Clear History"); // Set the title of the ToolTip
}