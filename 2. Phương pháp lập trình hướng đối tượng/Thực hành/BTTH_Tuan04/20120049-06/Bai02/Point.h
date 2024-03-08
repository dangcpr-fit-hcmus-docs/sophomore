#pragma once
#include <string>
using namespace std;

class Point {
private:
	int _x;
	int _y;
public:
	Point();
	Point(int);
	Point(int, int);
	int getX() { return _x; }
	int getY() { return _y; }
	void setPoint(int a, int b) { _x = a; _y = b; }
	string ToString();
	~Point();
};

class ArrayPoint {
private:
	Point* _k = NULL;
public:
	ArrayPoint(string);
	double Dis(Point, Point);
	Point MaxDis(Point);
	string ToString();
	~ArrayPoint();
};