#pragma once
#include<Windows.h>

class Math
{
public:
	static double sqroot(double index, double radicand);
	static double exp(double base, double exponent);
	static double logB(double base, double argument);
	static double Parser(HWND hwnd);
	void json_updator(double answer);
	void displayer();
};

