#include <ctime>
#include <iostream>
#include "Date.h"
#pragma warning(disable : 4996)
using namespace std;

Date::Date(int day, int month, int year) {
	_day = day;
	_month = month;
	_year = year;
	time_t rawtime;
	time(&rawtime);
	struct tm* timeinfo;
	timeinfo = localtime(&rawtime);
	timeinfo->tm_year = _year - 1900;
	timeinfo->tm_mon = _month - 1;
	timeinfo->tm_mday = _day;
	_date = mktime(timeinfo);
}
time_t Date::Yesterday() {
	struct tm* timeYes;
	time_t _dateNew;
	//time(&_date);
	time(&_dateNew);
	_dateNew = _date;
	timeYes = localtime(&_dateNew);
	timeYes->tm_mday--;
	return mktime(timeYes);
}
time_t Date::Tomorrow() {
	struct tm* timeTom;
	//time(&_date);
	time_t _dateNew;
	//time(&_date);
	time(&_dateNew);
	_dateNew = _date;
	timeTom = localtime(&_dateNew);
	timeTom->tm_mday++;
	return mktime(timeTom);
}
Date::~Date(){
	cout << "Destructor Date";
}