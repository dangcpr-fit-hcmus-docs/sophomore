#include <iostream>
#include "Line.h"
using namespace std;

int main()
{
	Line k;
	cout << k.ToStringLine() << endl;
	cout << "Do dai: " << k.Length();
}