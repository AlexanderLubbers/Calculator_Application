#include "HandleCommand.h"

//constructor called upon initializing the class which is what this line of code is doing
Calculator_Screen s;

void HandleCommand::handle_command(HWND hWnd, WPARAM wParam)
{
    int screen_message = 0;
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
    case DELETE_PRESSED:
        screen_message = 34;
        break;
    }
}
