#ifndef STORM_H
#define STORM_H
#include <iostream>
#include <string>

using namespace std;

class Storm
{
public:
    string name;
    int year;
    int category;
    float cost;

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

    string toString()
    {
        string tempCat = "";
        if (this->category == 0)
        {
            tempCat = "tropical storm";
        }
        else
        {
            tempCat = to_string(this->category);
        }

        string s = this->name + ": " + to_string(this->year) + ", " +
                   to_string(this->cost) + ", Category: " + tempCat + "\n";
        return s;
    }

    //gets
    int getCategory()
    {
        return this->category;
    }

    float getCost()
    {
        return this->cost;
    }
};

#endif
