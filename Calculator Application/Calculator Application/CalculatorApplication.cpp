
//this line of code tells the linker also known as the compiler that it will need the Microsoft Windows Common-Conrols
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"") 

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"

#include "Global.h"

#include <fstream>
#include <sstream>
#include <iostream>


#include "framework.h"
#include "CalculatorApplication.h"
#include "resource.h"
#include "HandleCommand.h"


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


AddMenus menu;
AddButtons button;
HandleCommand hacom;
Global b;

using namespace rapidjson;
using namespace std;
void screen_startup(HWND hwnd)
{
    stringstream ss;
    fstream file;
    file.open("calculator_data.json");
    if (file)
    {
        //parse json into string
        ss << file.rdbuf();
        string json_str = ss.str();
        //parse string into document object
        Document doc;
        doc.Parse(json_str.c_str());
        //get the string stored in "current equation"
        string text = doc["Current Equation"].GetString();
        //get the hdc
        HDC hdc = GetDC(hwnd);

        //make the text size larger and make the font arial
        HFONT hFont = CreateFont(74, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial");

        HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

        // Set text color
        SetTextColor(hdc, RGB(0, 0, 0)); // Red color

        // Set text background color
        SetBkColor(hdc, RGB(255, 255, 255)); // White background color
        // Draw text
        //TextOut(hdc, 1, 20, screen_text, text.length());
        LPCWSTR screen_message = b.convert_to_lpcwstr(text);
        TextOut(hdc, 10, 20, screen_message, text.length());

        //cleanup
        SelectObject(hdc, hOldFont);
        DeleteObject(hFont);
    }
    b.startup = false;
}
//   FUNCTION: InitInstance(HINSTANCE, int)
//   PURPOSE: Saves instance handle and creates main window
//   COMMENTS:In this function, we save the instance handle in a global variable and
//            create and display the main program window.      
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Store instance handle in our global variable

    DWORD dwStyle = (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU);
    HWND hWnd = CreateWindowW(szWindowClass, szTitle, dwStyle,
        200, 0, 700, 700, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);


    return TRUE;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_CALCULATORAPPLICATION);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CALCULATORAPPLICATION, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CALCULATORAPPLICATION));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int) msg.wParam;
}





//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        
        screen_startup(hWnd);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_COMMAND:
        hacom.handle_command(hWnd, wParam);
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_CREATE:
    {
        menu.AddMenuBar(hWnd);
        button.button(hWnd);
        //find a way to make this text box background white
        //HWND help = CreateWindowW(L"STATIC", L"Test", WS_VISIBLE | WS_CHILD, 0, 0, 100, 100, hWnd, NULL, NULL, NULL);
    }
        break;
    case WM_CTLCOLORBTN: //In order to make those edges invisble when we use RoundRect(),
    {                //we make the color of our button's background match window's background
        return (LRESULT)GetSysColorBrush(COLOR_WINDOW + 1);
    }
    break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        return 0;
    }
}
