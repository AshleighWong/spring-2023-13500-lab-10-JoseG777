#pragma once
#include <iostream>
#include <string>
#include <sstream>

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
