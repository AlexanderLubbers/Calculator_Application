#include "HandleCommand.h"

//constructor called upon initializing the class which is what this line of code is doing
Calculator_Screen s;

void HandleCommand::handle_command(HWND hWnd, WPARAM wParam)
{
    string screen_message = "";
    switch (wParam)
    {
    case LEFT_PARENTHESES_PRESSED:
        screen_message = "(";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case RIGHT_PARENTHESES_PRESSED:
        screen_message = ")";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case DECIMAL_PRESSED:
        screen_message = ".";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case NEGATIVE_PRESSED:
        screen_message = "-";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
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
        screen_message = "rad(";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case SEVEN_PRESSED:
        screen_message = "7";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case EIGHT_PRESSED:
        screen_message = "8";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case NINE_PRESSED:
        screen_message = "9";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case DIVIDE_PRESSED:
        screen_message = "/";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case PI_PRESSED:
        screen_message = "pi";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case EXPONENT_PRESSED:
        screen_message = "pow(";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case FOUR_PRESSED:
        screen_message = "4";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case FIVE_PRESSED:
        screen_message = "5";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case SIX_PRESSESD:
        screen_message = "6";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case MULTIPLY_PRESSED:
        screen_message = "*";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case SINE_PRESSED:
        screen_message = "Sin(";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case ABS_PRESSED:
        screen_message = "abs(";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case ONE_PRESSED:
        screen_message = "1";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case TWO_PRESSED:
        screen_message = "2";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case THREE_PRESSED:
        screen_message = "3";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case SUBTRACT_PRESSED:
        screen_message = "-";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case COSINE_PRESSED:
        screen_message = "Cos(";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case LOG_PRESSED:
        screen_message = "log10(";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case LOGBASE_PRESSED:
        screen_message = "logB(";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case ZERO_PRESSED:
        screen_message = "0";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case COMMA_PRESSED:
        screen_message = ",";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case ADD_PRESSED:
        screen_message = "+";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case TANGENT_PRESSED:
        screen_message = "Tan(";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case INVERSE_SINE_PRESSED:
        screen_message = "asin(";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case INVERSE_COSINE_PRESSED:
        screen_message = "acos(";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case INVERSE_TANGENT_PRESSED:
        screen_message = "atan(";
        s.update_json(screen_message, false);
        s.render_screen(hWnd);
        break;
    case ENTER_PRESSED:
        screen_message = "ENTER";
        s.update_json(screen_message, true);
        s.render_screen(hWnd);
        break;
    }
}
