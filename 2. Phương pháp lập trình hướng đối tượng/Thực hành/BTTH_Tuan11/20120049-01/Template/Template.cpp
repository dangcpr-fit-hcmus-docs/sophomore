#include "Header.h"

int main() {
	int mangInt[5] = { 4, -2, 5, 0, 6 };
	double mangThuc[4] = { 6.0, -1.5, 0.5, -3 };
	Fraction mangPhanSo[5] = { Fraction(1,3), Fraction(-3, 5), Fraction(), Fraction(8, 7), Fraction(9,8)};
	MyArray<int> arr1;
	MyArray<double> arr2;
	MyArray<Fraction> arr3;
	try {
		arr1.setArray(mangInt, 5);
		cout << "Gia tri phan tu thu 2: " << arr1[2] << endl;
		cout << "Mang Int la: ";  arr1.print();
		arr1.sort();
		cout << "Mang Int sau khi sap xep la: ";  arr1.print();
		arr1[2] = arr1[3]; //Gan phan tu thu 2 bang phan tu thu 3
		cout << "Mang Int sau khi gan arr1[2] = arr1[3]: ";  arr1.print(); cout << '\n';

		arr2.setArray(mangThuc, 4);
		cout << "Gia tri phan tu thu 2: " << arr2[2] << endl;
		cout << "Mang Thuc la: ";  arr2.print();
		arr2.sort();
		cout << "Mang Thuc sau khi sap xep la: ";  arr2.print();
		arr2[1] = arr2[2];
		cout << "Mang Int sau khi gan arr2[1] = arr2[2]: ";  arr2.print(); cout << '\n';

		arr3.setArray(mangPhanSo, 5);
		cout << "Gia tri phan tu thu 2: " << arr3[2] << endl;
		cout << "Mang Phan So la: ";  arr3.print();
		arr3.sort();
		cout << "Mang Thuc sau khi sap xep la: ";  arr3.print();
		arr3[2] = arr3[3];
		cout << "Mang Int sau khi gan arr3[2] = arr2[3]: ";  arr3.print();
	}
	catch (const char* msg) {
		cout << "Error: " << msg;
	}
	return 0;
}