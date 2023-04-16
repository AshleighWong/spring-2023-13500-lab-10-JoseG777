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

enum Genre
{
    ACTION,
    COMEDY,
    DRAMA,
    ROMANCE,
    THRILLER
};

class Movie
{
public:
    std::string title;
    Genre genre;
    int duration;
    operator std::string()
    {
        return title;
    }
};

class TimeSlot
{
public:
    Movie movie;
    Time startTime;
};

void printMovie(Movie mv);

// void printTimeSlot(TimeSlot ts);

std::string getTimeSlot(TimeSlot ts);

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);

bool timeOverlap(TimeSlot ts1, TimeSlot ts2);