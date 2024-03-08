#include <iostream>
#include "Text.h"

MySimpleLogger* MySimpleLogger::logger = NULL;
ofstream MySimpleTextFileLogger::fout;

int main(int argc, const char* argv[]) {
	A a1;
	B b1;
	b1.fooB();
	a1.fooA();
	return 0;
}