#include <iostream>
#include <string>
#include <sstream>
// #include "movie.h"
#include "time.h"
#include "timeslot.h"

void printTime(Time time)
{
    std::cout << time.h << ":" << time.m << "\n";
}

int minutesSinceMidnight(Time time)
{
    int minutes = (time.h * 60) + time.m;
    return minutes;
}

int minutesUntil(Time earlier, Time later)
{
    int minUntil;
    int minLater = (later.h * 60) + later.m;
    int minEarlier = (earlier.h * 60) + earlier.m;
    if (minLater < minEarlier)
    {
        minLater += 24 * 60;
        minUntil = minLater - minEarlier;
    }
    else
    {
        minUntil = minLater - minEarlier;
    }
    return minUntil;
}

Time addMinutes(Time time0, int min)
{
    Time newTime = time0;
    int h;
    int m;
    if (min % 60 == 0)
    {
        newTime.h += min / 60;
    }
    else
    {
        newTime.h += min / 60;
        newTime.m += min % 60;
    }
    if (newTime.m > 59)
    {
        newTime.h += newTime.m / 60;
        newTime.m = newTime.m % 60;
    }
    return newTime;
}

/* void printMovie(Movie mv)
{
    std::string g;
    switch (mv.genre)
    {
    case ACTION:
        g = "ACTION";
        break;
    case COMEDY:
        g = "COMEDY";
        break;
    case DRAMA:
        g = "DRAMA";
        break;
    case ROMANCE:
        g = "ROMANCE";
        break;
    case THRILLER:
        g = "THRILLER";
        break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
} */

/*void printTimeSlot(TimeSlot ts)
{
    Time finish;
    finish = addMinutes(ts.startTime, ts.movie.duration);
    printMovie(ts.movie);
    std::cout << " [starts at " << ts.startTime.h << ":" << ts.startTime.m << " , ends by " << finish.h << ":" << finish.m << "]"
              << "\n";
} */

std::string getTimeSlot(TimeSlot ts)
{

    std::string getTS = ts.movie.title + " ";

    switch (ts.movie.genre)
    {
    case ACTION:
        getTS += "ACTION (";
        break;
    case COMEDY:
        getTS += "COMEDY (";
        break;
    case DRAMA:
        getTS += "DRAMA (";
        break;
    case ROMANCE:
        getTS += "ROMANCE (";
        break;
    case THRILLER:
        getTS += "THRILLER (";
        break;
    }

    std::stringstream movieDuration;
    movieDuration << ts.movie.duration;
    getTS += movieDuration.str() + " min) [starts at ";

    std::stringstream startHour;
    std::stringstream startMinute;
    startHour << ts.startTime.h;
    startMinute << ts.startTime.m;
    getTS += startHour.str() + ":" + startMinute.str() + " , ends by ";

    Time finish;
    finish = addMinutes(ts.startTime, ts.movie.duration);
    std::stringstream endHour;
    std::stringstream endMinutes;
    endHour << finish.h;
    endMinutes << finish.m;
    getTS += endHour.str() + ":" + endMinutes.str() + "]";

    return getTS;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    Time finish;
    finish = addMinutes(ts.startTime, ts.movie.duration);
    TimeSlot after = {nextMovie, finish};
    return after;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    bool Over;
    Time end;
    end = addMinutes(ts1.startTime, ts1.movie.duration);
    if (end.h == ts2.startTime.h and end.m == ts2.startTime.m)
    {
        Over = false;
    }
    else if (end.h < ts2.startTime.h)
    {
        Over = false;
    }
    else
    {
        Over = true;
    }
    return Over;
}
