#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

//these have to be included before any class that uses the windows api.
//in fact that should be done for anything that does not use the winapi
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"

#include "Global.h"
#include "Calculator_Screen.h"

using namespace rapidjson;
using namespace std;

Global g;

Calculator_Screen::Calculator_Screen()
{
	ifstream file;

	file.open("calculator_data.json");
	if (!file)
	{
		//Setting up the json file in information will be stored.
		Document document;
		document.SetObject();

		//Creating another document that will serve almost as a sub json.
		//sub json for the equation history
		Document EquationHistory;
		EquationHistory.SetObject();
		EquationHistory.AddMember("dummy", "foo", EquationHistory.GetAllocator());

		//sub json for answer history
		Document AnswerHistory;
		AnswerHistory.SetObject();
		AnswerHistory.AddMember("test", "test", AnswerHistory.GetAllocator());

		document.AddMember("Current Equation", "", document.GetAllocator());
		document.AddMember("Current Answer", "", document.GetAllocator());
		document.AddMember("Equation History", EquationHistory, document.GetAllocator());
		document.AddMember("Answer History", AnswerHistory, document.GetAllocator());

		// Serialize the JSON document to a file
		//hopefully this code will actually create the json file
		StringBuffer buf;
		PrettyWriter<StringBuffer> writer(buf);
		//this line of code converts or serializes document into a stream
		//a stream is simply an abstract representation of a sequence of data that can be read from or written to
		//this stream will allow the user
		//in other words this line of code seems to be an important step in creating the json file?
		document.Accept(writer);
		ofstream json_file("calculator_data.json"); //creates an output file stream object called json_file and opens a new file called data.json for writing?
		json_file << buf.GetString() << endl; //method is called to retrieve the serialized JSON data as a string. Finally, the serialized JSON data is written to the output file using <<
	}
	else
	{
		return;
	}
}

void Calculator_Screen::render_screen(HWND hwnd)
{
	stringstream ss;
	ifstream file("calculator_data.json");

	ss << file.rdbuf();
	string json_str = ss.str();

	Document doc;
	doc.Parse(json_str.c_str());
	string text = doc["Current Equation"].GetString();
	if (text.length() > 101)
	{
		MessageBox(hwnd, L"You have reached the maximum length for an equation", L"Error", 1);
		return;
	}
	//hdc means handle device context
	//it is a data structure that handles graphic objects and their associated attributes
	
	//get the hdc
	HDC hdc = GetDC(hwnd);

	//make the text size larger and make the font arial
	HFONT hFont = CreateFont(74, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial");
	
	HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
	
	// Set text color
	SetTextColor(hdc, RGB(0, 0, 0)); // Red color

	// Set text background color
	SetBkColor(hdc, RGB(255, 255, 255)); // White background color
	// Draw text
	//TextOut(hdc, 1, 20, screen_text, text.length());
	LPCWSTR screen_message = g.convert_to_lpcwstr(text);

	//erase everything in a given rectangle
	// Invalidate the rectangle that encloses the text
	RECT rect;
	rect.left = 10;
	rect.top = 10;
	rect.right = 600; // adjust these values to cover the entire area where the text was drawn
	rect.bottom = 100;
	InvalidateRect(hwnd, &rect, TRUE);

	TextOut(hdc, 10, 20, screen_message, text.length());

	//cleanup
	SelectObject(hdc, hOldFont);
	DeleteObject(hFont);
}

void Calculator_Screen::update_json(string character, bool special_msg)
{
	//This is how the program will handle messages sent by the buttons when they are clicked
	//This will sort the message into two categories so that they can be correctly stored in the json
	stringstream ss;
	//convert the character to a c-styled string
	const char* msg = character.c_str();
	if (special_msg == false) 
	{
		// Read the JSON file into a string
		ifstream file("calculator_data.json");
		ss << file.rdbuf();
		string json_str = ss.str();

		//parse the json into a document object
		Document json;
		json.Parse(json_str.c_str());

		//find the value to update
		Value& equation_update = json["Current Equation"];

		// the size that the buffer should be
		size_t len = strlen(equation_update.GetString()) + strlen(msg) + 1;

		//allocate memory for the buffer based off of the length of the new string
		char* buffer = new char[len];
		strcpy(buffer, equation_update.GetString());
		strcat(buffer, msg);
		string new_msg = buffer;
		equation_update.SetString(new_msg.c_str(), new_msg.length(), json.GetAllocator());
		//deallocate that memory to avoid memory leaks
		delete[] buffer;

		//writing the document back into a json file
		StringBuffer buffer_out;
		PrettyWriter<StringBuffer> writer(buffer_out);
		json.Accept(writer);
		
		ofstream update_file("calculator_data.json");
		update_file << buffer_out.GetString() << endl;

	}
	else 
	{
		if (character == "CLEAR")
		{
			ifstream file("calculator_data.json");
			ss << file.rdbuf();
			string json_str = ss.str();

			Document json;
			json.Parse(json_str.c_str());

			Value& equation = json["Current Equation"];
			equation.SetString("");

			StringBuffer buf;
			PrettyWriter<StringBuffer> writer(buf);
			json.Accept(writer);

			ofstream update_file("calculator_data.json");
			update_file << buf.GetString() << endl;
			
			// Get a handle to the current window
			HWND hwnd = GetForegroundWindow();

			render_screen(hwnd);
		}
		else if (character == "ENTER")
		{

		}
		else
		{

		}
	}
}
