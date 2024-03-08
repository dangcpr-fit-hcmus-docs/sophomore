#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
class MySimpleLogger;
class MySimpleCSVFileLogger;

//ofstream MySimpleCSVFileLogger::fout;

class MySimpleLogger {
private:
	string _message;
	
public:
	static MySimpleLogger* logger;
public:
	MySimpleLogger();
	~MySimpleLogger();
	string message() {
		return _message;
	}
	void setMess(string s) {
		_message = s;
	}
	string messTime();
	string message(string);
	virtual void write(string s) = 0;
};
class MySimpleTextFileLogger : public MySimpleLogger {
public:
	static ofstream fout;
	
public:
	MySimpleTextFileLogger() : MySimpleLogger() {
		fout.open("Text.txt");
	}
	static MySimpleLogger* createInstance() {
		if (MySimpleLogger::logger == NULL) {
			MySimpleLogger::logger = new MySimpleTextFileLogger();
		}
		return MySimpleLogger::logger;
	};
	void write(string s) {
		fout << MySimpleLogger::logger->message(s);
	}
};

class A {
private:
	MySimpleLogger* logger;
public:
	A() {
		logger = MySimpleTextFileLogger::createInstance();
		logger->write("Begin of A::A()");
		logger->write("Middle of A::A()");
		logger->write("End of A::A()");
	}
	void fooA() {
		logger->write("Begin of A::fooA()");
		logger->write("Middle of A::fooA()");
		logger->write("Another logged message in A::fooA()");
		logger->write("End of A::fooA()");
	}
};
class B {
private:
	MySimpleLogger* logger;
public:
	B() {
		logger = MySimpleTextFileLogger::createInstance();
	}
	void fooB() {
		logger->write("A simple logged message in B::fooB()");
	}
};