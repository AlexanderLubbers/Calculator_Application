#include "AddButtons.h"

void AddButtons::button(HWND hWnd, LPARAM lParam)
{
    DWORD dwStyle = WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON;
    DWORD dwStyleBMP = WS_VISIBLE | WS_CHILD | BS_BITMAP | BS_PUSHBUTTON;
    HINSTANCE hInstance = GetModuleHandle(NULL);

    //first row
    //(
    HWND h_Left_Parentheses = CreateWindow(L"BUTTON", L"(", dwStyle, 15, 115, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //)
    HWND h_Right_Parantheses = CreateWindow(L"BUTTON", L")", dwStyle, 126.5, 115, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //.
    HWND h_Decimal_Point = CreateWindow(L"BUTTON", L".", dwStyle, 238, 115, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //-
    HWND h_Negative_Symbol = CreateWindow(L"BUTTON", L"-", dwStyle, 349.5, 115, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //history button
    HWND h_History = CreateWindow(L"BUTTON", L"History", dwStyle, 461, 115, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //history clear
    HWND h_Clear = CreateWindow(L"BUTTON", L"Clear", dwStyle, 572.5, 115, 96.5, 72.5, hWnd, NULL, hInstance, NULL);

    //second row
    //uploading the radical symbol onto a button
    HWND h_Sqroot = CreateWindowEx(NULL, L"BUTTON", NULL, dwStyleBMP, 15, 202.5, 96.5, 72.5, hWnd, (HMENU)301, hInstance, NULL);
    HICON Sqroot_bit = LoadIcon(hInstance, MAKEINTRESOURCE(SQROOT));
    if (Sqroot_bit == NULL) {
        MessageBox(hWnd, L"Image failed to load", L"Error", 1);
    }
    SendMessage(h_Sqroot, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)Sqroot_bit);
    //7
    HWND h_Seven = CreateWindow(L"BUTTON", L"7", dwStyle, 126.5, 202.5, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //8
    HWND h_Eight = CreateWindow(L"BUTTON", L"8", dwStyle, 238, 202.5, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //9
    HWND h_Nine = CreateWindow(L"BUTTON", L"9", dwStyle, 349.5, 202.5, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //division sign
    HWND h_Division = CreateWindow(L"BUTTON", L"", dwStyleBMP, 461, 202.5, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    HICON div = LoadIcon(hInstance, MAKEINTRESOURCE(DIVISION));
    if (div == NULL) {
        MessageBox(hWnd, L"Image failed to load", L"Error", 1);
    }
    SendMessage(h_Division, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)div);
    HWND h_Left_Panthses = CreateWindow(L"BUTTON", L"", dwStyle, 572.5, 202.2, 96.5, 72.5, hWnd, NULL, hInstance, NULL);

    //third row

    HWND a = CreateWindow(L"BUTTON", L"", dwStyle, 15, 290, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //4
    HWND h_Four = CreateWindow(L"BUTTON", L"4", dwStyle, 126.5, 290, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //5
    HWND h_Five = CreateWindow(L"BUTTON", L"5", dwStyle, 238, 290, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //6
    HWND h_Six = CreateWindow(L"BUTTON", L"6", dwStyle, 349.5, 290, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    
    HWND h_Mutiplication = CreateWindow(L"BUTTON", L"", dwStyleBMP, 461, 290, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    HICON mult = LoadIcon(hInstance, MAKEINTRESOURCE(MULTIPLICATION));
    if (mult == NULL) {
        MessageBox(hWnd, L"Image failed to load", L"Error", 1);
    }
    SendMessage(h_Mutiplication, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)mult);
    HWND f = CreateWindow(L"BUTTON", L"", dwStyle, 572.5, 290, 96.5, 72.5, hWnd, NULL, hInstance, NULL);

    //fourth row

    HWND g = CreateWindow(L"BUTTON", L"", dwStyle, 15, 377.5, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //1
    HWND h_One = CreateWindow(L"BUTTON", L"1", dwStyle, 126.5, 377.5, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //2
    HWND h_Two = CreateWindow(L"BUTTON", L"2", dwStyle, 238, 377.5, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //3
    HWND h_Three = CreateWindow(L"BUTTON", L"3", dwStyle, 349.5, 377.5, 96.5, 72.5, hWnd, NULL, hInstance, NULL);

    HWND h_Subtraction = CreateWindow(L"BUTTON", L"", dwStyleBMP, 461, 377.5, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    HICON sub = LoadIcon(hInstance, MAKEINTRESOURCE(SUBTRACTION));
    if (sub == NULL) {
        MessageBox(hWnd, L"Image failed to load", L"Error", 1);
    }
    SendMessage(h_Subtraction, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)sub);
    HWND l = CreateWindow(L"BUTTON", L"", dwStyle, 572.5, 377.5, 96.5, 72.5, hWnd, NULL, hInstance, NULL);

    //fifth row

    HWND m = CreateWindow(L"BUTTON", L"", dwStyle, 15, 465, 96.5, 72.5, hWnd, NULL, hInstance, NULL);

    HWND n = CreateWindow(L"BUTTON", L"", dwStyle, 126.5, 465, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    //0
    HWND h_Zero = CreateWindow(L"BUTTON", L"0", dwStyle, 238, 465, 96.5, 72.5, hWnd, NULL, hInstance, NULL);

    HWND p = CreateWindow(L"BUTTON", L"", dwStyle, 349.5, 465, 96.5, 72.5, hWnd, NULL, hInstance, NULL);

    HWND h_Addition = CreateWindow(L"BUTTON", L"", dwStyleBMP, 461, 465, 96.5, 72.5, hWnd, NULL, hInstance, NULL);
    HICON add = LoadIcon(hInstance, MAKEINTRESOURCE(ADDITION));
    if (add == NULL) {
        MessageBox(hWnd, L"Image failed to load", L"Error", 1);
    }
    SendMessage(h_Addition, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)add);
    HWND r = CreateWindow(L"BUTTON", L"", dwStyle, 572.5, 465, 96.5, 72.5, hWnd, NULL, hInstance, NULL);

    //sixth row
    HWND s = CreateWindow(L"BUTTON", L"", dwStyle, 15, 552.5, 152.25, 72.5, hWnd, NULL, hInstance, NULL);

    HWND t = CreateWindow(L"BUTTON", L"", dwStyle, 182.25, 552.5, 152.25, 72.5, hWnd, NULL, hInstance, NULL);

    HWND u = CreateWindow(L"BUTTON", L"", dwStyle, 349.5, 552.5, 152.25, 72.5, hWnd, NULL, hInstance, NULL);

    HWND v = CreateWindow(L"BUTTON", L"", dwStyle, 516.75, 552.5, 152.25, 72.5, hWnd, NULL, hInstance, NULL);
}



