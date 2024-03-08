#include "Header.h"
#include <string>
#include <sstream>

date::date() {
	_day = 1;
	_month = 1;
	_year = 1970;
}

date::date(int day, int month, int year) {
	_day = day;
	_month = month;
	_year = year;
}

Student::Student(string CT) {
	_name = "";
	_id = "";
	_gpa = 0;
	_CT = CT;
}

Student::Student(string name, string id, string CT, date dob, double gpa) {
	_name = "";
	_id = "";
	_gpa = 0;
	_CT = CT;
	_dob = dob;
}

void Student::input() {
	cin.ignore(); cout << "Nhap ten: "; getline(cin, _name);
	cout << "Nhap ngay sinh: "; cin >> _dob;
	cout << "Nhap diem: "; cin >> _gpa; cout << endl;
}

bool Student::isGraduate() {
	if (_gpa >= 5) return 1;
	else return 0;
}

string Student::toString() {
	stringstream ss;
	ss << "Ten sinh vien: " << _name << " - MSSV: " << _id << " - Chuong trinh: " << _CT << endl;
	ss << "\tNgay sinh: " << _dob << endl;
	ss << "\tDiem trung binh: " << _gpa << endl;
	if (isGraduate() == 1) ss << "\tTinh trang: Du dieu kien tot nghiep" << endl;
	else ss << "\tTinh trang: Chua du dieu kien tot nghiep" << endl;
	string s = ss.str();
	return s;
}
void StudentCQ::input() {
	Student::input();
}
bool StudentCQ::isGraduate() {
	return Student::isGraduate();
}

string StudentCQ::toString() {
	return Student::toString();
}
void StudentTT::input() {
	cin.ignore(); cout << "Nhap ten: "; getline(cin, _name);
	cout << "Nhap ngay sinh: "; cin >> _dob;
	cout << "Nhap diem: "; cin >> _gpa;
	cout << "Nhap diem toefl: "; cin >> _toefl; cout << endl;
}
bool StudentTT::isGraduate() {
	if (_gpa >= 5 && _toefl >= 80) return 1;
	else return 0;
}
string StudentTT::toString() {
	stringstream ss;
	ss << "Ten sinh vien: " << _name << " - MSSV: " << _id << " - Chuong trinh: " << _CT << endl;
	ss << "\tNgay sinh: " << _dob << endl;
	ss << "\tDiem trung binh: " << _gpa << endl;
	ss << "\tDiem toefl: " << _toefl << endl;
	if (isGraduate() == 1) ss << "\tTinh trang: Du dieu kien tot nghiep" << endl;
	else ss << "\tTinh trang: Chua du dieu kien tot nghiep" << endl;
	string s = ss.str();
	return s;
}
ListStudent::ListStudent() {}
void ListStudent::input() {
	int a, n;
	cout << "So sinh vien CQ: "; cin >> n;
	cout << "Nhap id bat dau: "; cin >> a;
	for (int i = 0; i < n; i++) {
		Student* tmp = new StudentCQ("CQ");
		tmp->input();
		tmp->setId(to_string(a++));
		_list.push_back(tmp);
	}
	cout << "So sinh vien TT: "; cin >> n;
	cout << "Nhap id bat dau: "; cin >> a;
	for (int i = 0; i < n; i++) {
		Student* tmp = new StudentTT("TT");
		tmp->input();
		tmp->setId(to_string(a++));
		_list.push_back(tmp);
	}
}
void ListStudent::output() {
	for (int i = 0; i < _list.size(); i++) {
		cout << _list[i]->toString();
	}
}
long ListStudent::TotalGraduate() {
	long total = 0;
	for (int i = 0; i < _list.size(); i++) {
		if (_list[i]->isGraduate() == 1) total++;
	}
	return total;
}
void ListStudent::listGraduate() {
	cout << "Sinh vien du dieu kien tot nghiep: " << endl;
	for (int i = 0; i < _list.size(); i++) {
		if(_list[i]->isGraduate() == 1) cout << _list[i]->toString();
	}
	cout << "Tong so sinh vien tot nghiep: " << TotalGraduate();
}