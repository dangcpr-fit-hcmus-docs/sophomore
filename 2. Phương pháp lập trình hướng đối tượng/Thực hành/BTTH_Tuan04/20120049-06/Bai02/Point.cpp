#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include "Point.h"
using namespace std;

Point::Point() {
	_x = 0;
	_y = 1;
}
Point::Point(int x) {
	_x = x;
	_y = 1;
}
Point::Point(int x, int y) {
	_x = x;
	_y = y;
}
string Point::ToString() {
	stringstream ss;
	ss << "(" << _x << "," << _y << ")";
	string s = ss.str();
	return s;
}
Point::~Point() {
	cout << endl << "Destructor Point";
}
ArrayPoint::ArrayPoint(string FileName) {
	fstream f;
	f.open(FileName, ios::in);
	_k = (Point*)malloc(0);
	int n = 0, x, y;
	while (!f.eof()) {
		_k = (Point*)realloc(_k, sizeof(Point) * (n + 1));
		f >> x >> y;
		_k[n].setPoint(x, y);
		n++;
	}
	f.close();
}
double ArrayPoint::Dis(Point a, Point b) {
	int dX = a.getX() - b.getX();
	int dY = a.getY() - b.getY();
	double d = sqrt(dX * dX + dY * dY);
	return d;
}
Point ArrayPoint::MaxDis(Point k) {
	Point Max = _k[0];
	int n = _msize(_k) / sizeof(Point);
	for (int i = 1; i < n; i++) {
		if (Dis(_k[i], k) > Dis(Max, k))
			Max = _k[i];
	}
	return Max;
}
string ArrayPoint::ToString() {
	stringstream ss;
	ss << "Mang Point: ";
	int n = _msize(_k) / sizeof(Point);
	for (int i = 0; i < n; i++) {
		ss << "(" << _k[i].getX() << "," << _k[i].getY() << ")";
	}
	string s = ss.str();
	return s;
}
ArrayPoint::~ArrayPoint() {
	free(_k);
	cout << endl << "Destructor Array";
}