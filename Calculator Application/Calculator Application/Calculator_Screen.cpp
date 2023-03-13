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
	//this line of code converts or serializes document into a stream
	//a stream is simply an abstract representation of a sequence of data that can be read from or written to
	//this stream will allow the user
	//in other words this line of code seems to be an important step in creating the json file?
	document.Accept(writer); 
	ofstream json_file("data.json"); //creates an output file stream object called json_file and opens a new file called data.json for writing?
	json_file << buf.GetString(); //method is called to retrieve the serialized JSON data as a string. Finally, the serialized JSON data is written to the output file using <<
}

void Calculator_Screen::receiver(int msg)
{

}
