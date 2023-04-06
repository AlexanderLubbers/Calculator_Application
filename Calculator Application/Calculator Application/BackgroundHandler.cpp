#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"

#include "BackgroundHandler.h"

using namespace rapidjson;

void BackgroundHandler::handle_background(WPARAM wParam, HWND hwnd)
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
		InvalidateRect(hwnd, NULL, TRUE);
		// Paint the background with the specified brush
		// Define a global variable to hold the background color
		HBRUSH g_hBrush = CreateSolidBrush(RGB(255, 255, 255));
		HDC hdc = (HDC)wParam;
		RECT rect;
		GetClientRect(hwnd, &rect);
		FillRect(hdc, &rect, g_hBrush);
		UpdateWindow(hwnd);
	}
	if(mode == "Dark Mode")
	{
		InvalidateRect(hwnd, NULL, TRUE);
		// Paint the background with the specified brush
		// Define a global variable to hold the background color
		HBRUSH g_hBrush = CreateSolidBrush(RGB(50, 50, 50));
		HDC hdc = (HDC)wParam;
		RECT rect;
		GetClientRect(hwnd, &rect);
		FillRect(hdc, &rect, g_hBrush);
		UpdateWindow(hwnd);
	}
}


//// set the left and top coordinates of the rectangle
//rect.left = 100;
//rect.top = 100;
//
//// set the right and bottom coordinates of the rectangle
//rect.right = 200;
//rect.bottom = 200;