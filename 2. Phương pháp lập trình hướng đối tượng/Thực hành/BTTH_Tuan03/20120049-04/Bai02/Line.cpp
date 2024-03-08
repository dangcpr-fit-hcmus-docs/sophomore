#include "Line.h"
#include <sstream>
#include <iostream>
#include <math.h>
using namespace std;
Point::Point() {
	double x, y;
	cout << "Nhap (x,y): ";
	cin >> x >> y;
	_x = x;
	_y = y;
}
string Point::ToString() {
	stringstream ss;
	ss << "Diem da nhap la: (" << _x << "," << _y << ")";
	string s = ss.str();
	return s;
}

string Line::ToStringLine() {
	stringstream ss;
	ss << "Duong thang da nhap la: (" << _a.X() << "," << _a.Y() << ") (" << _b.X() << ", " << _b.Y() << ")";
	string s = ss.str();
	return s;
}
double Line::Length() {
	double dx = _a.X() - _b.X();
	double dy = _a.Y() - _b.Y();
	double d = sqrt(dx * dx + dy * dy);
	return d;
}
Line::~Line() { }