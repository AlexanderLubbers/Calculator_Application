#pragma once
#include <Windows.h>
#include "resource.h"
#include <iostream>
class Calculator_Screen {
public:
	int Draw_Screen(std::string msg);
	int Recieve_Message(int msg);
};

