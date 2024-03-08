#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() {
	_num = 0;
	_den = 1;
}
Fraction::Fraction(int num) {
	_num = num;
	_den = 1;
}
Fraction::Fraction(int num, int den) {
	_num = num;
	_den = den;
}
Fraction::~Fraction() {
	cout << "Destructor Fraction" << endl;
}
ArrayFrac::ArrayFrac(string FileName) {
	fstream f;
	f.open(FileName, ios::in);
	_k = (Fraction*)malloc(0);
	int n = 0, num, den;
	while (!f.eof()) {
		_k = (Fraction*)realloc(_k, sizeof(Fraction) * (n + 1));
		f >> num >> den;
		_k[n].setF(num, den);
		n++;
	}
	f.close();
}
Fraction ArrayFrac::Max() {
	Fraction Max = _k[0];
	int n = _msize(_k) / sizeof(Fraction);
	for (int i = 1; i < n; i++) {
		if ((double)_k[i].getNum() / _k[i].getDen() > (double)Max.getNum() / Max.getDen())
			Max = _k[i];
	}
	return Max;
}
Fraction ArrayFrac::Min() {
	Fraction Min = _k[0];
	int n = _msize(_k) / sizeof(Fraction);
	for (int i = 1; i < n; i++) {
		if ((double)_k[i].getNum() / _k[i].getDen() < (double)Min.getNum() / Min.getDen())
			Min = _k[i];
	}
	return Min;
}
void ArrayFrac::Ascending() {
	int n = _msize(_k) / sizeof(Fraction);
	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n; j++)
			if ((double)_k[i].getNum() / _k[i].getDen() > (double)_k[j].getNum() / _k[j].getDen())
				swap(_k[i], _k[j]);
}
string ArrayFrac::ToString() {
	stringstream ss;
	ss << "Mang phan so: ";
	int n = _msize(_k) / sizeof(Fraction);
	for (int i = 0; i < n; i++) {
		ss << _k[i].getNum() << "/" << _k[i].getDen() << ' ';
	}
	string s = ss.str();
	return s;
}
ArrayFrac::~ArrayFrac() {
	free(_k);
	cout << "Destructor Array" << endl;
}