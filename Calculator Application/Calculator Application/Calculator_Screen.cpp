#include "Calculator_Screen.h"

int Calculator_Screen::Draw_Screen(std::string msg)
{
	//HWND Calculator_Screen = CreateWindowEx(NULL, L"STATIC", L"", )
	return 0;
}

int Calculator_Screen::Recieve_Message(int msg)
{
	std::string symbol = "";
	bool clear = false;
	switch (msg)
	{
	case 1:
		symbol = "(";
		break;
	case 2:
		symbol = ")";
		break;
	case 3:
		symbol = ".";
		break;
	case 4:
		symbol = "-";
		break;
	case 5:
		//add code to view history
		break;
	case 6:
		clear = true;
		break;
	case 7:
		symbol = "sqrt(";
		break;
	case 8:
		symbol = "7";
		break;
	case 9:
		symbol = "8";
		break;
	case 10:
		symbol = "9";
		break;
	case 11:
		symbol = "/";
		break;
	case 12:
		symbol = "pi";
		break;
	case 13:
		symbol = "^";
		break;
	case 14:
		symbol = "4";
		break;
	case 15:
		symbol = "5";
		break;
	case 16:
		symbol = "6";
		break;
	case 17:
		symbol = "x";
		break;
	case 18:
		symbol = "sin(";
		break;
	case 19:
		symbol = "e";
		break;
	case 20:
		symbol = "1";
		break;
	case 21:
		symbol = "2";
		break;
	case 22:
		symbol = "3";
		break;
	case 23:
		symbol = "--";
		break;
	case 24:
		symbol = "cos(";
		break;
	case 25:
		symbol = "log(";
		break;
	case 26:
		symbol = "logBASE(";
		break;
	case 27:
		symbol = "0";
		break;
	case 28:

		break;
	case 29:
		symbol = "+";
		break;
	case 30:
		symbol = "tan(";
		break;
	case 31:
		symbol = "arcsin(";
		break;
	case 32:
		symbol = "arccos(";
		break;
	case 33:
		symbol = "arctan(";
		break;
	case 34:

		break;
	}
	Calculator_Screen::Draw_Screen(symbol);
	return 0;
}
