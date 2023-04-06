#include "Settings.h"
#include "Calculator_Screen.h"
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
		HWND hComboBox = CreateWindowEx(0, WC_COMBOBOX, L"", CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE, 10, 40, 200, 300, hwnd, NULL, NULL, NULL);
		SendMessage(hComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)TEXT("Light Mode"));
		SendMessage(hComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)TEXT("Dark Mode"));
		SendMessage(hComboBox, (UINT)CB_SETCURSEL, (WPARAM)0, (LPARAM)TEXT("Light Mode"));
	}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_COMMAND:
		if (HIWORD(wParam) == CBN_SELCHANGE)
			// If the user makes a selection from the list:
			//   Send CB_GETCURSEL message to get the index of the selected list item.
			//   Send CB_GETLBTEXT message to get the item.
			//   Display the item in a messagebox.
		{
			int ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
				(WPARAM)0, (LPARAM)0);
			TCHAR  ListItem[256];
			//list item is what is currently selected in the box
			(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT,
				(WPARAM)ItemIndex, (LPARAM)ListItem);
			Calculator_Screen cs;
			cs.handle_mode(ItemIndex);
			
		}
		break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
