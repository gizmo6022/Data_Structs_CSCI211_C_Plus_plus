#ifndef STORM_H
#define STORM_H
#include <iostream>
#include <string>

using namespace std;

class Storm
{
private:
    string name;
    int year;
    int category;
    float cost;

public:

    // null cosntructor
    Storm()
    {
    }
    // constructor
    Storm(string name, int year, int category, float cost)
    {
        this->name = name;
        this->year = year;
        this->category = category;
        this->cost = cost;
    }

    // gets
    string getName()
    {
        return this->name;
    }

    float getCost()
    {
        return this->cost;
    }
};

#endif
