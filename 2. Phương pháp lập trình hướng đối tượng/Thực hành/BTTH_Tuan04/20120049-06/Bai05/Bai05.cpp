#include <iostream>
#include <iomanip>
#include "Hour.h"
#pragma warning(disable : 4996)
int main()
{
    struct tm* timeYes;
    int m, d, y;
    cout << "Nhap gio:phut:giay(dang 24h): ";
    cin >> m >> d >> y;
    Time time(m, d, y);
    time_t yes = time.Increase1s();
    time_t tom = time.Decrease1s();
    //time(&yes);
    cout.fill('0');
    struct tm* DYes;
    DYes = localtime(&yes);
    cout << "Tang 1 giay: " << setw(2) << DYes->tm_hour << ":" << setw(2) << DYes->tm_min << ":" << setw(2) << DYes->tm_sec << endl;
    DYes = localtime(&tom);
    cout << "Giam 1 giay: " << setw(2) << DYes->tm_hour << ":" << setw(2) << DYes->tm_min << ":" << setw(2) << DYes->tm_sec << endl;
}