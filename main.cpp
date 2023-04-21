#include <iostream>
#include <string>
#include <sstream>
#include "movie.h"
#include "time.h"
#include "timeslot.h"

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
    Time test1 = {10, 55};
    Time test2 = {23, 30};

    std::cout << minutesSinceMidnight(test1) << "\n"
              << minutesSinceMidnight(test2) << "\n";

    std::cout << minutesUntil(test1, test2) << "\n"
              << minutesUntil(test2, test1) << "\n";

    Time addedMinutes1 = addMinutes(test1, 102);
    Time addedMinutes2 = addMinutes(test2, 29);

    std::cout << addedMinutes1.h << ":" << addedMinutes1.m << "\n"
              << addedMinutes2.h << ":" << addedMinutes2.m << "\n";

    std::cout << getTimeSlot(morning) << "\n"
              << getTimeSlot(daytime) << "\n"
              << getTimeSlot(evening) << "\n";

    TimeSlot nextMovie1 = scheduleAfter(testing1, movie1);
    TimeSlot nextMovie2 = scheduleAfter(daytime, movie1);
    TimeSlot nextMovie3 = scheduleAfter(evening, movie1);

    std::cout << getTimeSlot(nextMovie1) << "\n"
              << getTimeSlot(nextMovie2) << "\n"
              << getTimeSlot(nextMovie3) << "\n";

    std::cout << timeOverlap(morning, evening) << "\n"
              << timeOverlap(morning, testing1) << "\n"
              << timeOverlap(testing1, testing2) << "\n";
}