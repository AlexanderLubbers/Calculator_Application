#include "AddMenus.h"

void AddMenus::AddMenuBar(HWND hWnd)
{
    HMENU hMenu;
    //*commented out sections are the lines of code for implementing submenues which will not be needed in this program
    hMenu = CreateMenu();
    HMENU hFileMenu = CreateMenu();
    //HMENU hSubMenu = CreateMenu();

    AppendMenuW(hFileMenu, MF_STRING, FILE_MENU_SETTINGS, L"Settings");
    AppendMenuW(hFileMenu, MF_SEPARATOR, NULL, NULL);
    AppendMenuW(hFileMenu, MF_STRING, FILE_MENU_EXIT, L"Exit");
    
    //AppendMenuW(hFileMenu, MF_POPUP, (UINT_PTR)hSubMenu, L"Open");

    //AppendMenuW(hSubMenu, MF_STRING, 10000, L"Wheeeeeeee");

    //instead of MF_STRING, MF_POPUP will be used because this will create a popup when clicked on
    AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, L"File");
    AppendMenuW(hMenu, MF_STRING, MENU_HELP, L"Help");

    SetMenu(hWnd, hMenu);
}
