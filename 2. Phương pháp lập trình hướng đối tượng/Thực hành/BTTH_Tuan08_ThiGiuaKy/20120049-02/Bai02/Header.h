#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class date {
protected:
	int _day;
	int _month;
	int _year;
public:
	date();
	date(int, int, int);
	int day() { return _day; }
	int month() { return _month; }
	int year() { return _year; }
	void setDay(int day) { _day = day; }
	void setMonth(int month) { _month = month; }
	void setYear(int year) { _year = year; }
	friend istream& operator >> (istream& is, date& dob) {
		int a;
		is >> a; dob.setDay(a);
		is >> a; dob.setMonth(a);
		is >> a; dob.setYear(a);
		return is;
	}
	friend ostream& operator << (ostream& os, date& dob) {
		os << dob.day() << "/";
		os << dob.month() << "/";
		os << dob.year();
		return os;
	}
	date operator=(const date& dob1) {
		date dob;
		_day = dob1._day;
		_month = dob1._month;
		_year = dob1._year;
		return dob;
	}
	~date() {};
};
class Student {
protected:
	string _name;
	string _CT;
	string _id;
	date _dob;
	double _gpa;
public:
	Student(string);
	Student(string, string, string, date, double);
	string name() { return _name; }
	string id() { return _id; }
	date dob() { return _dob; }
	double gpa() { return _gpa; }
	void setName(string name) { _name = name; }
	void setId(string id) { _id = id; }
	void setDOB(date dob) { _dob = dob; }
	void setGPA(double gpa) { _gpa = gpa; }
	virtual void input();
	virtual bool isGraduate();
	virtual string toString();
	~Student() {
		//cout << "Destructor " << _CT;
	}
};
class StudentCQ : public Student {
public:
	StudentCQ(string CT = "CQ") : Student(CT) {};
	void input();
	bool isGraduate();
	string toString();
	~StudentCQ() {};
};
class StudentTT : public Student {
protected:
	int _toefl;
public:
	StudentTT(string CT = "TT") : Student(CT) {
		_name = "";
		_id = "";
		_gpa = 0;
		_CT = CT;
		_toefl = 0;
	};
	StudentTT(string name, string id, string CT, date dob, double gpa, int toefl) : Student(name, id, CT, dob, gpa) {
		_name = "";
		_id = "";
		_gpa = 0;
		_CT = CT;
		_dob = dob;
		_toefl = toefl;
	};
	void input();
	bool isGraduate();
	string toString();
	~StudentTT() {};
};

class ListStudent {
private:
	vector<Student*> _list;
public:
	ListStudent();
	vector<Student*> list() { return _list; }
	void setList(vector<Student*> list) { _list = list; }
	void input();
	void output();
	long TotalGraduate();
	void listGraduate();
	~ListStudent() {
		for (int i = 0; i < _list.size(); i++) {
			delete _list[i];
			cout << "\nDesturctor Element";
		}
		cout << "\nDesturctor List";
	}
};