#pragma once
#include <iostream>

using namespace std;

class Calculator_Screen
{
public:
	//a constructor is a function that gets called when a class is initialized
	Calculator_Screen();
	void render_screen();
	void update_json(string character);
	void receiver(int msg);
};

