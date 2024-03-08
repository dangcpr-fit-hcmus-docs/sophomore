#include <iostream>
#include "Polygon.h"
using namespace std;

int main()
{
	Polygon G;
	cout << endl << G.ToStringPolygon();
	cout << endl << "Chu vi la: " << G.Perimeter();
	cout << endl << "Dien tich la: " << G.Area();
	cout << endl << "G la da giac loi? (1:True, 0:False): " << G.checkConvex() << endl;
	Point A;
	cout << endl << "A nam trong da giac G? (1:True, 0:False): " << G.isInside(A);
}