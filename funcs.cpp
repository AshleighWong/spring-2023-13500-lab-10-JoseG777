#include <iostream>
#include <string>
#include <sstream>

class Time
{
public:
    int h;
    int m;
};

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
        minUntil = minLater - minLater;
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

void printMovie(Movie mv)
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
}

void printTimeSlot(TimeSlot ts)
{
    Time finish;
    finish = addMinutes(ts.startTime, ts.movie.duration);
    printMovie(ts.movie);
    std::cout << " [starts at " << ts.startTime.h << ":" << ts.startTime.m << " , ends by " << finish.h << ":" << finish.m << "]"
              << "\n";
}

// Back to the Future COMEDY (116 min) [starts at 9:15 , ends by 11:11]
std::string getTimeSlot(TimeSlot ts)
{

    std::string getTS = ts.movie.operator std::__1::string() + " ";

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

Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};
Movie easyTest = {"Test", ACTION, 15};

TimeSlot morning = {movie1, {9, 15}};
TimeSlot daytime = {movie2, {12, 15}};
TimeSlot evening = {movie2, {16, 45}};

TimeSlot testing1 = {easyTest, {10, 15}};
TimeSlot testing2 = {easyTest, {10, 30}};

int main()
{
    Time now;
    now.h = 17;
    now.m = 45;

    std::cout << now.h << ":" << now.m << "\n";

    Time test = {17, 45};
    Time test1 = {01, 00};

    int test2 = minutesUntil(test, test1);

    std::cout << test2 << "\n";

    int h = 10;
    int m = 323;

    std::cout << m / 60 << " " << m % 60 << "\n";

    Time test3 = addMinutes(test, 45);

    std::cout << test3.h << ":" << test3.m << "\n";

    TimeSlot test4 = scheduleAfter(morning, movie1);

    std::cout << test4.startTime.m << ":" << test4.startTime.m << " " << test4.movie.title << "\n";

    std::cout << timeOverlap(morning, evening) << "\n";

    std::cout << timeOverlap(morning, testing1) << "\n";

    std::cout << timeOverlap(testing1, testing2) << "\n";

    printTimeSlot(morning);

    printTimeSlot(testing1);

    std::cout << getTimeSlot(morning) << "\n";

    std::cout << getTimeSlot(testing1) << "\n";
}