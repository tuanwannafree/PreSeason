#include "Time.h"
#include <iostream>

void Time::Set(int initHrs, int initMin, int initSecs) {
	std::cin >> initHrs >> initMin >> initSecs;
}

Time::Time(int Hours, int Minutes, int Seconds) {
	Set(Hours, Minutes, Seconds);
}