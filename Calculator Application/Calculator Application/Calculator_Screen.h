#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include<Windows.h>
using namespace std;

class Calculator_Screen
{
public:
	//a constructor is a function that gets called when a class is initialized
	Calculator_Screen();
	void render_screen(HWND hwnd);
	void update_json(string character, bool special_msg);
};

