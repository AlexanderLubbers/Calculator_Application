#include "HandleMenu.h"

void HandleMenu::handle_menu(HWND hwnd, WPARAM wparam)
{
	switch (wparam)
	{
    case MENU_HELP:
        MessageBox(hwnd, L"This is a Calculator application. Enter numbers in by clicking the buttons displaying that number and click the buttons with the operation you wish to perfrom in order to perform that operation on your number. for more details on how the buttons work click on the button details menu item located under file.", L"Help", 1);
        break;
    case FILE_MENU_EXIT:
        DestroyWindow(hwnd);
        break;
	}
}
