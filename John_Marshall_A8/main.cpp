// john Marshall Homework assignment 8

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "Storm.h"
#include "StormTree.h"

using namespace std;

int main()
{
    ifstream file;
    file.open("cyclones_1900_2010_bst.csv");
    string line;
    int count = 0;
    getline(file, line);

    //create
    StormTree tree = StormTree();

    //read CSV
    while (getline(file, line) && count < 500)
    {

        // convert line to char array
        int length = line.length();
        char *str = new char[length + 1];
        strcpy(str, line.c_str());

        char *pch;
        pch = strtok(str, ",");
        int lineElementCount = 0;
        
        string tempName = "";
        int  tempYear;
        int  tempCategory;
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

        //create temp storm
        Storm TempStorm = Storm(tempName, tempYear, tempCategory, tempCost);
        //add to tree
        tree.insert(TempStorm);

        count++;
    }

    //traverse the tree in different in order, pre order, post order, breadthFirst
    cout <<"Inorder: ";
    tree.traverse(1);
    cout <<"\nPreorder: ";
    tree.traverse(2);
    cout <<"\nPostorder: ";
    tree.traverse(3);
    cout <<"\nBreadth First: ";
    tree.breadthFirst();

    file.close();
    return 0;
}