#pragma once
#include <iostream>
#include <string>
#include <sstream>

class TimeSlot
{
public:
    Movie movie;
    Time startTime;
};

// void printMovie(Movie mv);

// void printTimeSlot(TimeSlot ts);

std::string getTimeSlot(TimeSlot ts);

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);

bool timeOverlap(TimeSlot ts1, TimeSlot ts2);