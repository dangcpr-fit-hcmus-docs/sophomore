#include <iostream>
#include "Header.h"

int main() {
	NongTrai NT;
	double a, b;
	NT.Nhap();
	NT.Xuat();
	cout << "\nMin = "; cin >> a;
	cout << "\nMax = "; cin >> b;
	NT.Xuat_Theo_Tuoi(a, b);
	cout << "\nKiem tra ham setter, toan tu =:\n";
	De tmp;
	De tmp2(13, 6, 7);
	tmp2.setWeight(10);
	tmp2.setAge(8);
	tmp = tmp2;
	cout << tmp.Info();
}