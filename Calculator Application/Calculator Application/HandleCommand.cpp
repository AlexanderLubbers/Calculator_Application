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
        s.update_json(screen_message, false);
        //s.render_screen(hWnd);
        break;
    case RIGHT_PARENTHESES_PRESSED:
        screen_message = ")";
        s.update_json(screen_message, false);
        //s.render_screen(hWnd, screen_message);
        break;
    case DECIMAL_PRESSED:
        screen_message = ".";
        s.update_json(screen_message, false);
        break;
    case NEGATIVE_PRESSED:
        screen_message = "-";
        s.update_json(screen_message, false);
        break;
    case HISTORY_PRESSED:
        screen_message = "HISTORY";
        s.update_json(screen_message, true);
        break;
    case CLEAR_PRESSED:
        screen_message = "CLEAR";
        s.update_json(screen_message, true);
        break;
    case SQROOT_PRESSED:
        screen_message = "sqrt(";
        s.update_json(screen_message, false);
        break;
    case SEVEN_PRESSED:
        screen_message = "7";
        s.update_json(screen_message, false);
        break;
    case EIGHT_PRESSED:
        screen_message = "8";
        s.update_json(screen_message, false);
        break;
    case NINE_PRESSED:
        screen_message = "9";
        s.update_json(screen_message, false);
        break;
    case DIVIDE_PRESSED:
        screen_message = "/";
        s.update_json(screen_message, false);
        break;
    case PI_PRESSED:
        screen_message = "pi";
        s.update_json(screen_message, false);
        break;
    case EXPONENT_PRESSED:
        screen_message = "^";
        s.update_json(screen_message, false);
        break;
    case FOUR_PRESSED:
        screen_message = "4";
        s.update_json(screen_message, false);
        break;
    case FIVE_PRESSED:
        screen_message = "5";
        s.update_json(screen_message, false);
        break;
    case SIX_PRESSESD:
        screen_message = "6";
        s.update_json(screen_message, false);
        break;
    case MULTIPLY_PRESSED:
        screen_message = "*";
        s.update_json(screen_message, false);
        break;
    case SINE_PRESSED:
        screen_message = "sin(";
        s.update_json(screen_message, false);
        break;
    case E_PRESSED:
        screen_message = "e";
        s.update_json(screen_message, false);
        break;
    case ONE_PRESSED:
        screen_message = "1";
        s.update_json(screen_message, false);
        break;
    case TWO_PRESSED:
        screen_message = "2";
        s.update_json(screen_message, false);
        break;
    case THREE_PRESSED:
        screen_message = "3";
        s.update_json(screen_message, false);
        break;
    case SUBTRACT_PRESSED:
        screen_message = "--";
        s.update_json(screen_message, false);
        break;
    case COSINE_PRESSED:
        screen_message = "cos(";
        s.update_json(screen_message, false);
        break;
    case LOG_PRESSED:
        screen_message = "log(";
        s.update_json(screen_message, false);
        break;
    case LOGBASE_PRESSED:
        screen_message = "logBASE(";
        s.update_json(screen_message, false);
        break;
    case ZERO_PRESSED:
        screen_message = "0";
        s.update_json(screen_message, false);
        break;
    case COMMA_PRESSED:
        screen_message = ",";
        s.update_json(screen_message, false);
        break;
    case ADD_PRESSED:
        screen_message = "+";
        s.update_json(screen_message, false);
        break;
    case TANGENT_PRESSED:
        screen_message = "tan(";
        s.update_json(screen_message, false);
        break;
    case INVERSE_SINE_PRESSED:
        screen_message = "arc-sin(";
        s.update_json(screen_message, false);
        break;
    case INVERSE_COSINE_PRESSED:
        screen_message = "arc-cos(";
        s.update_json(screen_message, false);
        break;
    case INVERSE_TANGENT_PRESSED:
        screen_message = "arc-tan(";
        s.update_json(screen_message, false);
        break;
    case DELETE_PRESSED:
        screen_message = "DELETE";
        s.update_json(screen_message, true);
        break;
    }
}
