// john Marshall Homework assignment 5

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "Storm.h"
#include "StormList.h"

using namespace std;

int main()
{
    ifstream file;
    file.open("cyclones_1900_2010.csv");
    string line;
    int count = 0;
    getline(file, line);

    StormList list = StormList();

    while (getline(file, line) && count < 500)
    {

        // convert line to char array
        int length = line.length();
        char *str = new char[length + 1];
        strcpy(str, line.c_str());

        char *pch;
        pch = strtok(str, ",");
        int lineElementCount = 0;

        // temp storm
        Storm temp = Storm();
        temp.name = pch;

        while (pch != NULL)
        {
            switch (lineElementCount)
            {
            case 1:
                temp.year = atoi(pch);
                break;
            case 2:
                temp.category = atoi(pch);
                break;
            case 3:
                temp.cost = atof(pch);
                break;
            }

            lineElementCount++;
            pch = strtok(NULL, ",");
        }

        if (count < 14)
        {
            list.pushFront(temp);
        }
        else if (count == 29)
        {

            list.insert(temp, 13);
        }
        else
        {
            list.pushBack(temp);
        }

        count++;
    }

    list.printForward();
    // sort list
    list.bubbleSortCategory(list.getSize());
    cout << "SORTED BY CATEGORY FORWARDS--------------------------------\n";
    list.printForward();

    list.bubbleSortCost(list.getSize());
    cout << "SORTED BY COST BACKWARDS--------------------------------\n";
    list.printBackward();

    file.close();
    return 0;
}