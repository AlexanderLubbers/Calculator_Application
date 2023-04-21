#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include "exprtk/exprtk.hpp"

#include "Math.h"
#include "Global.h"

using namespace rapidjson;
using namespace exprtk;

double Math::sqroot(double index, double radicand)
{
	return std::pow(radicand, 1.0 / index);
}

double Math::exp(double base, double exponent)
{
	return std::pow(base, exponent);
}


double Math::logB(double base, double argument)
{
	return std::log10(argument) / std::log10(base);
}


//function that takes in what is typed and parses it down until it is just some numbers math operations and parentheses
double Math::Parser(HWND hwnd)
{
	stringstream ss;
	ifstream file("calculator_data.json");

	//parse the json into a string
	ss << file.rdbuf();
	string json_str = ss.str();

	//parse the string into a document object
	Document doc;
	doc.Parse(json_str.c_str());

	string text_to_parse = doc["Current Equation"].GetString();

	//check the parentheses
	int leftp_count = 0;
	int rightp_count = 0;
	
	double answer = 0.0;

	for (int i = 0; i < text_to_parse.size(); i++)
	{
		if (text_to_parse[i] == ')')
		{
			rightp_count++;
			if (i - 1 > 0)
			{
				if (text_to_parse[i - 1] == '(')
				{
					MessageBox(hwnd, L"Invalid Equation", L"Error", 1);
					return -1;
				}
			}
		}
		if (text_to_parse[i] == '(')
		{
			leftp_count++;
			if (i + 1 < text_to_parse.size())
			{
				if (text_to_parse[i + 1] == ')')
				{
					MessageBox(hwnd, L"Invalid Equation", L"Error", 1);
					return -1;
				}
			}
		}
	}
	if (leftp_count != rightp_count)
	{
		MessageBox(hwnd, L"Error", L"Invalid Equation", 1);
		return -1;
	}
	
	symbol_table<double> symbol_table;
	expression<double> expr;
	parser<double> parser;

	symbol_table.add_constant("pi", 3.141592653589793238);
	symbol_table.add_function("rad", sqroot);
	symbol_table.add_function("logB", logB);
	symbol_table.add_function("pow", exp);

	expr.register_symbol_table(symbol_table);
	
	parser.compile(text_to_parse, expr);

	answer = expr.value();

	if (!parser.compile(text_to_parse, expr))
	{
		MessageBox(hwnd, L"Invalid Equation", L"Error", 1);
		return -1;
	}

	StringBuffer buf;
	PrettyWriter<StringBuffer> writer(buf);
	doc.Accept(writer);

	ofstream update_file("calculator_data.json");
	update_file << buf.GetString() << endl;

	return answer;
}

void Math::json_updator(double answer)
{
	stringstream ss;
	ifstream file("calculator_data.json");

	//parse the json into a string
	ss << file.rdbuf();
	string json_str = ss.str();
	ss.clear();

	//parse the string into a document object
	Document doc;
	doc.Parse(json_str.c_str());

	//setting the current answer to the new answer
	Value& new_answer = doc["Current Answer"];
	std::string str_answer = std::to_string(answer);
	new_answer.SetString(str_answer.c_str(), str_answer.length(), doc.GetAllocator());

	std::string equation = doc["Current Equation"].GetString();
	std::string empty = "";
	if (equation == empty)
	{
		return;
	}

	Value& equations = doc["Equation History"];
	//find length of equations
	const size_t num_items = equations.MemberCount();
	
	int key_num = num_items + 1;
	std::string key = "equation" + std::to_string(key_num);

	Value equation_value;
	equation_value.SetString(equation.c_str(), equation.length(), doc.GetAllocator());
	equations.AddMember(StringRef(key.c_str()), equation_value, doc.GetAllocator());

	Value& current_equation = doc["Current Equation"];
	current_equation.SetString("", 0, doc.GetAllocator());

	//write the string form of the json back into a file format
	StringBuffer buf;
	PrettyWriter<StringBuffer> writer(buf);
	doc.Accept(writer);
	
	ofstream update_file("calculator_data.json");
	update_file << buf.GetString() << endl;
}

void Math::displayer()
{
	stringstream ss;
	ifstream file("calculator_data.json");

	ss << file.rdbuf();
	string json_str = ss.str();

	Document doc;
	doc.Parse(json_str.c_str());
	string text = doc["Current Answer"].GetString();

	// Create a new font
	LOGFONT lf = { 0 };
	lf.lfHeight = 10; // set font height to a certain amount of pixels
	lf.lfWeight = FW_NORMAL;
	lf.lfCharSet = DEFAULT_CHARSET;
	lstrcpy(lf.lfFaceName, TEXT("Arial"));
	HFONT hFont = CreateFontIndirect(&lf);

	HWND hwnd = FindWindow(L"Calculator App", L"Calculator");
	//hdc means handle device context
	//it is a data structure that handles graphic objects and their associated attributes
	//get the hdc
	HDC hdc = GetDC(hwnd);

	SelectObject(hdc, hFont);
	
	Global g;
	LPCWSTR screen_message = g.convert_to_lpcwstr(text);

	//erase everything in a given rectangle by invalidating that rectance
	RECT rect;
	rect.left = 10;
	rect.top = 10;
	rect.right = 10000;
	rect.bottom = 100;
	InvalidateRect(hwnd, &rect, TRUE);

	HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

	TextOut(hdc, 10, 35, screen_message, text.length());
	//cleanup
	SelectObject(hdc, hOldFont);
	DeleteObject(hFont);
	ReleaseDC(hwnd, hdc);
}

//thoughts
// */ = checkmark
//1. on startup check if the current answer item displays something, if so then display that instead