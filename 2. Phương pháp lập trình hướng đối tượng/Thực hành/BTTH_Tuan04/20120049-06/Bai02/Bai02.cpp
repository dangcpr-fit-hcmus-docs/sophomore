#include <iostream>
#include "Point.h"
using namespace std;
int main()
{
	int x, y;
	cout << "Nhap (x,y)=";
	cin >> x >> y;
	Point P(x, y);
	ArrayPoint arr("Point.txt");
	cout << endl << "Max Distance: " << arr.MaxDis(P).ToString() << endl;
	cout << endl << arr.ToString();
}