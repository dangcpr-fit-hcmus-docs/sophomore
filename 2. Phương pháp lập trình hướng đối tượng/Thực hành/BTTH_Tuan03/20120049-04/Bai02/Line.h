#pragma once
#include <string>
using namespace std;

class Point {
private:
	double _x;
	double _y;
public:
	double X() { return _x; }
	double Y() { return _y; }
	void setPoint(double x, double y) { _x = x; _y = y; }
	Point();
	string ToString();
};

class Line {
private:
	Point _a;
	Point _b;
public:
	string ToStringLine();
	double Length();
	~Line();
};