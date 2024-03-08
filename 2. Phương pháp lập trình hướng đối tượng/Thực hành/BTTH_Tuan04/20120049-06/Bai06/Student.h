#pragma once
#include <iostream>
#include <string>
#include <vector>
//#include <QtXml>
//#include <QTextStream>
using namespace std;

struct NgaySinh {
	int day;
	int month;
	int year;
};
class Student {
private:
	string _id;
	string _FName;
	string _LName;
	string _Address;
	NgaySinh _Birth;
	double _Mark;
public:
	void setID(string id) { _id = id; };
	void setFName(string FName) { _FName = FName; };
	void setLName(string LName) { _LName = LName; };
	void setAddress(string Address) { _Address = Address; };
	void setBirth(NgaySinh Birth) { _Birth = Birth; };
	void setMark(double Mark) { _Mark = Mark; };
	string getID() { return _id; };
	string getFName() { return _FName; };
	string getLName() { return _LName; };
	string getAddress() { return _Address; };
	NgaySinh getBirth() { return _Birth; };
	double getMark() { return _Mark; };
};
class ArrayStudent {
private:
	vector<Student> _S;
public:
	ArrayStudent(string);
	void SortByLName();
	void writeXML(string);
	~ArrayStudent();
};