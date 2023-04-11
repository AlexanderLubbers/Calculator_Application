#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include <fstream>
#include <iostream>
#include <sstream>

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
	
	return string();
}
