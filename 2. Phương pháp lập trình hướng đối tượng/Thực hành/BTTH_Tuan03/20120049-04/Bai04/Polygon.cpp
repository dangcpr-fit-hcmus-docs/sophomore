#define _USE_MATH_DEFINES
#include "Polygon.h"
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
Point::~Point() {
	cout << endl << "Destructor Point";
}

Polygon::Polygon() {
	int n;
	cout << "Nhap so dinh: ";
	cin >> n; setN(n);
}
string Polygon::ToStringPolygon() {
	stringstream ss;
	ss << "Da giac ban nhap la: ";
	for (int i = 0; i < _n; i++) {
		ss << "(" << _k[i].X() << "," << _k[i].Y() << ")";
	}
	string s = ss.str();
	return s;
}
double Polygon::Length(Point k, Point t) {
	double dx = k.X() - t.X();
	double dy = k.Y() - t.Y();
	double d = sqrt(dx * dx + dy * dy);
	return d;
}
double Polygon::Perimeter() {
	double Per = 0;
	for (int i = 0; i < _n; i++) {
		if (i != _n - 1) Per += Length(_k[i], _k[i + 1]);
		else
			Per += Length(_k[_n - 1], _k[0]);
	}
	return Per;
}
double Polygon::Area() {
	double xy = 0, yx = 0;
	for (int i = 0; i < _n; i++) {
		if (i != _n - 1) {
			xy += _k[i].X() * _k[i + 1].Y();
			yx += _k[i].Y() * _k[i + 1].X();
		}
		else {
			xy += _k[_n - 1].X() * _k[0].Y();
			yx += _k[_n - 1].Y() * _k[0].X();
		}
	}
	return abs(xy - yx) / 2;
}
bool Polygon::checkConvex() {
	double rad = 0;
	double dX1, dY1, dX2, dY2;
	for (int i = 0; i < _n; i++) {
		if (i == _n - 1) {
			dX1 = _k[_n - 2].X() - _k[_n - 1].X();
			dY1 = _k[_n - 2].Y() - _k[_n - 1].Y();
			dX2 = _k[0].X() - _k[_n - 1].X();
			dY2 = _k[0].Y() - _k[_n - 1].Y();
		}
		else if (i == 0) {
			dX1 = _k[_n - 1].X() - _k[0].X();
			dY1 = _k[_n - 1].Y() - _k[0].Y();
			dX2 = _k[1].X() - _k[0].X();
			dY2 = _k[1].Y() - _k[0].Y();
		}
		else {
			dX1 = _k[i - 1].X() - _k[i].X();
			dY1 = _k[i - 1].Y() - _k[i].Y();
			dX2 = _k[i + 1].X() - _k[i].X();
			dY2 = _k[i + 1].Y() - _k[i].Y();
		}
		rad += acos((dX1 * dX2 + dY1 * dY2) / (sqrt(dX1 * dX1 + dY1 * dY1) * sqrt(dX2 * dX2 + dY2 * dY2)));
	}
	if (rad == (_n - 2) * M_PI) return 1;
	else return 0;
}
bool Polygon::isInside(Point a) {
	double rad = 0;
	double dX1, dY1, dX2, dY2;
	for (int i = 0; i < _n; i++) {
		if (i != _n - 1) {
			dX1 = _k[i].X() - a.X();
			dY1 = _k[i].Y() - a.Y();
			dX2 = _k[i + 1].X() - a.X();
			dY2 = _k[i + 1].Y() - a.Y();
		}
		else {
			dX1 = _k[_n - 1].X() - a.X();
			dY1 = _k[_n - 1].Y() - a.Y();
			dX2 = _k[0].X() - a.X();
			dY2 = _k[0].Y() - a.Y();
		}
		rad += acos((dX1 * dX2 + dY1*dY2) / (sqrt(dX1 * dX1 + dY1 * dY1) * sqrt(dX2 * dX2 + dY2 * dY2)));
	}
	if (rad == 2 * M_PI) return 1;
	else return 0;
}
Polygon::~Polygon() {
	delete[] _k;
	cout << endl << "Destructor";
}