// CSVLogger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CSV.h"

MySimpleLogger* MySimpleLogger::logger = NULL;
ofstream MySimpleCSVFileLogger::fout;
int main(int argc, const char* argv[]) {
	A a1;
	B b1;
	b1.fooB();
	a1.fooA();
	return 0;
}