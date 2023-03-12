//these have to be included before any class that uses the windows api.
//in fact that should be done for anything that does not use the winapi
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <fstream>

#include "Calculator_Screen.h"
#include<Windows.h>

using namespace rapidjson;
using namespace std;

Calculator_Screen::Calculator_Screen()
{
	//Setting up the json file in information will be stored.
	Document document;
	document.SetObject();

	//test to see if the json is created?
	document.AddMember("author", "Walter White", document.GetAllocator()); //this adds the key of author and its value to the json
	
	// Serialize the JSON document to a file
	//hopefully this code will actually create the json file
	StringBuffer buf;
	Writer<StringBuffer> writer(buf);
	document.Accept(writer);
	ofstream file("data.json");
	file << buf.GetString();
	file.close();
}

void Calculator_Screen::receiver(int msg)
{

}
