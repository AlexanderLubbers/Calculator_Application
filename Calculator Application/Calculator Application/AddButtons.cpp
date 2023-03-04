#include "AddButtons.h"
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"") 

void AddButtons::button(HWND hWnd)
{
    DWORD dwStyle = WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON;
    DWORD dwStyleBMP = WS_VISIBLE | WS_CHILD | BS_BITMAP | BS_PUSHBUTTON;
    HINSTANCE hInstance = GetModuleHandle(NULL);

    //first row
    //(
    HWND h_Left_Parentheses = CreateWindow(L"BUTTON", L"(", dwStyle, 15, 115, 96.5, 72.5, hWnd, (HMENU)LEFT_PARENTHESES_PRESSED, NULL, NULL);
    //)
    HWND h_Right_Parantheses = CreateWindow(L"BUTTON", L")", dwStyle, 126.5, 115, 96.5, 72.5, hWnd, (HMENU)RIGHT_PARENTHESES_PRESSED, NULL, NULL);
    //.
    HWND h_Decimal_Point = CreateWindow(L"BUTTON", L".", dwStyle, 238, 115, 96.5, 72.5, hWnd, (HMENU)DECIMAL_PRESSED, NULL, NULL);
    //-
    HWND h_Negative_Symbol = CreateWindow(L"BUTTON", L"-", dwStyle, 349.5, 115, 96.5, 72.5, hWnd, (HMENU)NEGATIVE_PRESSED, NULL, NULL);
    //history button
    HWND h_History = CreateWindow(L"BUTTON", L"History", dwStyle, 461, 115, 96.5, 72.5, hWnd, (HMENU)HISTORY_PRESSED, NULL, NULL);
    //history clear
    HWND h_Clear = CreateWindow(L"BUTTON", L"Clear", dwStyle, 572.5, 115, 96.5, 72.5, hWnd, (HMENU)CLEAR_PRESSED, NULL, NULL);
    //second row
    //uploading the radical symbol onto a button
    HWND h_Sqroot = CreateWindowEx(NULL, L"BUTTON", NULL, dwStyleBMP, 15, 202.5, 96.5, 72.5, hWnd, (HMENU)SQROOT_PRESSED, NULL, NULL);
    HICON Sqroot_bit = LoadIcon(hInstance, MAKEINTRESOURCE(SQROOT));
    if (Sqroot_bit == NULL) {
        MessageBox(hWnd, L"Image failed to load", L"Error", 1);
    }
    SendMessage(h_Sqroot, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)Sqroot_bit);
    //7
    HWND h_Seven = CreateWindow(L"BUTTON", L"7", dwStyle, 126.5, 202.5, 96.5, 72.5, hWnd, (HMENU)SEVEN_PRESSED, NULL, NULL);
    //8
    HWND h_Eight = CreateWindow(L"BUTTON", L"8", dwStyle, 238, 202.5, 96.5, 72.5, hWnd, (HMENU)EIGHT_PRESSED, NULL, NULL);
    //9
    HWND h_Nine = CreateWindow(L"BUTTON", L"9", dwStyle, 349.5, 202.5, 96.5, 72.5, hWnd, (HMENU)NINE_PRESSED, NULL, NULL);
    //division sign
    HWND h_Division = CreateWindow(L"BUTTON", L"÷", dwStyle, 461, 202.5, 96.5, 72.5, hWnd, (HMENU)DIVIDE_PRESSED, NULL, NULL);
    HWND h_Division_Handle = GetDlgItem(hWnd, DIVIDE_PRESSED);
    // Create a new font with a larger size
    HFONT hFontDiv = CreateFont(32, 10, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");

    // Send the WM_SETFONT message to the button control with the new font
    SendMessage(h_Division_Handle, WM_SETFONT, (WPARAM)hFontDiv, TRUE);
    HWND h_Pi = CreateWindow(L"BUTTON", L"pi", dwStyle, 572.5, 202.2, 96.5, 72.5, hWnd, (HMENU)PI_PRESSED, NULL, NULL);
    //third row
    HWND h_Exponent = CreateWindow(L"BUTTON", L"^", dwStyle, 15, 290, 96.5, 72.5, hWnd, (HMENU)EXPONENT_PRESSED, NULL, NULL);
    HWND h_Exponent_Handle = GetDlgItem(hWnd, EXPONENT_PRESSED);
    // Create a new font with a larger size
    HFONT hFontEx = CreateFont(25, 10, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");

    // Send the WM_SETFONT message to the button control with the new font
    SendMessage(h_Exponent_Handle, WM_SETFONT, (WPARAM)hFontEx, TRUE);
    //4
    HWND h_Four = CreateWindow(L"BUTTON", L"4", dwStyle, 126.5, 290, 96.5, 72.5, hWnd, (HMENU)FOUR_PRESSED, NULL, NULL);
    //5
    HWND h_Five = CreateWindow(L"BUTTON", L"5", dwStyle, 238, 290, 96.5, 72.5, hWnd, (HMENU)FIVE_PRESSED, NULL, NULL);
    //6
    HWND h_Six = CreateWindow(L"BUTTON", L"6", dwStyle, 349.5, 290, 96.5, 72.5, hWnd, (HMENU)SIX_PRESSESD, NULL, NULL);
    
    HWND h_Mutiplication = CreateWindow(L"BUTTON", L"X", dwStyleBMP, 461, 290, 96.5, 72.5, hWnd, (HMENU)MULTIPLY_PRESSED, NULL, NULL);
    
    //Sine
    HWND h_Sin = CreateWindow(L"BUTTON", L"sin", dwStyle, 572.5, 290, 96.5, 72.5, hWnd, (HMENU)SINE_PRESSED, NULL, NULL);

    //fourth row

    HWND h_E = CreateWindow(L"BUTTON", L"E", dwStyle, 15, 377.5, 96.5, 72.5, hWnd, (HMENU)E_PRESSED, NULL, NULL);
    //1
    HWND h_One = CreateWindow(L"BUTTON", L"1", dwStyle, 126.5, 377.5, 96.5, 72.5, hWnd, (HMENU)ONE_PRESSED, NULL, NULL);
    //2
    HWND h_Two = CreateWindow(L"BUTTON", L"2", dwStyle, 238, 377.5, 96.5, 72.5, hWnd, (HMENU)TWO_PRESSED, NULL, NULL);
    //3
    HWND h_Three = CreateWindow(L"BUTTON", L"3", dwStyle, 349.5, 377.5, 96.5, 72.5, hWnd, (HMENU)THREE_PRESSED, NULL, NULL);

    HWND h_Subtraction = CreateWindow(L"BUTTON", L"--", dwStyle, 461, 377.5, 96.5, 72.5, hWnd, (HMENU)SUBTRACT_PRESSED, NULL, NULL);
    HWND h_Subtraction_Handle = GetDlgItem(hWnd, SUBTRACT_PRESSED);
    // Create a new font with a larger size
    HFONT hFontSub = CreateFont(25, 10, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");

    // Send the WM_SETFONT message to the button control with the new font
    SendMessage(h_Subtraction_Handle, WM_SETFONT, (WPARAM)hFontSub, TRUE);
    //cosine
    HWND h_Cos = CreateWindow(L"BUTTON", L"cos", dwStyle, 572.5, 377.5, 96.5, 72.5, hWnd, (HMENU)COSINE_PRESSED, NULL, NULL);

    //fifth row

    HWND h_Log = CreateWindow(L"BUTTON", L"Log", dwStyle, 15, 465, 96.5, 72.5, hWnd, (HMENU)LOG_PRESSED, NULL, NULL);

    HWND h_LogBASE = CreateWindow(L"BUTTON", L"LogBASE", dwStyle, 126.5, 465, 96.5, 72.5, hWnd, (HMENU)LOGBASE_PRESSED, NULL, NULL);
    //0
    HWND h_Zero = CreateWindow(L"BUTTON", L"0", dwStyle, 238, 465, 96.5, 72.5, hWnd, (HMENU)ZERO_PRESSED, NULL, NULL);

    HWND h_Comma = CreateWindow(L"BUTTON", L",", dwStyle, 349.5, 465, 96.5, 72.5, hWnd, (HMENU)COMMA_PRESSED, NULL, NULL);

    HWND h_Addition = CreateWindow(L"BUTTON", L"+", dwStyle, 461, 465, 96.5, 72.5, hWnd, (HMENU)ADD_PRESSED, NULL, NULL);
    HWND h_Addition_Handle = GetDlgItem(hWnd, ADD_PRESSED);
    // Create a new font
    HFONT hFontAddition = CreateFont(25, 10, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");

    // Send the WM_SETFONT message to the button control with the new font
    SendMessage(h_Addition_Handle, WM_SETFONT, (WPARAM)hFontAddition, TRUE);
    //tangent
    HWND h_Tan = CreateWindow(L"BUTTON", L"tan", dwStyle, 572.5, 465, 96.5, 72.5, hWnd, (HMENU)TANGENT_PRESSED, NULL, NULL);

    //sixth row
    //inverse Sine
    HWND h_Sininv = CreateWindow(L"BUTTON", L"", dwStyleBMP, 15, 552.5, 152.25, 72.5, hWnd, (HMENU)INVERSE_SINE_PRESSED, NULL, NULL);
    HICON invsin = LoadIcon(hInstance, MAKEINTRESOURCE(SININV));
    if (invsin == NULL) {
        MessageBox(hWnd, L"Image failed to load", L"Error", 1);
    }
    SendMessage(h_Sininv, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)invsin);
    //inverse Cosine
    HWND h_Cosinv = CreateWindow(L"BUTTON", L"", dwStyleBMP, 182.25, 552.5, 152.25, 72.5, hWnd, (HMENU)INVERSE_COSINE_PRESSED, NULL, NULL);
    HICON invcos = LoadIcon(hInstance, MAKEINTRESOURCE(COSINV));
    if (invcos == NULL) {
        MessageBox(hWnd, L"Image failed to load", L"Error", 1);
    }
    SendMessage(h_Cosinv, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)invcos);
    //inverse Tangent
    HWND h_Taninv = CreateWindow(L"BUTTON", L"", dwStyleBMP, 349.5, 552.5, 152.25, 72.5, hWnd, (HMENU)INVERSE_TANGENT_PRESSED, NULL, NULL);
    HICON invtan = LoadIcon(hInstance, MAKEINTRESOURCE(TANINV));
    if (invtan == NULL) {
        MessageBox(hWnd, L"Image failed to load", L"Error", 1);
    }
    SendMessage(h_Taninv, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)invtan);
    HWND h_Radical = CreateWindow(L"BUTTON", L"", dwStyleBMP, 516.75, 552.5, 152.25, 72.5, hWnd, (HMENU)RADICAL_PRESSED, NULL, NULL);
    HICON radical = LoadIcon(hInstance, MAKEINTRESOURCE(RADICAL));
    if (radical == NULL)
    {
        MessageBox(hWnd, L"Image failed to load", L"Error", 1);
    }
    SendMessage(h_Radical, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)radical);
}



