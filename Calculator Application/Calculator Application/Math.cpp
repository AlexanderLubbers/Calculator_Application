#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "exprtk/exprtk.hpp"

#include "Math.h"
#include "Global.h"

using namespace rapidjson;
//function that takes in what is typed and parses it down until it is just some numbers math operations and parentheses
string Math::Parser(HWND hwnd)
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

	//check the parenthesis
	int leftp_count = 0;
	int rightp_count = 0;

	for (int i = 0; i < text_to_parse.size(); i++)
	{
		if (text_to_parse[i] == ')')
		{
			rightp_count++;
			if (i - 1 > 0)
			{
				if (text_to_parse[i - 1] == '(')
				{
					MessageBox(hwnd, L"Error", L"Invalid Equation", 1);
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
					MessageBox(hwnd, L"Error", L"Invalid Equation", 1);
				}
			}
		}
	}
	if (leftp_count != rightp_count)
	{
		MessageBox(hwnd, L"Error", L"Invalid Equation", 1);
	}
	//check to make sure that all parenthesis are correct

	return string();
}
