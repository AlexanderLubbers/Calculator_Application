#pragma once
#include "Windows.h"
#include "resource.h"

//HMENU constants for the buttons
#define LEFT_PARENTHESES_PRESSED 301
#define RIGHT_PARENTHESES_PRESSED 302
#define DECIMAL_PRESSED 303
#define NEGATIVE_PRESSED 304
#define HISTORY_PRESSED 305
#define CLEAR_PRESSED 306
#define SQROOT_PRESSED 307

class AddButtons {
public:
	void button(HWND hWnd);
};

