#pragma once
#pragma once
#include <string>
#include <vector>
using namespace std;
class Point {
private:
	double _x;
	double _y;
public:
	double X() { return _x; }
	double Y() { return _y; }
	void setPoint(double x, double y) { 
		_x = x; 
		_y = y;
	}
	string ToString();
};

class Triangle {
private:
	Point _a, _b, _c;
public:
	Point A() { return _a; }
	Point B() { return _b; }
	Point C() { return _c; }
	void setA(double x, double y) {_a.setPoint(x, y);}
	void setB(double x, double y) { _b.setPoint(x, y); }
	void setC(double x, double y) { _c.setPoint(x, y); }
	string ToStringTriangle();
	double Length(Point, Point);
	double Degree(Point, Point, Point);
	bool validTri();
	double Perimeter();
	double Area();
	~Triangle();
};

class ArrayTriangle {
private:
	vector<Triangle> _T;
public:
	ArrayTriangle(string);
	int numTri();
	int delInvaildTri(); //Xoa tam giac khong hop le
	int equiTri(); //Tam giac deu
	int rightIsoTri(); //Tam giac vuong can
	int rightTri(); //Tam giac vuong
	int acuteTri();
	int obtuseTri();
	void printArrTri();
	~ArrayTriangle();
};