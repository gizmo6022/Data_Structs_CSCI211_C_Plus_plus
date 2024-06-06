// John Marshall HW6
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int hashFunc(string, int);
int CheckArr(int[], string[], int, int);

int main()
{
    srand(3);
    string jNumArr[25000];

    // create the JNums
    for (int i = 0; i < 25000; i++)
    {
        int rn = abs(rand() * 100000000 % 100000000);
        string jNum;
        // Place in Placeholder zzeros
        if (rn < 10)
        {
            jNum = "J0000000" + to_string(rn);
        }
        else if (rn < 100)
        {
            jNum = "J000000" + to_string(rn);
        }
        else if (rn < 1000)
        {
            jNum = "J00000" + to_string(rn);
        }
        else if (rn < 10000)
        {
            jNum = "J0000" + to_string(rn);
        }
        else if (rn < 100000)
        {
            jNum = "J000" + to_string(rn);
        }
        else if (rn < 1000000)
        {
            jNum = "J00" + to_string(rn);
        }
        else if (rn < 10000000)
        {
            jNum = "J0" + to_string(rn);
        }
        else
        {
            jNum = "J" + to_string(rn);
        }
        // Add to array
        jNumArr[i] = jNum;
    }
    // delcare collison array
    // test array with Check Array FunctionS
    int testOneArr[127];
    int test = 0;
    int testOneResults = CheckArr(testOneArr, jNumArr, 100, 127);

    int testTwoArr[512];
    int testTwoResults = CheckArr(testTwoArr, jNumArr, 500, 512);

    int testThreeArr[1024];
    int testThreeResults = CheckArr(testThreeArr, jNumArr, 1000, 1024);

    int testFourArr[27000];
    int testFourResults = CheckArr(testFourArr, jNumArr, 25000, 2700);

    return 0;
}

int CheckArr(int countArr[], string jNums[], int sizeOfRun, int sizeOfCount)
{
    // set all in count array equal to -1
    for (int i = 0; i < sizeOfCount; i++)
    {
        countArr[i] = -1;
    }

    // has the function and place count the results
    for (int x = 0; x < sizeOfRun; x++)
    {
        countArr[hashFunc(jNums[x], sizeOfCount)]++;
    }
    int collisions = 0;
    int singleUse = 0;
    int nonUsed = 0;
    // count the collisions
    for (int y = 0; y < sizeOfCount; y++)
    {
        if (countArr[y] == -1)
        {
            nonUsed++;
        }
        if (countArr[y] == 0)
        {
            singleUse++;
        }
        if (countArr[y] > 0)
        {
            collisions += countArr[y];
        }
    }

    cout << " Run Size: " + to_string(sizeOfRun) + "\n";
    cout << " Unused: " + to_string(nonUsed) + "\n";
    cout << " Single Use: " + to_string(singleUse) + "\n";
    cout << " Collisions: " + to_string(collisions) + "\n";
    cout << "\n";

    return collisions;
}

int hashFunc(string jNum, int size)
{
    unsigned int hash = 0;

    int j = 0;
    int k = 0;

    hash = 0;
    for (int i = 0; i < jNum.length(); i++)
    {
        if (i % 2 == 0)
        {
            j = j + jNum[i];
        }
        else
        {
            k = k + jNum[i];
        }

        hash = (j * 13) + (k * 31);
    }
    return hash % size;
}