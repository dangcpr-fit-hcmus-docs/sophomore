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
	~Point();
};
class Polygon {
private:
	int _n;
	Point* _k = NULL;
public:
	void setN(int n) { _n = n; _k = new Point[_n]; }
	int getN() { return _n; }
	Polygon();
	string ToStringPolygon();
	double Length(Point, Point);
	double Perimeter();
	double Area();
	bool checkConvex();
	bool isInside(Point);
	~Polygon();
};