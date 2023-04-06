#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"

#include "BackgroundHandler.h"

using namespace rapidjson;

void BackgroundHandler::handle_background(HWND hwnd)
{
	stringstream ss;
	ifstream file("calculator_data.json");

	ss << file.rdbuf();
	string json_str = ss.str();

	Document doc;
	doc.Parse(json_str.c_str());

	string mode = doc["Mode"].GetString();
	if (mode == "Light Mode")
	{
		MessageBox(hwnd, L"light", L"help", 1);
		HDC hdc = GetDC(hwnd);
		SetBkColor(hdc, RGB(255, 255, 255));
	}
	if(mode == "Dark Mode")
	{
		MessageBox(hwnd, L"dark", L"ahhhh", 1);
		HDC hdc = GetDC(hwnd);
		SetBkColor(hdc, RGB(50, 50, 50));
	}
}


//// set the left and top coordinates of the rectangle
//rect.left = 100;
//rect.top = 100;
//
//// set the right and bottom coordinates of the rectangle
//rect.right = 200;
//rect.bottom = 200;

////InvalidateRect(hwnd, NULL, TRUE);
//		// Paint the background with the specified brush
//		// Define a global variable to hold the background color
//HBRUSH g_hBrush = CreateSolidBrush(RGB(255, 255, 255));
//HDC hdc = GetDC(hwnd);
//RECT rect;
//GetClientRect(hwnd, &rect);
//FillRect(hdc, &rect, g_hBrush);
//UpdateWindow(hwnd);