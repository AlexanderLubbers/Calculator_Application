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

	std::wstring wstr = std::to_wstring(answer);

	LPCWSTR deargod = wstr.c_str();

	MessageBox(hwnd, deargod, deargod, 1);

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

}

void Math::displayer()
{
}
