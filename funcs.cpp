#include <iostream>
#include <string>

class Time
{
public:
    int h;
    int m;

    void printTime(Time time)
    {
        std::cout << h << ":" << m << "\n";
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
};

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
};

class TimeSlot
{
public:
    Movie movie;
    Time startTime;
};

Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};
Movie movie3 = {"TEST", ACTION, 73};

TimeSlot morning = {movie1, {9, 15}};
TimeSlot daytime = {movie2, {12, 15}};
TimeSlot evening = {movie2, {16, 45}};

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
    finish = ts.startTime.addMinutes(ts.startTime, ts.movie.duration);
    printMovie(ts.movie);
    //[starts at 9:15, ends by 11:11]
    std::cout << " [starts at " << ts.startTime.h << ":" << ts.startTime.m << " , ends by " << finish.h << ":" << finish.m << "]"
              << "\n";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    Time finish;
    finish = ts.startTime.addMinutes(ts.startTime, ts.movie.duration);
    TimeSlot after = {nextMovie, finish};
    return after;
}

int main()
{
    /* Time now;
    now.h = 17;
    now.m = 45;

    std::cout << now.h << ":" << now.m << "\n";

    Time test = {17, 45};
    Time test1 = {01, 00};

    int test2 = test.minutesUntil(test, test1);

    std::cout << test2 << "\n";

    int h = 10;
    int m = 323;

    std::cout << m / 60 << " " << m % 60 << "\n";

    Time test3 = test.addMinutes(test, 45);

    std::cout << test3.h << ":" << test3.m << "\n"; */

    // printTimeSlot(morning);

    TimeSlot test = scheduleAfter(morning, movie1);

    std::cout << test.startTime.h << ":" << test.startTime.m << "\n";
}