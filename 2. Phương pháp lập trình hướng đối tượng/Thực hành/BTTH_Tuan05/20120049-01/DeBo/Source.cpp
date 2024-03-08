#include <iostream>
#include <sstream>
#include <string>
#include "Header.h"
using namespace std;

BoSua::BoSua() {
	_id = -1;
	_weight = 10;
	_age = 5;
}

BoSua::BoSua(int id, double weight, double age) {
	_id = id;
	if (weight <= 0) _weight = 25;
	else _weight = weight;
	if (age <= 0) _age = 1;
	else _age = age;
}

void BoSua::operator=(const BoSua& obj) {
	_id = obj._id;
	_weight = obj._weight;
	_age = obj._age;
}

string BoSua::Info() {
	stringstream ss;
	ss << "Bo sua id = " << _id << "; Can nang = " << _weight << "; Tuoi = " << _age << "\n";
	string s = ss.str();
	return s;
}

BoSua::~BoSua() {
	//cout << "Destructor BoSua!";
}

De::De() {
	_id = -1;
	_weight = 10;
	_age = 5;
}

De::De(int id, double weight, double age) {
	_id = id;
	if (weight <= 0) _weight = 25;
	else _weight = weight;
	if (age <= 0) _age = 1;
	else _age = age;
}

void De::operator=(const De& obj) {

	_id = obj._id;
	_weight = obj._weight;
	_age = obj._age;
}

string De::Info() {
	stringstream ss;
	ss << "De id = " << _id << "; Can nang = " << _weight << "; Tuoi = " << _age << "\n";
	string s = ss.str();
	return s;
}

//e::~De() {
	//cout << "Destructor De!";
//}

void NongTrai::Nhap() {
	int a, n; double b, c;
	cout << "Nhap so bo sua: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap bo sua id = " << i + 1 << ":\n";
		cout << "Can nang: "; cin >> b;
		cout << "Tuoi: "; cin >> c;
		BoSua tmp(i + 1, b, c);
		ds_bo_sua.push_back(tmp);
	}
	cout << "Nhap so de: "; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap de id = " << i + 1 << ":\n";
		cout << "Can nang: "; cin >> b;
		cout << "Tuoi: "; cin >> c;
		De tmp(i + 1, b, c);
		ds_de.push_back(tmp);
	}
}

void NongTrai::Xuat() {
	cout << "---Thong tin bo de---\n";
	for (int i = 0; i < ds_bo_sua.size(); i++) {
		cout << ds_bo_sua[i].Info();
	}
	for (int i = 0; i < ds_de.size(); i++) {
		cout << ds_de[i].Info();
	}
}
void NongTrai::Xuat_Theo_Tuoi(int min, int max) {
	cout << "\n---Thong tin bo de tu " << min << " toi " << max << " tuoi---\n";
	for (int i = 0; i < ds_bo_sua.size(); i++) {
		if (ds_bo_sua[i].getAge() >= min && ds_bo_sua[i].getAge() <= max)
			cout << ds_bo_sua[i].Info();
	}
	for (int i = 0; i < ds_de.size(); i++) {
		if (ds_de[i].getAge() >= min && ds_de[i].getAge() <= max)
			cout << ds_de[i].Info();
	}
}
NongTrai::~NongTrai() { }