#pragma once


#include <fstream>
#include<Windows.h>
#include <iostream>
using namespace std;

class Calculator_Screen
{
public:
	//a constructor is a function that gets called when a class is initialized
	Calculator_Screen();
	void render_screen(HDC hdc, string character);
	void update_json(string character, bool special_msg);
};

