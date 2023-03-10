//this line of code tells the linker also known as the compiler that it will need the Microsoft Windows Common-Conrols
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"") 

#include "framework.h"
#include "CalculatorApplication.h"
#include "resource.h"
#include "AddButtons.h"
#include "AddMenus.h"

#define MAX_LOADSTRING 100

#define MENU_HELP 1
#define FILE_MENU_EXIT 2
#define FILE_MENU_SETTINGS 3

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


AddMenus menu;
AddButtons button;



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

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
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CALCULATORAPPLICATION);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
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


//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int screen_message = 0;
    switch (message)
    {
    case WM_COMMAND:
        switch (wParam)
        {
        case MENU_HELP:
            MessageBox(hWnd, L"This is a Calculator application. Enter numbers in by clicking the buttons displaying that number and click the buttons with the operation you wish to perfrom in order to perform that operation on your number", L"Help", 1);
            break;
        case FILE_MENU_EXIT:
            DestroyWindow(hWnd);
            break;
        case LEFT_PARENTHESES_PRESSED:
            screen_message = 1;
            break;
        case RIGHT_PARENTHESES_PRESSED:
            screen_message = 2;
            break;
        case DECIMAL_PRESSED:
            screen_message = 3;
            break;
        case NEGATIVE_PRESSED:
            screen_message = 4;
            break;
        case HISTORY_PRESSED:
            screen_message = 5;
            break;
        case CLEAR_PRESSED:
            screen_message = 6;
            break;
        case SQROOT_PRESSED:
            screen_message = 7;
            break;
        case SEVEN_PRESSED:
            screen_message = 8;
            break;
        case EIGHT_PRESSED:
            screen_message = 9;
            break;
        case NINE_PRESSED:
            screen_message = 10;
            break;
        case DIVIDE_PRESSED:
            screen_message = 11;
            break;
        case PI_PRESSED:
            screen_message = 12;
            break;
        case EXPONENT_PRESSED:
            screen_message = 13;
            break;
        case FOUR_PRESSED:
            screen_message = 14;
            break;
        case FIVE_PRESSED:
            screen_message = 15;
            break;
        case SIX_PRESSESD:
            screen_message = 16;
            break;
        case MULTIPLY_PRESSED:
            screen_message = 17;
            break;
        case SINE_PRESSED:
            screen_message = 18;
            break;
        case E_PRESSED:
            screen_message = 19;
            break;
        case ONE_PRESSED:
            screen_message = 20;
            break;
        case TWO_PRESSED:
            screen_message = 21;
            break;
        case THREE_PRESSED:
            screen_message = 22;
            break;
        case SUBTRACT_PRESSED:
            screen_message = 23;
            break;
        case COSINE_PRESSED:
            screen_message = 24;
            break;
        case LOG_PRESSED:
            screen_message = 25;
            break;
        case LOGBASE_PRESSED:
            screen_message = 26;
            break;
        case ZERO_PRESSED:
            screen_message = 27;
            break;
        case COMMA_PRESSED:
            screen_message = 28;
            break;
        case ADD_PRESSED:
            screen_message = 29;
            break;
        case TANGENT_PRESSED:
            screen_message = 30;
            break;
        case INVERSE_SINE_PRESSED:
            screen_message = 31;
            break;
        case INVERSE_COSINE_PRESSED:
            screen_message = 32;
            break;
        case INVERSE_TANGENT_PRESSED:
            screen_message = 33;
            break;
        case RADICAL_PRESSED:
            screen_message = 34;
            break;
        }
        break;
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_CREATE:
        menu.AddMenuBar(hWnd);
        button.button(hWnd);
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
