#include "Settings.h"
#include "resource.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int Settings::init_settings(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//initilize the settings window
	WNDCLASSEX settings;
	ZeroMemory(&settings, sizeof(WNDCLASSEX));
	settings.cbSize = sizeof(WNDCLASSEX);
	settings.lpfnWndProc = WindowProc;
	settings.hInstance = hInstance;
	settings.hCursor = LoadCursor(NULL, IDC_ARROW);
	settings.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	settings.lpszClassName = L"Settings";
	settings.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(GEAR));
	RegisterClassEx(&settings);

	//create the settings window
	HWND hSettings_wnd = CreateWindowEx(0, L"Settings", L"Settings", WS_OVERLAPPEDWINDOW, 400, 100, 400, 400, NULL, NULL, hInstance, NULL);
	ShowWindow(hSettings_wnd, nCmdShow);

	MSG msg;
	while (GetMessage(&msg, NULL, 0 ,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
	{
		HWND hComboBox = CreateWindowEx(0, WC_COMBOBOX, L"", CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE, 10, 40, 200, 300, hwnd, NULL, NULL, NULL);
	}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
