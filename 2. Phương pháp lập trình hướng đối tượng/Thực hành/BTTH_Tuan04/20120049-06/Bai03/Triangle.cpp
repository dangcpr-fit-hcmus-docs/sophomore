#define _USE_MATH_DEFINES
#include "Triangle.h"
#include <sstream>
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
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
double Triangle::Degree(Point a, Point b, Point c) { //Tinh goc 2 vecto: ba va bc
	double ba_x = a.X() - b.X();
	double ba_y = a.Y() - b.Y();
	double bc_x = c.X() - b.X();
	double bc_y = c.Y() - b.Y();
	double deg = acos((ba_x * bc_x + ba_y * bc_y) / (sqrt(ba_x * ba_x + ba_y * ba_y) * sqrt(bc_x * bc_x + bc_y * bc_y)));
	return deg;
}
bool Triangle::validTri() {
	double ab = Length(_a, _b);
	double ac = Length(_b, _c);
	double bc = Length(_a, _c);
	if (abs(ab - ac) < bc && bc < ab + ac && abs(ac - bc) < ab && ab < ac + bc && abs(bc - ab) < ac && ac < bc + ab)
		return 1;
	else
		return 0;
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
	return sqrt((Perimeter() / 2) * (Perimeter() / 2 - ab) * (Perimeter() / 2 - ac) * (Perimeter() / 2 - bc));
}
Triangle::~Triangle() {}

ArrayTriangle::ArrayTriangle(string file) {
	fstream f;
	double x[6];
	Triangle tmp;
	f.open(file, ios::in);
	while (!f.eof()) {
		for (int i = 0; i < 6; i++) {
			f >> x[i];
		}
		tmp.setA(x[0], x[1]);
		tmp.setB(x[2], x[3]);
		tmp.setC(x[4], x[5]);
		_T.push_back(tmp);
	}
	f.close();
}
int ArrayTriangle::numTri() {
	return _T.size();
}
int ArrayTriangle::delInvaildTri() {
	int k = 0;
	for (int i = 0; i < _T.size(); i++) {
		if (!_T[i].validTri()) {
			_T.erase(_T.begin() + i);
			k++;
		}
	}
	return k;
}
int ArrayTriangle::equiTri() {
	int k = 0;
	for (int i = 0; i < _T.size(); i++) {
		double ab = _T[i].Length(_T[i].A(), _T[i].B());
		double bc = _T[i].Length(_T[i].B(), _T[i].C());
		double ca = _T[i].Length(_T[i].C(), _T[i].A());
		double degB = _T[i].Degree(_T[i].A(), _T[i].B(), _T[i].C());
		double degC = _T[i].Degree(_T[i].B(), _T[i].C(), _T[i].A());
		double degA = _T[i].Degree(_T[i].C(), _T[i].A(), _T[i].B());
		if ((ab == bc && degB - M_PI / 3 < pow(10,-15)) 
			|| (bc == ca && degC - M_PI / 3 < pow(10, -15))
			|| (ca == ab && degA - M_PI / 3 < pow(10, -15)))
			k++;
	}
	return k;
}
int ArrayTriangle::rightIsoTri() {
	int k = 0;
	for (int i = 0; i < _T.size(); i++) {
		double ab = _T[i].Length(_T[i].A(), _T[i].B());
		double bc = _T[i].Length(_T[i].B(), _T[i].C());
		double ca = _T[i].Length(_T[i].C(), _T[i].A());
		if ((ab == bc && sqrt(ab * ab + bc * bc) == ca)
			|| (bc == ca && sqrt(bc * bc + ca * ca) == ab)
			|| (ca == ab && sqrt(ca * ca + ab * ab) == bc))
			k++;
	}
	return k;
}

int ArrayTriangle::rightTri() {
	int k = 0;
	for (int i = 0; i < _T.size(); i++) {
		double ab = _T[i].Length(_T[i].A(), _T[i].B());
		double bc = _T[i].Length(_T[i].B(), _T[i].C());
		double ca = _T[i].Length(_T[i].C(), _T[i].A());
		if (sqrt(ab * ab + bc * bc) == ca
			|| sqrt(bc * bc + ca * ca) == ab
			|| sqrt(ca * ca + ab * ab) == bc)
			k++;
	}
	return k;
}

int ArrayTriangle::acuteTri() {
	int k = 0;
	for (int i = 0; i < _T.size(); i++) {
		double degB = _T[i].Degree(_T[i].A(), _T[i].B(), _T[i].C());
		double degC = _T[i].Degree(_T[i].B(), _T[i].C(), _T[i].A());
		double degA = _T[i].Degree(_T[i].C(), _T[i].A(), _T[i].B());
		if (degA < M_PI / 2 && degB < M_PI / 2 && degC < M_PI / 2)
			k++;
	}
	return k;
}
int ArrayTriangle::obtuseTri() {
	int k = 0;
	for (int i = 0; i < _T.size(); i++) {
		double degB = _T[i].Degree(_T[i].A(), _T[i].B(), _T[i].C());
		double degC = _T[i].Degree(_T[i].B(), _T[i].C(), _T[i].A());
		double degA = _T[i].Degree(_T[i].C(), _T[i].A(), _T[i].B());
		if (degA > M_PI / 2 || degB > M_PI / 2 || degC > M_PI / 2)
			k++;
	}
	return k;
}
void ArrayTriangle::printArrTri() {
	for (int i = 0; i < _T.size(); i++) {
		cout << "(" << _T[i].A().X() << "," << _T[i].A().Y() << ")";
		cout << "(" << _T[i].B().X() << "," << _T[i].B().Y() << ")";
		cout << "(" << _T[i].C().X() << "," << _T[i].C().Y() << ")\n";
	}
}
ArrayTriangle::~ArrayTriangle() {
	cout << "Destructor Array Triangle";
}