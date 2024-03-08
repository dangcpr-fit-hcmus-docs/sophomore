#pragma once
#include <ctime>
using namespace std;

class Time {
private:
	int _hour;
	int _minute;
	int _second;
	time_t _time;
public:
	Time(int, int, int);
	time_t getDate() { return _time; }
	time_t Increase1s();
	time_t Decrease1s();
	~Time();
};