#include "AddButtons.h"
#include <CommCtrl.h>
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"") 


void AddButtons::button(HWND hWnd)
{
    DWORD dwStyle = WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON;
    DWORD dwStyleBMP = WS_VISIBLE | WS_CHILD | BS_BITMAP | BS_PUSHBUTTON;
    HINSTANCE hInstance = GetModuleHandle(NULL);
    UINT Tool_Tip_Flag = TTF_IDISHWND | TTF_SUBCLASS;

    //first row
    //(
    HWND h_Left_Parentheses = CreateWindow(L"BUTTON", L"(", dwStyle, 15, 115, 96.5, 72.5, hWnd, (HMENU)LEFT_PARENTHESES_PRESSED, NULL, NULL);

    //tooltip control for the left parentheses button
    HWND hToolTipLeftP = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO toolInfo = { 0 };
    toolInfo.cbSize = sizeof(toolInfo);
    toolInfo.hwnd = hWnd; // Handle to the parent window
    toolInfo.uFlags = Tool_Tip_Flag;
    toolInfo.uId = (UINT_PTR)h_Left_Parentheses; // Handle to the control to associate the ToolTip with
    toolInfo.lpszText = (LPWSTR)(L"(");
    SendMessage(hToolTipLeftP, TTM_ADDTOOL, 0, (LPARAM)&toolInfo);

    SendMessage(hToolTipLeftP, TTM_SETMAXTIPWIDTH, 0, 500); // Set the maximum width of the ToolTip to 200 pixels
    SendMessage(hToolTipLeftP, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500)); // Set the initial delay time to 500 milliseconds
    SendMessage(hToolTipLeftP, TTM_SETTITLE, TTI_INFO, (LPARAM)L"("); // Set the title of the ToolTip
    //)
    HWND h_Right_Parantheses = CreateWindow(L"BUTTON", L")", dwStyle, 126.5, 115, 96.5, 72.5, hWnd, (HMENU)RIGHT_PARENTHESES_PRESSED, NULL, NULL);

    //tooltip for the right parentheses button
    HWND hToolTipRightP = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO RightPToolTipInfo = { 0 };
    RightPToolTipInfo.cbSize = sizeof(RightPToolTipInfo);
    RightPToolTipInfo.hwnd = hWnd;
    RightPToolTipInfo.uFlags = Tool_Tip_Flag;
    RightPToolTipInfo.uId = (UINT_PTR)h_Right_Parantheses;
    RightPToolTipInfo.lpszText = (LPWSTR)(L")");
    SendMessage(hToolTipRightP, TTM_ADDTOOL, 0, (LPARAM)&RightPToolTipInfo);

    SendMessage(hToolTipRightP, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipRightP, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipRightP, TTM_SETTITLE, TTI_INFO, (LPARAM)(L")"));
    //.
    HWND h_Decimal_Point = CreateWindow(L"BUTTON", L".", dwStyle, 238, 115, 96.5, 72.5, hWnd, (HMENU)DECIMAL_PRESSED, NULL, NULL);
    
    //tool tip control for the decimal button
    HWND hToolTipDecimal = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO DecimalToolTipInfo = { 0 };
    DecimalToolTipInfo.cbSize = sizeof(DecimalToolTipInfo);
    DecimalToolTipInfo.hwnd = hWnd;
    DecimalToolTipInfo.uFlags = Tool_Tip_Flag;
    DecimalToolTipInfo.uId = (UINT_PTR)(h_Decimal_Point);
    DecimalToolTipInfo.lpszText = (LPWSTR)(L".");
    SendMessage(hToolTipDecimal, TTM_ADDTOOL, 0, (LPARAM)&DecimalToolTipInfo);

    SendMessage(hToolTipDecimal, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipDecimal, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipDecimal, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"."));
    //-
    HWND h_Negative_Symbol = CreateWindow(L"BUTTON", L"-", dwStyle, 349.5, 115, 96.5, 72.5, hWnd, (HMENU)NEGATIVE_PRESSED, NULL, NULL);

    //tooltip control for the negative button
    HWND hToolTipNegative = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO NegativeToolTipInfo = { 0 };
    NegativeToolTipInfo.cbSize = sizeof(NegativeToolTipInfo);
    NegativeToolTipInfo.hwnd = hWnd;
    NegativeToolTipInfo.uFlags = Tool_Tip_Flag;
    NegativeToolTipInfo.uId = (UINT_PTR)h_Negative_Symbol;
    NegativeToolTipInfo.lpszText = (LPWSTR)(L"-");
    SendMessage(hToolTipNegative, TTM_ADDTOOL, 0, (LPARAM)&NegativeToolTipInfo);

    SendMessage(hToolTipNegative, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipNegative, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipNegative, TTM_SETTITLE, TTI_INFO, LPARAM(L"-"));
    //history button
    HWND h_History = CreateWindow(L"BUTTON", L"History", dwStyle, 461, 115, 96.5, 72.5, hWnd, (HMENU)HISTORY_PRESSED, NULL, NULL);

    //tooltip for the history button
    HWND hToolTipHistory = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO HistoryToolTipInfo = { 0 };
    HistoryToolTipInfo.cbSize = sizeof(HistoryToolTipInfo);
    HistoryToolTipInfo.hwnd = hWnd;
    HistoryToolTipInfo.uFlags = Tool_Tip_Flag;
    HistoryToolTipInfo.uId = (UINT_PTR)h_History;
    HistoryToolTipInfo.lpszText = (LPWSTR)(L"Click this button to view past equations and answers");
    SendMessage(hToolTipHistory, TTM_ADDTOOL, 0, (LPARAM)&HistoryToolTipInfo);

    SendMessage(hToolTipHistory, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipHistory, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipHistory, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"History"));

    //history clear
    HWND h_Clear = CreateWindow(L"BUTTON", L"Clear", dwStyle, 572.5, 115, 96.5, 72.5, hWnd, (HMENU)CLEAR_PRESSED, NULL, NULL);
    
    //tool tip for the clear button
    HWND hToolTipClear = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO ClearToolTipInfo = { 0 };
    ClearToolTipInfo.cbSize = sizeof(ClearToolTipInfo);
    ClearToolTipInfo.hwnd = hWnd;
    ClearToolTipInfo.uFlags = Tool_Tip_Flag;
    ClearToolTipInfo.uId = (UINT_PTR)h_Clear;
    ClearToolTipInfo.lpszText = (LPWSTR)(L"Click this button to view clear the equation");
    SendMessage(hToolTipClear, TTM_ADDTOOL, 0, (LPARAM)&ClearToolTipInfo);

    SendMessage(hToolTipClear, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipClear, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipClear, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"Clear"));

    //second row
    //uploading the radical symbol onto a button
    HWND h_Sqroot = CreateWindowEx(NULL, L"BUTTON", NULL, dwStyleBMP, 15, 202.5, 96.5, 72.5, hWnd, (HMENU)SQROOT_PRESSED, NULL, NULL);
    HICON Sqroot_bit = LoadIcon(hInstance, MAKEINTRESOURCE(SQROOT));
    if (Sqroot_bit == NULL) {
        MessageBox(hWnd, L"Image failed to load", L"Error", 1);
    }
    SendMessage(h_Sqroot, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)Sqroot_bit);

    //tool tip control for the square root button
    HWND hToolTipSqroot = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO SqrootToolTipInfo = { 0 };
    SqrootToolTipInfo.cbSize = sizeof(SqrootToolTipInfo);
    SqrootToolTipInfo.hwnd = hWnd;
    SqrootToolTipInfo.uFlags = Tool_Tip_Flag;
    SqrootToolTipInfo.uId = (UINT_PTR)h_Sqroot;
    SqrootToolTipInfo.lpszText = (LPWSTR)(L"rad(index, radicand)");
    SendMessage(hToolTipSqroot, TTM_ADDTOOL, 0, (LPARAM)&SqrootToolTipInfo);

    SendMessage(hToolTipSqroot, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipSqroot, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipSqroot, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"radical"));
    //7
    HWND h_Seven = CreateWindow(L"BUTTON", L"7", dwStyle, 126.5, 202.5, 96.5, 72.5, hWnd, (HMENU)SEVEN_PRESSED, NULL, NULL);

    //tool tip control for the 7 button
    HWND hToolTipSeven = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO SevenToolTipInfo = { 0 };
    SevenToolTipInfo.cbSize = sizeof(SevenToolTipInfo);
    SevenToolTipInfo.hwnd = hWnd;
    SevenToolTipInfo.uFlags = Tool_Tip_Flag;
    SevenToolTipInfo.uId = (UINT_PTR)h_Seven;
    SevenToolTipInfo.lpszText = (LPWSTR)(L"7");
    SendMessage(hToolTipSeven, TTM_ADDTOOL, 0, (LPARAM)&SevenToolTipInfo);

    SendMessage(hToolTipSeven, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipSeven, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipSeven, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"7"));

    //8
    HWND h_Eight = CreateWindow(L"BUTTON", L"8", dwStyle, 238, 202.5, 96.5, 72.5, hWnd, (HMENU)EIGHT_PRESSED, NULL, NULL);

    //tool tip control for the 8 button
    HWND hToolTipEight = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO EightToolTipInfo = { 0 };
    EightToolTipInfo.cbSize = sizeof(EightToolTipInfo);
    EightToolTipInfo.hwnd = hWnd;
    EightToolTipInfo.uFlags = Tool_Tip_Flag;
    EightToolTipInfo.uId = (UINT_PTR)h_Eight;
    EightToolTipInfo.lpszText = (LPWSTR)(L"8");
    SendMessage(hToolTipEight, TTM_ADDTOOL, 0, (LPARAM)&EightToolTipInfo);

    SendMessage(hToolTipEight, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipEight, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipEight, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"8"));
    //9
    HWND h_Nine = CreateWindow(L"BUTTON", L"9", dwStyle, 349.5, 202.5, 96.5, 72.5, hWnd, (HMENU)NINE_PRESSED, NULL, NULL);

    //tool tip control for the 9 button
    HWND hToolTipNine = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO NineToolTipInfo = { 0 };
    NineToolTipInfo.cbSize = sizeof(NineToolTipInfo);
    NineToolTipInfo.hwnd = hWnd;
    NineToolTipInfo.uFlags = Tool_Tip_Flag;
    NineToolTipInfo.uId = (UINT_PTR)h_Nine;
    NineToolTipInfo.lpszText = (LPWSTR)(L"9");
    SendMessage(hToolTipNine, TTM_ADDTOOL, 0, (LPARAM)&NineToolTipInfo);

    SendMessage(hToolTipNine, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipNine, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipNine, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"9"));
    //division sign
    HWND h_Division = CreateWindow(L"BUTTON", L"÷", dwStyle, 461, 202.5, 96.5, 72.5, hWnd, (HMENU)DIVIDE_PRESSED, NULL, NULL);
    // Create a new font with a larger size
    HFONT hFontDiv = CreateFont(32, 10, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");

    // Send the WM_SETFONT message to the button control with the new font
    SendMessage(h_Division, WM_SETFONT, (WPARAM)hFontDiv, TRUE);

    //tool tip control of the division button
    HWND hToolTipDivision = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO DivisionToolTipInfo = { 0 };
    DivisionToolTipInfo.cbSize = sizeof(DivisionToolTipInfo);
    DivisionToolTipInfo.hwnd = hWnd;
    DivisionToolTipInfo.uFlags = Tool_Tip_Flag;
    DivisionToolTipInfo.uId = (UINT_PTR)h_Division;
    DivisionToolTipInfo.lpszText = (LPWSTR)(L"x / y");
    SendMessage(hToolTipDivision, TTM_ADDTOOL, 0, (LPARAM)&DivisionToolTipInfo);

    SendMessage(hToolTipDivision, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipDivision, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipDivision, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"/"));

    HWND h_Pi = CreateWindow(L"BUTTON", L"pi", dwStyle, 572.5, 202.2, 96.5, 72.5, hWnd, (HMENU)PI_PRESSED, NULL, NULL);

    //tool tip control for the pi button
    HWND hToolTipPi = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO PiToolTipInfo = { 0 };
    PiToolTipInfo.cbSize = sizeof(PiToolTipInfo);
    PiToolTipInfo.hwnd = hWnd;
    PiToolTipInfo.uFlags = Tool_Tip_Flag;
    PiToolTipInfo.uId = (UINT_PTR)h_Pi;
    PiToolTipInfo.lpszText = (LPWSTR)(L"3.14");
    SendMessage(hToolTipPi, TTM_ADDTOOL, 0, (LPARAM)&PiToolTipInfo);

    SendMessage(hToolTipPi, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipPi, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipPi, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"pi"));
    //third row
    HWND h_Exponent = CreateWindow(L"BUTTON", L"^", dwStyle, 15, 290, 96.5, 72.5, hWnd, (HMENU)EXPONENT_PRESSED, NULL, NULL);
    // Create a new font with a larger size
    HFONT hFontEx = CreateFont(25, 10, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");

    // Send the WM_SETFONT message to the button control with the new font
    SendMessage(h_Exponent, WM_SETFONT, (WPARAM)hFontEx, TRUE);

    //tool tip control for the exponenet button
    HWND hToolTipExponent = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO ExponentToolTipInfo = { 0 };
    ExponentToolTipInfo.cbSize = sizeof(ExponentToolTipInfo);
    ExponentToolTipInfo.hwnd = hWnd;
    ExponentToolTipInfo.uFlags = Tool_Tip_Flag;
    ExponentToolTipInfo.uId = (UINT_PTR)h_Exponent;
    ExponentToolTipInfo.lpszText = (LPWSTR)(L"pow(base, exponent)");
    SendMessage(hToolTipExponent, TTM_ADDTOOL, 0, (LPARAM)&ExponentToolTipInfo);

    SendMessage(hToolTipExponent, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipExponent, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipExponent, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"pow()"));

    //4
    HWND h_Four = CreateWindow(L"BUTTON", L"4", dwStyle, 126.5, 290, 96.5, 72.5, hWnd, (HMENU)FOUR_PRESSED, NULL, NULL);

    //tool tip control for the four button
    HWND hToolTipFour = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO FourToolTipInfo = { 0 };
    FourToolTipInfo.cbSize = sizeof(FourToolTipInfo);
    FourToolTipInfo.hwnd = hWnd;
    FourToolTipInfo.uFlags = Tool_Tip_Flag;
    FourToolTipInfo.uId = (UINT_PTR)h_Four;
    FourToolTipInfo.lpszText = (LPWSTR)(L"4");
    SendMessage(hToolTipFour, TTM_ADDTOOL, 0, (LPARAM)&FourToolTipInfo);

    SendMessage(hToolTipFour, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipFour, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipFour, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"4"));
    //5
    HWND h_Five = CreateWindow(L"BUTTON", L"5", dwStyle, 238, 290, 96.5, 72.5, hWnd, (HMENU)FIVE_PRESSED, NULL, NULL);

    //tool tip control for the five button
    HWND hToolTipFive = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO FiveToolTipInfo = { 0 };
    FiveToolTipInfo.cbSize = sizeof(FiveToolTipInfo);
    FiveToolTipInfo.hwnd = hWnd;
    FiveToolTipInfo.uFlags = Tool_Tip_Flag;
    FiveToolTipInfo.uId = (UINT_PTR)h_Five;
    FiveToolTipInfo.lpszText = (LPWSTR)(L"5");
    SendMessage(hToolTipFive, TTM_ADDTOOL, 0, (LPARAM)&FiveToolTipInfo);

    SendMessage(hToolTipFive, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipFive, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipFive, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"5"));
    //6
    HWND h_Six = CreateWindow(L"BUTTON", L"6", dwStyle, 349.5, 290, 96.5, 72.5, hWnd, (HMENU)SIX_PRESSESD, NULL, NULL);

    //tool tip control for the six button
    HWND hToolTipSix = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO SixToolTipInfo = { 0 };
    SixToolTipInfo.cbSize = sizeof(SixToolTipInfo);
    SixToolTipInfo.hwnd = hWnd;
    SixToolTipInfo.uFlags = Tool_Tip_Flag;
    SixToolTipInfo.uId = (UINT_PTR)h_Six;
    SixToolTipInfo.lpszText = (LPWSTR)(L"6");
    SendMessage(hToolTipSix, TTM_ADDTOOL, 0, (LPARAM)&SixToolTipInfo);

    SendMessage(hToolTipSix, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipSix, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipSix, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"6"));
    
    HWND h_Mutiplication = CreateWindow(L"BUTTON", L"X", dwStyleBMP, 461, 290, 96.5, 72.5, hWnd, (HMENU)MULTIPLY_PRESSED, NULL, NULL);

    //tool tip control for the multiplcation button
    HWND hToolTipMult = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO MultToolTipInfo = { 0 };
    MultToolTipInfo.cbSize = sizeof(MultToolTipInfo);
    MultToolTipInfo.hwnd = hWnd;
    MultToolTipInfo.uFlags = Tool_Tip_Flag;
    MultToolTipInfo.uId = (UINT_PTR)h_Mutiplication;
    MultToolTipInfo.lpszText = (LPWSTR)(L"x * y");
    SendMessage(hToolTipMult, TTM_ADDTOOL, 0, (LPARAM)&MultToolTipInfo);

    SendMessage(hToolTipMult, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipMult, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipMult, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"*"));
    
    //Sine
    HWND h_Sin = CreateWindow(L"BUTTON", L"sin", dwStyle, 572.5, 290, 96.5, 72.5, hWnd, (HMENU)SINE_PRESSED, NULL, NULL);

    HWND hToolTipSin = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    //tool tip control for the sine button
    TOOLINFO SinToolTipInfo = { 0 };
    SinToolTipInfo.cbSize = sizeof(SinToolTipInfo);
    SinToolTipInfo.hwnd = hWnd;
    SinToolTipInfo.uFlags = Tool_Tip_Flag;
    SinToolTipInfo.uId = (UINT_PTR)h_Sin;
    SinToolTipInfo.lpszText = (LPWSTR)(L"Sin(radians)");
    SendMessage(hToolTipSin, TTM_ADDTOOL, 0, (LPARAM)&SinToolTipInfo);

    SendMessage(hToolTipSin, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipSin, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipSin, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"Sin()"));

    //fourth row

    HWND h_Abs = CreateWindow(L"BUTTON", L"abs", dwStyle, 15, 377.5, 96.5, 72.5, hWnd, (HMENU)ABS_PRESSED, NULL, NULL);

    HWND hToolTipAbs = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    //tool tip control for the e button
    TOOLINFO AbsToolTipInfo = { 0 };
    AbsToolTipInfo.cbSize = sizeof(AbsToolTipInfo);
    AbsToolTipInfo.hwnd = hWnd;
    AbsToolTipInfo.uFlags = Tool_Tip_Flag;
    AbsToolTipInfo.uId = (UINT_PTR)h_Abs;
    AbsToolTipInfo.lpszText = (LPWSTR)(L"abs(-23) -> 23");
    SendMessage(hToolTipAbs, TTM_ADDTOOL, 0, (LPARAM)&AbsToolTipInfo);

    SendMessage(hToolTipAbs, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipAbs, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipAbs, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"Abs()"));
    //1
    HWND h_One = CreateWindow(L"BUTTON", L"1", dwStyle, 126.5, 377.5, 96.5, 72.5, hWnd, (HMENU)ONE_PRESSED, NULL, NULL);

    //tool tip control for the One button
    HWND hToolTipOne = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO OneToolTipInfo = { 0 };
    OneToolTipInfo.cbSize = sizeof(OneToolTipInfo);
    OneToolTipInfo.hwnd = hWnd;
    OneToolTipInfo.uFlags = Tool_Tip_Flag;
    OneToolTipInfo.uId = (UINT_PTR)h_One;
    OneToolTipInfo.lpszText = (LPWSTR)(L"1");
    SendMessage(hToolTipOne, TTM_ADDTOOL, 0, (LPARAM)&OneToolTipInfo);

    SendMessage(hToolTipOne, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipOne, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipOne, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"1"));
    //2
    HWND h_Two = CreateWindow(L"BUTTON", L"2", dwStyle, 238, 377.5, 96.5, 72.5, hWnd, (HMENU)TWO_PRESSED, NULL, NULL);
    //tool tip control for the two button
    HWND hToolTipTwo = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO TwoToolTipInfo = { 0 };
    TwoToolTipInfo.cbSize = sizeof(TwoToolTipInfo);
    TwoToolTipInfo.hwnd = hWnd;
    TwoToolTipInfo.uFlags = Tool_Tip_Flag;
    TwoToolTipInfo.uId = (UINT_PTR)h_Two;
    TwoToolTipInfo.lpszText = (LPWSTR)(L"2");
    SendMessage(hToolTipTwo, TTM_ADDTOOL, 0, (LPARAM)&TwoToolTipInfo);

    SendMessage(hToolTipTwo, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipTwo, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipTwo, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"2"));
    //3
    HWND h_Three = CreateWindow(L"BUTTON", L"3", dwStyle, 349.5, 377.5, 96.5, 72.5, hWnd, (HMENU)THREE_PRESSED, NULL, NULL);

    //tool tip control for the three button
    HWND hToolTipThree = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO ThreeToolTipInfo = { 0 };
    ThreeToolTipInfo.cbSize = sizeof(ThreeToolTipInfo);
    ThreeToolTipInfo.hwnd = hWnd;
    ThreeToolTipInfo.uFlags = Tool_Tip_Flag;
    ThreeToolTipInfo.uId = (UINT_PTR)h_Three;
    ThreeToolTipInfo.lpszText = (LPWSTR)(L"3");
    SendMessage(hToolTipThree, TTM_ADDTOOL, 0, (LPARAM)&ThreeToolTipInfo);

    SendMessage(hToolTipThree, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipThree, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipThree, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"3"));

    HWND h_Subtraction = CreateWindow(L"BUTTON", L"-", dwStyle, 461, 377.5, 96.5, 72.5, hWnd, (HMENU)SUBTRACT_PRESSED, NULL, NULL);
    // Create a new font with a larger size
    HFONT hFontSub = CreateFont(25, 10, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");

    // Send the WM_SETFONT message to the button control with the new font
    SendMessage(h_Subtraction, WM_SETFONT, (WPARAM)hFontSub, TRUE);


    //tool tip control for the Subtaction button
    HWND hToolTipSub = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO SubToolTipInfo = { 0 };
    SubToolTipInfo.cbSize = sizeof(SubToolTipInfo);
    SubToolTipInfo.hwnd = hWnd;
    SubToolTipInfo.uFlags = Tool_Tip_Flag;
    SubToolTipInfo.uId = (UINT_PTR)h_Subtraction;
    SubToolTipInfo.lpszText = (LPWSTR)(L"x - 7");
    SendMessage(hToolTipSub, TTM_ADDTOOL, 0, (LPARAM)&SubToolTipInfo);

    SendMessage(hToolTipSub, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipSub, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipSub, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"-"));


    //cosine
    HWND h_Cos = CreateWindow(L"BUTTON", L"cos", dwStyle, 572.5, 377.5, 96.5, 72.5, hWnd, (HMENU)COSINE_PRESSED, NULL, NULL);

    //tool tip control for the cos button
    HWND hToolTipCos = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO CosToolTipInfo = { 0 };
    CosToolTipInfo.cbSize = sizeof(CosToolTipInfo);
    CosToolTipInfo.hwnd = hWnd;
    CosToolTipInfo.uFlags = Tool_Tip_Flag;
    CosToolTipInfo.uId = (UINT_PTR)h_Cos;
    CosToolTipInfo.lpszText = (LPWSTR)(L"Cos(radians)");
    SendMessage(hToolTipCos, TTM_ADDTOOL, 0, (LPARAM)&CosToolTipInfo);

    SendMessage(hToolTipCos, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipCos, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipCos, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"Cos()"));

    //fifth row
    HWND h_Log = CreateWindow(L"BUTTON", L"log10", dwStyle, 15, 465, 96.5, 72.5, hWnd, (HMENU)LOG_PRESSED, NULL, NULL);

    //tool tip control for the Log button
    HWND hToolTipLog = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO LogToolTipInfo = { 0 };
    LogToolTipInfo.cbSize = sizeof(LogToolTipInfo);
    LogToolTipInfo.hwnd = hWnd;
    LogToolTipInfo.uFlags = Tool_Tip_Flag;
    LogToolTipInfo.uId = (UINT_PTR)h_Log;
    LogToolTipInfo.lpszText = (LPWSTR)(L"Log(x)");
    SendMessage(hToolTipLog, TTM_ADDTOOL, 0, (LPARAM)&LogToolTipInfo);

    SendMessage(hToolTipLog, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipLog, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipLog, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"Log()"));

    HWND h_LogBASE = CreateWindow(L"BUTTON", L"logBASE", dwStyle, 126.5, 465, 96.5, 72.5, hWnd, (HMENU)LOGBASE_PRESSED, NULL, NULL);

    //tool tip control for the LogBASE button
    HWND hToolTipLogB = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO LogBToolTipInfo = { 0 };
    LogBToolTipInfo.cbSize = sizeof(LogBToolTipInfo);
    LogBToolTipInfo.hwnd = hWnd;
    LogBToolTipInfo.uFlags = Tool_Tip_Flag;
    LogBToolTipInfo.uId = (UINT_PTR)h_LogBASE;
    LogBToolTipInfo.lpszText = (LPWSTR)(L"LogB(base, argument)");
    SendMessage(hToolTipLogB, TTM_ADDTOOL, 0, (LPARAM)&LogBToolTipInfo);

    SendMessage(hToolTipLogB, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipLogB, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipLogB, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"LogB()"));
    //0
    HWND h_Zero = CreateWindow(L"BUTTON", L"0", dwStyle, 238, 465, 96.5, 72.5, hWnd, (HMENU)ZERO_PRESSED, NULL, NULL);

    //tool tip control for the zero button
    HWND hToolTipZero = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO ZeroToolTipInfo = { 0 };
    ZeroToolTipInfo.cbSize = sizeof(ZeroToolTipInfo);
    ZeroToolTipInfo.hwnd = hWnd;
    ZeroToolTipInfo.uFlags = Tool_Tip_Flag;
    ZeroToolTipInfo.uId = (UINT_PTR)h_Zero;
    ZeroToolTipInfo.lpszText = (LPWSTR)(L"0");
    SendMessage(hToolTipZero, TTM_ADDTOOL, 0, (LPARAM)&ZeroToolTipInfo);

    SendMessage(hToolTipZero, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipZero, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipZero, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"0"));

    HWND h_Comma = CreateWindow(L"BUTTON", L",", dwStyle, 349.5, 465, 96.5, 72.5, hWnd, (HMENU)COMMA_PRESSED, NULL, NULL);

    //tool tip control for the comma button
    HWND hToolTipComma = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO CommaToolTipInfo = { 0 };
    CommaToolTipInfo.cbSize = sizeof(CommaToolTipInfo);
    CommaToolTipInfo.hwnd = hWnd;
    CommaToolTipInfo.uFlags = Tool_Tip_Flag;
    CommaToolTipInfo.uId = (UINT_PTR)h_Comma;
    CommaToolTipInfo.lpszText = (LPWSTR)(L",");
    SendMessage(hToolTipComma, TTM_ADDTOOL, 0, (LPARAM)&CommaToolTipInfo);

    SendMessage(hToolTipComma, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipComma, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipComma, TTM_SETTITLE, TTI_INFO, (LPARAM)(L","));

    HWND h_Addition = CreateWindow(L"BUTTON", L"+", dwStyle, 461, 465, 96.5, 72.5, hWnd, (HMENU)ADD_PRESSED, NULL, NULL);
    // Create a new font
    HFONT hFontAddition = CreateFont(25, 10, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");

    // Send the WM_SETFONT message to the button control with the new font
    SendMessage(h_Addition, WM_SETFONT, (WPARAM)hFontAddition, TRUE);

    //tool tip control for the addition button
    HWND hToolTipAdd = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO AddToolTipInfo = { 0 };
    AddToolTipInfo.cbSize = sizeof(AddToolTipInfo);
    AddToolTipInfo.hwnd = hWnd;
    AddToolTipInfo.uFlags = Tool_Tip_Flag;
    AddToolTipInfo.uId = (UINT_PTR)h_Addition;
    AddToolTipInfo.lpszText = (LPWSTR)(L"x + y");
    SendMessage(hToolTipAdd, TTM_ADDTOOL, 0, (LPARAM)&AddToolTipInfo);

    SendMessage(hToolTipAdd, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipAdd, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipAdd, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"+"));

    //tangent
    HWND h_Tan = CreateWindow(L"BUTTON", L"tan", dwStyle, 572.5, 465, 96.5, 72.5, hWnd, (HMENU)TANGENT_PRESSED, NULL, NULL);

    //tool tip control for the tan button
    HWND hToolTipTan = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO TanToolTipInfo = { 0 };
    TanToolTipInfo.cbSize = sizeof(TanToolTipInfo);
    TanToolTipInfo.hwnd = hWnd;
    TanToolTipInfo.uFlags = Tool_Tip_Flag;
    TanToolTipInfo.uId = (UINT_PTR)h_Tan;
    TanToolTipInfo.lpszText = (LPWSTR)(L"Tan(radians)");
    SendMessage(hToolTipTan, TTM_ADDTOOL, 0, (LPARAM)&TanToolTipInfo);

    SendMessage(hToolTipTan, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipTan, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipTan, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"Tan()"));

    //sixth row
    //inverse Sine
    HWND h_Sininv = CreateWindow(L"BUTTON", L"arc-sin", dwStyle, 15, 552.5, 152.25, 72.5, hWnd, (HMENU)INVERSE_SINE_PRESSED, NULL, NULL);

    //tool tip control for the inverse sine button
    HWND hToolTipISin = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO ISinToolTipInfo = { 0 };
    ISinToolTipInfo.cbSize = sizeof(ISinToolTipInfo);
    ISinToolTipInfo.hwnd = hWnd;
    ISinToolTipInfo.uFlags = Tool_Tip_Flag;
    ISinToolTipInfo.uId = (UINT_PTR)h_Sininv;
    ISinToolTipInfo.lpszText = (LPWSTR)(L"asin(x)");
    SendMessage(hToolTipISin, TTM_ADDTOOL, 0, (LPARAM)&ISinToolTipInfo);

    SendMessage(hToolTipISin, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipISin, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipISin, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"asin()"));

    //inverse Cosine
    HWND h_Cosinv = CreateWindow(L"BUTTON", L"arc-cos", dwStyle, 182.25, 552.5, 152.25, 72.5, hWnd, (HMENU)INVERSE_COSINE_PRESSED, NULL, NULL);

    //tool tip control for the inverse cosine button
    HWND hToolTipICos = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO ICosToolTipInfo = { 0 };
    ICosToolTipInfo.cbSize = sizeof(ICosToolTipInfo);
    ICosToolTipInfo.hwnd = hWnd;
    ICosToolTipInfo.uFlags = Tool_Tip_Flag;
    ICosToolTipInfo.uId = (UINT_PTR)h_Cosinv;
    ICosToolTipInfo.lpszText = (LPWSTR)(L"acos(x)");
    SendMessage(hToolTipICos, TTM_ADDTOOL, 0, (LPARAM)&ICosToolTipInfo);

    SendMessage(hToolTipICos, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipICos, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipICos, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"acos()"));

    //inverse Tangent
    HWND h_Taninv = CreateWindow(L"BUTTON", L"arc-tan", dwStyle, 349.5, 552.5, 152.25, 72.5, hWnd, (HMENU)INVERSE_TANGENT_PRESSED, NULL, NULL);

    //tool tip control for the inverse tangent button
    HWND hToolTipITan = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO ITanToolTipInfo = { 0 };
    ITanToolTipInfo.cbSize = sizeof(ITanToolTipInfo);
    ITanToolTipInfo.hwnd = hWnd;
    ITanToolTipInfo.uFlags = Tool_Tip_Flag;
    ITanToolTipInfo.uId = (UINT_PTR)h_Taninv;
    ITanToolTipInfo.lpszText = (LPWSTR)(L"atan(x)");
    SendMessage(hToolTipITan, TTM_ADDTOOL, 0, (LPARAM)&ITanToolTipInfo);

    SendMessage(hToolTipITan, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipITan, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipITan, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"atan()"));

    HWND h_Enter = CreateWindow(L"BUTTON", L"enter", dwStyle, 516.75, 552.5, 152.25, 72.5, hWnd, (HMENU)ENTER_PRESSED, NULL, NULL);

    //tool tip control for the Enter button
    HWND hToolTipEnter = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);

    TOOLINFO EnterToolTipInfo = { 0 };
    EnterToolTipInfo.cbSize = sizeof(EnterToolTipInfo);
    EnterToolTipInfo.hwnd = hWnd;
    EnterToolTipInfo.uFlags = Tool_Tip_Flag;
    EnterToolTipInfo.uId = (UINT_PTR)h_Enter;
    EnterToolTipInfo.lpszText = (LPWSTR)(L"Press this button to calculate the answer for the entered equation");
    SendMessage(hToolTipEnter, TTM_ADDTOOL, 0, (LPARAM)&EnterToolTipInfo);

    SendMessage(hToolTipEnter, TTM_SETMAXTIPWIDTH, 0, 500);
    SendMessage(hToolTipEnter, TTM_SETDELAYTIME, TTDT_INITIAL, MAKELPARAM(0, 500));
    SendMessage(hToolTipEnter, TTM_SETTITLE, TTI_INFO, (LPARAM)(L"Enter"));
}




