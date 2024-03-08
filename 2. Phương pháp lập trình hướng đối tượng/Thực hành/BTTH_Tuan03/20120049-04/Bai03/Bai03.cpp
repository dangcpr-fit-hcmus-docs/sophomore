#include <iostream>
#include "Geometry.h"
using namespace std;

int main()
{
	Triangle T;
	cout << T.ToStringTriangle() << endl;
	cout << "Chu vi: " << T.Perimeter() << endl;
	cout << "Dien tich: " << T.Area() << endl;
	Rectangular R;
	cout << R.ToStringRectangular() << endl;
	cout << "Chu vi: " << R.Perimeter() << endl;
	cout << "Dien tich: " << R.Area() << endl;
	Square S;
	cout << S.ToStringSquare() << endl;
	cout << "Chu vi: " << S.Perimeter() << endl;
	cout << "Dien tich: " << S.Area() << endl;
}