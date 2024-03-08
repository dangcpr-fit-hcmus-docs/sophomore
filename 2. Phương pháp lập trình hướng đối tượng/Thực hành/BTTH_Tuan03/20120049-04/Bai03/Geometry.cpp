#include "Geometry.h"
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

string Triangle::ToStringTriangle() {
	stringstream ss;
	ss << "Tam giac da nhap la: (" << _a.X() << "," << _a.Y() << ") (" << _b.X() << "," << _b.Y() << ") (" << _c.X() << "," << _c.Y() << ")";
	string s = ss.str();
	return s;
}
double Triangle::Length(Point k, Point t) {
	double dx = k.X() - t.X();
	double dy = k.Y() - t.Y();
	double d = sqrt(dx * dx + dy * dy);
	return d;
}
double Triangle::Perimeter() {
	double ab = Length(_a, _b);
	double ac = Length(_b, _c);
	double bc = Length(_a, _c);
	return ab + ac + bc;
}
double Triangle::Area() {
	double ab = Length(_a, _b);
	double ac = Length(_a, _c);
	double bc = Length(_b, _c);
	return sqrt((Perimeter()/2)*(Perimeter() / 2 - ab) * (Perimeter() / 2 - ac) * (Perimeter() / 2 - bc));
}
Triangle::~Triangle() {}

string Rectangular::ToStringRectangular() {
	stringstream ss;
	ss << "Hinh chu nhat da nhap la: (" << _a.X() << "," << _a.Y() << ") (" << _b.X() << "," << _b.Y() << ") (" << _c.X() << "," << _c.Y() << ") (" << _d.X() << "," << _d.Y() << ")";
	string s = ss.str();
	return s;
}
double Rectangular::Length(Point k, Point t) {
	double dx = k.X() - t.X();
	double dy = k.Y() - t.Y();
	double d = sqrt(dx * dx + dy * dy);
	return d;
}
double Rectangular::Perimeter() {
	double ab = Length(_a, _b);
	double bc = Length(_b, _c);
	return (ab + bc) * 2;
}
double Rectangular::Area() {
	double ab = Length(_a, _b);
	double bc = Length(_b, _c);
	return ab * bc;
}
Rectangular::~Rectangular() {}

string Square::ToStringSquare() {
	stringstream ss;
	ss << "Hinh vuong da nhap la: (" << _a.X() << "," << _a.Y() << ") (" << _b.X() << "," << _b.Y() << ") (" << _c.X() << "," << _c.Y() << ") (" << _d.X() << "," << _d.Y() << ")";
	string s = ss.str();
	return s;
}
double Square::Length(Point k, Point t) {
	double dx = k.X() - t.X();
	double dy = k.Y() - t.Y();
	double d = sqrt(dx * dx + dy * dy);
	return d;
}
double Square::Perimeter() {
	double ab = Length(_a, _b);
	return ab * 4;
}
double Square::Area() {
	double ab = Length(_a, _b);
	return ab * ab;
}
Square::~Square(){}