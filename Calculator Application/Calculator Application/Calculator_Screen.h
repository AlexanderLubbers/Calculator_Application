#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "BackgroundHandler.h"
#include <Windows.h>
using namespace std;

extern UINT uMsgMyMessage;

class Calculator_Screen
{
public:
	//a constructor is a function that gets called when a class is initialized
	Calculator_Screen();
	void render_screen(HWND hwnd);
	void update_json(string character, bool special_msg);
	void handle_mode(int message);
};

