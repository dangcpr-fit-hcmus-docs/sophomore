#include "Text.h"
#include <time.h>
class MySimpleCSVFileLogger;
#pragma warning (disable:4996)

MySimpleLogger::MySimpleLogger()
{

}


MySimpleLogger::~MySimpleLogger()
{
}

string MySimpleLogger::messTime() {
	stringstream ss;

	time_t now = time(0);
	tm* ltm = localtime(&now);

	ss << ltm->tm_year + 1900 << ' ' << ltm->tm_mon + 1 << ' ' << ltm->tm_mday << ' ' << ltm->tm_hour << ' ' << ltm->tm_min << ' ' << ltm->tm_sec;

	string s = ss.str();
	return s;
}
string MySimpleLogger::message(string w) {
	stringstream ss;

	ss << messTime() << ' ' << w << endl;

	string s = ss.str();
	return s;
}