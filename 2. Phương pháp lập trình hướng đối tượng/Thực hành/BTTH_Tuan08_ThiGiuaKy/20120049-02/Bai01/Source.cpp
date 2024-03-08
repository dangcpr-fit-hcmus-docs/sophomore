#include "Header.h"
#include <string>
#include <sstream>

Student::Student(string CT) {
	_name = "";
	_age = 18;
	_CT = CT;
	_id = "";
	_subNew = 0;
	_subRelearn = 0;
	_subRetest = 0;
}
Student::Student(string name, int age, string CT, string id, int subNew, int subRetest, int subRelearn) {
	_name = name;
	_age = age;
	_CT = CT;
	_id = id;
	_subNew = subNew;
	_subRelearn = subRelearn;
	_subRetest = subRetest;
}
void Student::input() {
	cin.ignore(); cout << "Nhap ten: "; getline(cin, _name);
	cout << "Nhap tuoi: "; cin >> _age;
	cout << "Nhap so mon dang ky moi: "; cin >> _subNew;
	cout << "Nhap so mon thi lai: "; cin >> _subRetest;
	cout << "Nhap so mon hoc lai: "; cin >> _subRelearn; cout << endl;
}
long Student::tuition() {
	if (_subNew + _subRelearn + _subRetest < 3)
		return -1;
	else {
		return 500000 + _subNew * 200000 + _subRetest * 50000 + _subRelearn * 100000;
	}
}
string Student::toString() {
	stringstream ss;
	ss << "Ten sinh vien: " << _name << " - MSSV: " << _id << " - Chuong trinh: " << _CT << endl;
	ss << "\tSo luong mon moi dang ky: " << _subNew << endl;
	ss << "\tSo luong mon dang ky thi lai: " << _subRetest << endl;
	ss << "\tSo luong mon dang ky hoc lai: " << _subRelearn << endl;
	if(tuition() != -1) ss << "\tHoc phi: " << tuition() << endl;
	string s = ss.str();
	return s;
}
long StudentCNTN::tuition() {
	return Student::tuition();
}
string StudentCNTN::toString() {
	return Student::toString();
}
long StudentCTTT::tuition() {
	if (_subNew + _subRelearn + _subRetest < 3)
		return -1;
	else {
		return 10000000 + _subNew * 1000000 + _subRetest * 100000 + _subRelearn * 500000;
	}
}
string StudentCTTT::toString() {
	return Student::toString();
}
ListStudent::ListStudent() {
}
void ListStudent::input() {
	int a, n;
	cout << "So sinh vien CNTN: "; cin >> n;
	cout << "Nhap id bat dau: "; cin >> a;
	for (int i = 0; i < n; i++) {
		Student* tmp = new StudentCNTN("CNTN");
		tmp->input();
		tmp->setId(to_string(a++));
		_list.push_back(tmp);
	}
	cout << "So sinh vien CTTT: "; cin >> n;
	cout << "Nhap id bat dau: "; cin >> a;
	for (int i = 0; i < n; i++) {
		Student* tmp = new StudentCTTT("CTTT");
		tmp->input();
		tmp->setId(to_string(a++));
		_list.push_back(tmp);
	}
}
void ListStudent::output() {
	for (int i = 0; i < _list.size(); i++) {
		cout << _list[i]->toString();
	}
	cout << endl << "Tong hoc phi: " << TotalTutition();
}
long ListStudent::TotalTutition() {
	long total = 0;
	for (int i = 0; i < _list.size(); i++) {
		if(_list[i]->tuition() != -1) total += _list[i]->tuition();
	}
	return total;
}