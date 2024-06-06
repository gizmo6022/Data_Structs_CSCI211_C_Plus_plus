#ifndef FIRESTATION_H
#define FIRESTATION_H
#include <iostream>
#include <string>

using namespace std;

class FireStation
{
public:
    int stationNumber;
    string location;
    //null cosntructor
    FireStation()
    {
    }
    //constructor
    FireStation(int stationNumber, string location)
    {
        this->location = location;
        this->stationNumber = stationNumber;
    }
    //gets
    int getStation()
    {
        return this->stationNumber;
    }
    //toString
    string toString()
    {
        string s = to_string(this->stationNumber) + ": " + this->location;
        return s;
    }
};


#endif