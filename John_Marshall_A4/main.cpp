// john Marshall Homework assignment 4

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "FireStationList.h"

using namespace std;

int main()
{
    ifstream file;
    file.open("firestations.csv");
    string line;
    int count = 0;
    getline(file, line);

    FireStationList list = FireStationList();

    while (getline(file, line) && count < 500)
    {

        // convert line to char array
        int length = line.length();
        char *str = new char[length + 1];
        strcpy(str, line.c_str());

        char *pch;
        pch = strtok(str, ",");

        FireStation temp = FireStation();

        temp.stationNumber = atoi(pch);

        pch = strtok(NULL, ",");
        temp.location = pch;
            list.push(temp);
    }
    //sort list
    list.bubbleSort(list.getSize());
    //print forward and backwards
    list.printForward();
    list.printBackward();

    file.close();
    return 0;
}
