#include <iostream>
#include "Fraction.h"
int main()
{
	ArrayFrac k("Fraction.txt");
	cout << k.ToString();
	cout << "Max: " << k.Max().getNum() << "/" << k.Max().getDen() << endl;
	cout << "Min: " << k.Min().getNum() << "/" << k.Min().getDen() << endl;
	k.Ascending();
	cout << "Mang sap xep tang dan:\n" << k.ToString() << endl;
}