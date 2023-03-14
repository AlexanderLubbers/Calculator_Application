#include "HandleCommand.h"

//constructor called upon initializing the class which is what this line of code is doing
Calculator_Screen s;

void HandleCommand::handle_command(HWND hWnd, WPARAM wParam)
{
    string screen_message = "";
    switch (wParam)
    {
    case MENU_HELP:
        MessageBox(hWnd, L"This is a Calculator application. Enter numbers in by clicking the buttons displaying that number and click the buttons with the operation you wish to perfrom in order to perform that operation on your number", L"Help", 1);
        break;
    case FILE_MENU_EXIT:
        DestroyWindow(hWnd);
        break;
    case LEFT_PARENTHESES_PRESSED:
        screen_message = "(";
        break;
    case RIGHT_PARENTHESES_PRESSED:
        screen_message = ")";
        break;
    case DECIMAL_PRESSED:
        screen_message = ".";
        break;
    case NEGATIVE_PRESSED:
        screen_message = "-";
        break;
    case HISTORY_PRESSED:
        screen_message = "";
        break;
    case CLEAR_PRESSED:
        screen_message = "";
        break;
    case SQROOT_PRESSED:
        screen_message = "sqrt(";
        break;
    case SEVEN_PRESSED:
        screen_message = "7";
        break;
    case EIGHT_PRESSED:
        screen_message = "8";
        break;
    case NINE_PRESSED:
        screen_message = "9";
        break;
    case DIVIDE_PRESSED:
        screen_message = "/";
        break;
    case PI_PRESSED:
        screen_message = "pi";
        break;
    case EXPONENT_PRESSED:
        screen_message = "^";
        break;
    case FOUR_PRESSED:
        screen_message = "4";
        break;
    case FIVE_PRESSED:
        screen_message = "5";
        break;
    case SIX_PRESSESD:
        screen_message = "6";
        break;
    case MULTIPLY_PRESSED:
        screen_message = "*";
        break;
    case SINE_PRESSED:
        screen_message = "sin(";
        break;
    case E_PRESSED:
        screen_message = "e";
        break;
    case ONE_PRESSED:
        screen_message = "1";
        break;
    case TWO_PRESSED:
        screen_message = "2";
        break;
    case THREE_PRESSED:
        screen_message = "3";
        break;
    case SUBTRACT_PRESSED:
        screen_message = "--";
        break;
    case COSINE_PRESSED:
        screen_message = "cos(";
        break;
    case LOG_PRESSED:
        screen_message = "log(";
        break;
    case LOGBASE_PRESSED:
        screen_message = "logBASE(";
        break;
    case ZERO_PRESSED:
        screen_message = "0";
        break;
    case COMMA_PRESSED:
        screen_message = ",";
        break;
    case ADD_PRESSED:
        screen_message = "+";
        break;
    case TANGENT_PRESSED:
        screen_message = "tan(";
        break;
    case INVERSE_SINE_PRESSED:
        screen_message = "arc-sin(";
        break;
    case INVERSE_COSINE_PRESSED:
        screen_message = "arc-cos(";
        break;
    case INVERSE_TANGENT_PRESSED:
        screen_message = "arc-tan(";
        break;
    case DELETE_PRESSED:
        screen_message = "";
        break;
    }
}
