#include <iostream>
#include <iomanip>
#include "Date.h"
#pragma warning(disable : 4996)
int main()
{
    struct tm* timeYes;
    int m, d, y;
    cout << "Nhap ngay/thang/nam: ";
    cin >> m >> d >> y;
    Date date(m, d, y);
    time_t yes = date.Yesterday();
    time_t tom = date.Tomorrow();
    //time(&yes);
    struct tm* DYes;
    DYes = localtime(&yes);
    cout.fill('0');
    cout << "Ngay hom qua: " << setw(2) << DYes->tm_mday << "/" << setw(2) << DYes->tm_mon + 1 << "/" << DYes->tm_year + 1900 << endl;
    DYes = localtime(&tom);
    cout << "Ngay hom sau: " << setw(2) << DYes->tm_mday << "/" << setw(2) << DYes->tm_mon + 1 << "/" << DYes->tm_year + 1900 << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
