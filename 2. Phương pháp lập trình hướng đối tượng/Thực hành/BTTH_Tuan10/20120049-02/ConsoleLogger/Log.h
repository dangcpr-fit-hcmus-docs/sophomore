#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

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
class MySimpleConsoleLogger : public MySimpleLogger {
public:
	static MySimpleLogger* createInstance() {
		if (MySimpleLogger::logger == NULL) {
			MySimpleLogger::logger = new MySimpleConsoleLogger();
		}
		return MySimpleLogger::logger;
	}
public:
	void write(string s) {
		cout << MySimpleLogger::logger->message(s);
	}
};
class A {
private:
	MySimpleLogger* logger;
public:
	A() {
		logger = MySimpleConsoleLogger::createInstance();
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
		logger = MySimpleConsoleLogger::createInstance();
	}
	void fooB() {
		logger->write("A simple logged message in B::fooB()");
	}
};