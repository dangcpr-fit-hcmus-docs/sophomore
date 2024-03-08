#pragma once
#include <ctime>
using namespace std;

class Date {
private:
	int _day;
	int _month;
	int _year;
	time_t _date;
public:
	Date(int, int, int);
	time_t getDate() { return _date; }
	time_t Yesterday();
	time_t Tomorrow();
	~Date();
};