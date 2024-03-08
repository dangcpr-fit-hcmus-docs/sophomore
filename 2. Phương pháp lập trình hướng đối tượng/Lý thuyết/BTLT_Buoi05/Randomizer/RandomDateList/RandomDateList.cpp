#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>
#include <random>
#include <iomanip>
#pragma warning(disable : 4996)
using namespace std;

class RandomInteger;
class RandomDate;
class RandomInteger {
public:
    //RandomInteger();
    unsigned int next();
    unsigned int next(unsigned int);
    unsigned int next(unsigned int, unsigned int);
    ~RandomInteger();
};
class RandomDate {
private:
    int _day;
    int _month;
    int _year;
    RandomInteger _rng;
public:
    RandomDate();
    RandomDate(int, int, int);
    RandomDate(int, int, int, int, int, int);
    string toString();
    ~RandomDate();
};
class ArrayDate {
private:
    vector<RandomDate> _T;
public:
    ArrayDate();
    ArrayDate(int, int, int);
    ArrayDate(int, int, int, int, int, int);
    void Output();
    ~ArrayDate();
};
//RandomInteger::RandomInteger() {
    
//}
unsigned int RandomInteger::next() {
    unsigned int x = rand() & 0xff;
    x |= (rand() & 0xff) << 8;
    x |= (rand() & 0xff) << 16;
    x |= (rand() & 0xff) << 24;
    return x;
}
unsigned int RandomInteger::next(unsigned int right) {
    unsigned int x = rand() & 0xff;
    x |= (rand() & 0xff) << 8;
    x |= (rand() & 0xff) << 16;
    x |= (rand() & 0xff) << 24;
    x = x % right;
    return x;
}
unsigned int RandomInteger::next(unsigned int left, unsigned int right) {
    unsigned int x = rand() & 0xff;
    x |= (rand() & 0xff) << 8;
    x |= (rand() & 0xff) << 16;
    x |= (rand() & 0xff) << 24;
    x = x % (left - right + 1) + left;
    return x;
}
RandomInteger::~RandomInteger() {}

RandomDate::RandomDate() {
    long long res = _rng.next();
    time_t res2 = (time_t)res;
    struct tm* timeinfo;
    timeinfo = localtime(&res2);
    _year = timeinfo->tm_year + 1900;
    _month = timeinfo->tm_mon + 1;
    _day = timeinfo->tm_mday;
}
RandomDate::RandomDate(int e_day, int e_month, int e_year) {
    time_t rawtime;
    struct tm* end;
    time(&rawtime);
    end = localtime(&rawtime);
    end->tm_year = e_year - 1900;
    end->tm_mon = e_month - 1;
    end->tm_mday = e_day;
    time_t e = mktime(end);
    unsigned int res = _rng.next((unsigned int)e);
    time_t res2 = (time_t)res;
    struct tm* timeinfo;
    timeinfo = localtime(&res2);
    _year = timeinfo->tm_year + 1900;
    _month = timeinfo->tm_mon + 1;
    _day = timeinfo->tm_mday;
}
RandomDate::RandomDate(int s_day, int s_month, int s_year, int e_day, int e_month, int e_year) {
    time_t rawtime;
    struct tm* start;
    time(&rawtime);
    start = localtime(&rawtime);
    start->tm_year = s_year - 1900;
    start->tm_mon = s_month - 1;
    start->tm_mday = s_day;
    time_t s = mktime(start);
    struct tm* end;
    time(&rawtime);
    end = localtime(&rawtime);
    end->tm_year = e_year - 1900;
    end->tm_mon = e_month - 1;
    end->tm_mday = e_day;
    time_t e = mktime(end);
    unsigned int res = _rng.next((unsigned int)s, (unsigned int)e);
    time_t res2 = (time_t)res;
    struct tm* timeinfo;
    timeinfo = localtime(&res2);
    _year = timeinfo->tm_year + 1900;
    _month = timeinfo->tm_mon + 1;
    _day = timeinfo->tm_mday;
}
string RandomDate::toString() {
    stringstream ss;
    ss.fill('0');
    ss << setw(2) << _day << "/" << setw(2) << _month << "/" << setw(4) << _year << "\n";
    string s = ss.str();
    return s;
}
RandomDate::~RandomDate() {}

ArrayDate::ArrayDate() {
    for (int i = 0; i < 20; i++) {
        RandomDate tmp;
        _T.push_back(tmp);
    }
}
ArrayDate::ArrayDate(int e_day, int e_month, int e_year) {
    for (int i = 0; i < 20; i++) {
        RandomDate tmp(e_day, e_month, e_year);
        _T.push_back(tmp);
    }
}
ArrayDate::ArrayDate(int s_day, int s_month, int s_year, int e_day, int e_month, int e_year) {
    for (int i = 0; i < 20; i++) {
        RandomDate tmp(s_day, s_month, s_year, e_day, e_month, e_year);
        _T.push_back(tmp);
    }
}
void ArrayDate::Output() {
    for (int i = 0; i < 20; i++) {
        cout << _T[i].toString();
    }
}
ArrayDate::~ArrayDate() {}
int main() {
    srand(time(NULL));
    ArrayDate A1;
    A1.Output();
    return 0;
}