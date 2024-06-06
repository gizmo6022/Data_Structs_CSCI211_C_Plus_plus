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

    //constructos

    Storm(){
        name = "";
        year = 0;
        category = 0;
        cost = 0.0;
    }

    Storm( string stormName, int stormYear, int stormCatagory, float stormCost){
        string name = stormName;
        int year = stormYear;
        int category = stormCatagory;
        float cost = stormCatagory;
    }

    //deconstructors

    string toString()
    {
        string cat = "";
        switch(this->category)
          {
            case 0:
                cat = "Tropical Storm";
                break;
            case 1:
                cat = "1";
                break;
            case 2:
                cat = "2";
                break;
            case 3:
                cat = "3";
                break;
            case 4:
                cat = "4";
                break;
            case 5:
                cat = "5";
                break;
            default:
                cat ="NO RATING";
                break;
            }

        string storm = this->name + " Year: " + to_string(this->year) + " Catagory: " + cat + " Cost: " + to_string(this->cost);
        return storm;
    }

};
#endif
