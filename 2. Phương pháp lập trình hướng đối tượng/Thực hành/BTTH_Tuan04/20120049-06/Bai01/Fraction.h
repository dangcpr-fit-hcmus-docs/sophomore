#pragma once
#include <string>
using namespace std;

class Fraction {
private:
	int _num;
	int _den;
public:
	Fraction();
	Fraction(int);
	Fraction(int, int);
	int getNum() { return _num; }
	int getDen() { return _den; }
	void setF(int a, int b) { _num = a; _den = b; }
	~Fraction();
};

class ArrayFrac {
private:
	Fraction* _k = NULL;
public:
	ArrayFrac(string);
	Fraction Max();
	Fraction Min();
	void Ascending();
	string ToString();
	~ArrayFrac();
};