#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"

#include "History.h"
#include "Global.h"
#include <CommCtrl.h>
#include <objidl.h>
#include <gdiplus.h>
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"") 
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

using namespace rapidjson;

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

		writer();
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

void History::writer()
{
	stringstream ss;
	ifstream file("calculator_data.json");

	ss << file.rdbuf();
	string json_str = ss.str();
	ss.clear();

	Document doc;
	doc.Parse(json_str.c_str());

	//serializing the equations and answers into a string and then into their own document objects
	Value& equations = doc["Equation History"];
	Value& answers = doc["Answer History"];

	Document equation_doc;
	Document answer_doc;

	StringBuffer equation_buffer;
	StringBuffer answer_buffer;

	PrettyWriter<StringBuffer> equation_writer(equation_buffer);
	PrettyWriter<StringBuffer> answer_writer(answer_buffer);

	equations.Accept(equation_writer);
	answers.Accept(answer_writer);

	string str_equations = equation_buffer.GetString();
	string str_answers = answer_buffer.GetString();
	
	equation_doc.Parse(str_equations.c_str());
	answer_doc.Parse(str_answers.c_str());
	int count = 0;
	//looping through each document and outputing each equation to the screen
	for (const auto& member : equation_doc.GetObj())
	{

		const Value& value = member.value;
		string equation_str = value.GetString();
		if (value.IsString())
		{
			Global g;
			LPCWSTR equation = g.convert_to_lpcwstr(equation_str);
			
			HWND hwnd = FindWindow(L"History Window", L"History");
			HDC hdc = GetDC(hwnd);

			// Create a new font
			LOGFONT lf = { 0 };
			lf.lfHeight = 25; // set font height to a certain amount of pixels
			lf.lfWeight = FW_NORMAL;
			lf.lfCharSet = DEFAULT_CHARSET;
			lstrcpy(lf.lfFaceName, TEXT("Arial"));
			HFONT hFont = CreateFontIndirect(&lf);

			SelectObject(hdc, hFont);

			int y = 159 + (30 * (count - 1));
			TextOut(hdc, 10, y, equation, equation_str.length());

			HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
			SelectObject(hdc, hOldFont);
			DeleteObject(hFont);
			ReleaseDC(hwnd, hdc);
		}
		else
		{
			HWND hwnd = FindWindow(L"History Window", L"History");
			MessageBox(hwnd, L"Error while printing equations to screen", L"Error", 1);
		}
		
		count++;
	}
	for (const auto& member : answer_doc.GetObj())
	{

		const Value& value = member.value;
		string answer_str = value.GetString();
		if (value.IsString())
		{
			Global g;
			LPCWSTR answer = g.convert_to_lpcwstr(answer_str);

			HWND hwnd = FindWindow(L"History Window", L"History");
			HDC hdc = GetDC(hwnd);

			// Create a new font
			LOGFONT lf = { 0 };
			lf.lfHeight = 25; // set font height to a certain amount of pixels
			lf.lfWeight = FW_NORMAL;
			lf.lfCharSet = DEFAULT_CHARSET;
			lstrcpy(lf.lfFaceName, TEXT("Arial"));
			HFONT hFont = CreateFontIndirect(&lf);

			SelectObject(hdc, hFont);
			int y = 70 + (30 * (count - 1));
			TextOut(hdc, 640, y, answer, answer_str.length());

			HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
			SelectObject(hdc, hOldFont);
			DeleteObject(hFont);
			ReleaseDC(hwnd, hdc);

		}
		else
		{
			HWND hwnd = FindWindow(L"History Window", L"History");
			MessageBox(hwnd, L"Error while print answers to screen", L"Error", 1);
		}
		count++;
	}
}

void History::clearer()
{
}
