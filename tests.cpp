#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "movie.h"
#include "time.h"
#include "timeslot.h"
#include <iostream>
#include <string>
#include <sstream>

Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};
Movie easyTest = {"Test", ACTION, 15};

TimeSlot morning = {movie1, {9, 15}};
TimeSlot daytime = {movie2, {12, 15}};
TimeSlot evening = {movie2, {16, 45}};

TimeSlot testing1 = {easyTest, {10, 15}};
TimeSlot testing2 = {easyTest, {10, 30}};

Time test1 = {10, 55};
Time test2 = {23, 30};

TEST_CASE("Minutes Since Midnight")
{
    CHECK(minutesSinceMidnight(test1) == 655);
    CHECK(minutesSinceMidnight(test2) == 1410);
}

TEST_CASE("Minutes Untill")
{
    CHECK(minutesUntil(test1, test2) == 755);
    CHECK(minutesUntil(test2, test1) == 685);
}

Time addedMinutes1 = addMinutes(test1, 102);
Time addedMinutes2 = addMinutes(test2, 29);

TEST_CASE("Add Minutes")
{
    CHECK(addedMinutes1.h == 12);
    CHECK(addedMinutes1.m == 37);
    CHECK(addedMinutes2.h == 23);
    CHECK(addedMinutes2.m == 59);
}

TimeSlot nextMovie1 = scheduleAfter(testing1, movie1);
TimeSlot nextMovie2 = scheduleAfter(daytime, movie1);
TimeSlot nextMovie3 = scheduleAfter(evening, movie1);

std::string testGTS1 = "Back to the Future COMEDY (116 min) [starts at 10:30 , ends by 12:26]";
std::string testGTS2 = "Back to the Future COMEDY (116 min) [starts at 14:29 , ends by 16:25]";
std::string testGTS3 = "Back to the Future COMEDY (116 min) [starts at 18:59 , ends by 20:55]";

TEST_CASE("Get Time Slot")
{
    CHECK(getTimeSlot(nextMovie1) == testGTS1);
    CHECK(getTimeSlot(nextMovie2) == testGTS2);
    CHECK(getTimeSlot(nextMovie3) == testGTS3);
}

TEST_CASE("Time Overlap?")
{
    CHECK(timeOverlap(morning, evening) == false);
    CHECK(timeOverlap(morning, testing1) == true);
    CHECK(timeOverlap(testing1, testing2) == false);
}