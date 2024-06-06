// john Marshall Homework assignment 3

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "StormList.h"
#include <conio.h>
// #include "Storm.h"
// #include "Node.h"

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
        if (list.getSize() == 29)
        {
            list.insert(temp, 13);
        }
        else
        {

            // allocating to heap with pointer
            Node *tempNode = new Node();
            tempNode->setStorm(temp);
            list.push(tempNode);
        }
    }

    for (int x = 0; x < list.getSize(); x++)
    {
        Storm temp = Storm();
        temp = list.get(x);
        // print New Storm Item
        cout << temp.toString() + "\n";
    }

    file.close();
    return 0;
}
