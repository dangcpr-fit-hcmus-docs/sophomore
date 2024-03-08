#include "Point.h"
#include <sstream>
#include <iostream>
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
Point::~Point() {
	cout << "\nDa huy (" << _x << "," << _y << ")";
}