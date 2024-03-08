#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student {
protected:
	string _name;
	int _age;
	string _CT;
	string _id;
	int _subNew;
	int _subRetest;
	int _subRelearn;
public:
	Student(string);
	Student(string, int, string, string, int, int, int);
	string name() { return _name; }
	int age() { return _age; }
	string id() { return _id; }
	int subNew() { return _subNew; }
	int subRetest() { return _subRetest; }
	int subRelearn() { return _subRelearn; }
	void setname(string name) { _name = name; }
	void setAge(int age) { _age = age; }
	void setId(string id) { _id = id; }
	void setSubNew(int subNew) { _subNew = subNew; }
	void setSubRetest(int subRetest) { _subRetest = subRetest; }
	void setSubRelearn(int subRelearn) { _subRelearn = subRelearn; }
	void input();
	virtual long tuition();
	virtual string toString();
	~Student() {
		//cout << "Destructor " << _CT;
	}
};
class StudentCNTN : public Student {
public:
	StudentCNTN(string CT = "CNTN") : Student(CT) {};
	string toString();
	long tuition();
	~StudentCNTN() {};
};
class StudentCTTT : public Student {
public:
	StudentCTTT(string CT = "CTTT") : Student(CT) {};
	string toString();
	long tuition();
	~StudentCTTT() {};
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
	long TotalTutition();
	~ListStudent() {
		for (int i = 0; i < _list.size(); i++) {
			delete _list[i];
			cout << "\nDesturctor Element";
		}
		cout << "\nDesturctor List";
	}
};