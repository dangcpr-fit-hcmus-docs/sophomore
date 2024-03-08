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

class Triangle {
private:
	Point _a, _b, _c;
public:
	string ToStringTriangle();
	double Length(Point, Point);
	double Perimeter();
	double Area();
	~Triangle();
};

class Rectangular {
private:
	Point _a, _b, _c, _d;
public:
	string ToStringRectangular();
	double Length(Point, Point);
	double Perimeter();
	double Area();
	~Rectangular();
};

class Square {
private:
	Point _a, _b, _c, _d;
public:
	string ToStringSquare();
	double Length(Point, Point);
	double Perimeter();
	double Area();
	~Square();
};
