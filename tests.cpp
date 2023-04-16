#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include <iostream>
#include <string>
#include <sstream>

Time test1 = {10, 55};
Time test2 = {23, 30};

TEST_CASE("Minutes Since Midnight")
{
    CHECK(minutesSinceMidnight(test1) == 655);
    CHECK(minutesSinceMidnight(test2) == 1410);
}