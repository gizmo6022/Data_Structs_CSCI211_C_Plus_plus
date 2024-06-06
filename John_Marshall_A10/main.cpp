// john Marshall Homework assignment 10

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "Storm.h"
#include "MinHeap.h"

using namespace std;

int main()
{
    ifstream file;
    file.open("cyclones_1900_2010_a10.csv");
    string line;
    int count = 0;
    getline(file, line);

    // create
    Storm initArray[16] = {Storm()};

    // read CSV
    while (getline(file, line) && count < 16)
    {

        // convert line to char array
        int length = line.length();
        char *str = new char[length + 1];
        strcpy(str, line.c_str());

        char *pch;
        pch = strtok(str, ",");
        int lineElementCount = 0;

        string tempName = "";
        int tempYear;
        int tempCategory;
        float tempCost;

        tempName = pch;

        while (pch != NULL)
        {
            switch (lineElementCount)
            {
            case 1:
                tempYear = atoi(pch);
                break;
            case 2:
                tempCategory = atoi(pch);
                break;
            case 3:
                tempCost = atof(pch);
                break;
            }

            lineElementCount++;
            pch = strtok(NULL, ",");
        }

        // create temp storm
        Storm TempStorm = Storm(tempName, tempYear, tempCategory, tempCost);
        // add to tree
        initArray[count] = TempStorm;

        count++;
    }

    //create heap
    MinHeap heap = MinHeap();
    cout <<" OUT OF ORDER NAMES:\n";

    //print and add to heap
    for (int f = 0; f < count; f++)
    {
        cout << initArray[f].getName() + "\n";
        heap.add(initArray[f]);
    }

    //clear intial array
    for (int x = 0; x < count; x++)
    {
        initArray[x] = Storm();
    }

    cout <<"\n IN ORDER NAMES:\n";

    //remove from heap and re add to array in order, print names
    for (int y = 0; y < count; y++)
    {
        initArray[y] = heap.remove();
        cout << initArray[y].getName();
        cout << "\n";
    }

    file.close();
    return 0;
}