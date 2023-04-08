#include "History.h"

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
		
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		EndPaint(hwnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_COMMAND:
		
		break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
