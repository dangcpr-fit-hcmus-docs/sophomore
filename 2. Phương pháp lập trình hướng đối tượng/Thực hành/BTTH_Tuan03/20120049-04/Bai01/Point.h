#pragma once
#include <string>
using namespace std;

class Point {
private:
	double _x;
	double _y;
public:
	Point();
	string ToString();
	~Point();
};