
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
#include "HandleMenu.h"
#include "Settings.h"
#include "BackgroundHandler.h"


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
HandleMenu m;
BackgroundHandler bh;

//create custom window message

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
        string answer = doc["Current Answer"].GetString();
        string empty = "";
        if (answer != empty)
        {
            if (b.startup == false)
            {
                LOGFONT lf = { 0 };
                lf.lfHeight = 50; // set font height to a certain amount of pixels
                lf.lfWeight = FW_NORMAL;
                lf.lfCharSet = DEFAULT_CHARSET;
                lstrcpy(lf.lfFaceName, TEXT("Arial"));
                HFONT hFont = CreateFontIndirect(&lf);

                //hdc means handle device context
                //it is a data structure that handles graphic objects and their associated attributes
                //get the hdc
                HDC hdc = GetDC(hwnd);

                SelectObject(hdc, hFont);

                Global g;
                LPCWSTR screen_message = g.convert_to_lpcwstr(answer);

                //erase everything in a given rectangle by invalidating that rectance
                /*RECT rect;
                rect.left = 10;
                rect.top = 10;
                rect.right = 10000;
                rect.bottom = 100;
                InvalidateRect(hwnd, &rect, TRUE);*/

                HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

                TextOut(hdc, 10, 35, screen_message, answer.length());
                //cleanup
                SelectObject(hdc, hOldFont);
                DeleteObject(hFont);
                ReleaseDC(hwnd, hdc);
                b.startup = false;
                return;
            }
            return;
        }
        //get the string stored in "current equation"
        string text = doc["Current Equation"].GetString();
        //get the hdc
        HDC hdc = GetDC(hwnd);

        // Create a new font
        LOGFONT lf = { 0 };
        lf.lfHeight = 50; // set font height to a certain amount of pixels
        lf.lfWeight = FW_NORMAL;
        lf.lfCharSet = DEFAULT_CHARSET;
        lstrcpy(lf.lfFaceName, TEXT("Arial"));
        HFONT hFont = CreateFontIndirect(&lf);

        HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

        LPCWSTR screen_message = b.convert_to_lpcwstr(text);
        TextOut(hdc, 10, 35, screen_message, text.length());

        //cleanup
        SelectObject(hdc, hOldFont);
        DeleteObject(hFont);
        ReleaseDC(hwnd, hdc);
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
    HWND hWnd = CreateWindowW(L"Calculator App", L"Calculator", dwStyle,
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
    wcex.lpszClassName = L"Calculator App";
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
    HWND hwnd = FindWindow(L"Calculator App", L"Calculator");
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
        switch (wParam)
        {
        case FILE_MENU_SETTINGS:
            Settings set;
            set.init_settings(GetModuleHandle(NULL), NULL, NULL, 1);
            break;
        }
        m.handle_menu(hWnd, wParam);
        hacom.handle_command(hWnd, wParam);
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_CREATE:
    {
        menu.AddMenuBar(hWnd);
        button.button(hWnd);
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
