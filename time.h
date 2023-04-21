#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Time
{
public:
    int h;
    int m;
};

void printTime(Time time);

int minutesSinceMidnight(Time time);

int minutesUntil(Time earlier, Time later);

Time addMinutes(Time time0, int min);