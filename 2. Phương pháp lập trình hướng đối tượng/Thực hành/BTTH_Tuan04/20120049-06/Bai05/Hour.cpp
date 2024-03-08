#include <ctime>
#include <iostream>
#include "Hour.h"
#pragma warning(disable : 4996)
using namespace std;

Time::Time(int hour, int minute, int second) {
	_hour = hour;
	_minute = minute;
	_second = second;
	time_t rawtime;
	time(&rawtime);
	struct tm* timeinfo;
	timeinfo = localtime(&rawtime);
	timeinfo->tm_hour = _hour;
	timeinfo->tm_min = _minute;
	timeinfo->tm_sec = _second;
	_time = mktime(timeinfo);
}
time_t Time::Increase1s() {
	struct tm* timeYes;
	time_t _timeNew;
	//time(&_date);
	time(&_timeNew);
	_timeNew = _time;
	timeYes = localtime(&_timeNew);
	timeYes->tm_sec--;
	return mktime(timeYes);
}
time_t Time::Decrease1s() {
	struct tm* timeTom;
	//time(&_date);
	time_t _timeNew;
	//time(&_date);
	time(&_timeNew);
	_timeNew = _time;
	timeTom = localtime(&_timeNew);
	timeTom->tm_sec++;
	return mktime(timeTom);
}
Time::~Time() {
	cout << "Destructor Time";
}