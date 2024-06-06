//John Marshall HW6
#include <iostream>
#include <string>
#include "PrintQueue.h"

using namespace std;



int main()
{   
    PrintQue que = PrintQue();
    int jobNum = 1;
    string input ="";
    cout << "Would you like to 'ADD', 'PRINT', or 'EXIT'?\n";
    cin >> input;
    while(input != "EXIT")
    {
        if(input == "ADD")
        {
            try{
                int pageNum;
                cout << "How many pages will be printed?\n";
                cin >> pageNum;
                PrintJob newJob = PrintJob(jobNum, pageNum);
                que.push(newJob);
                cout << "Pint Created. Que Position: ";
                cout << jobNum;
                cout << "\n";
                jobNum++;

            } catch (...){
                cout << "Please enter a valid whole number\n";
            }
            

        }
        else if(input == "PRINT")
        {
            if(!que.isEmpty()){
                PrintJob currentJob = que.pop();
                cout << "Job ID: ";
                cout << currentJob.getJobID();
                cout << "\n";
                cout << "Number of Pages: ";
                cout << currentJob.getNumPages();
                cout << "\n";
            }
            else
            {
                cout << "No Jobs in Que. \n";
            }
        }
        
        
    cout << "Please type 'ADD', 'PRINT', or 'EXIT'?\n";
    cin >> input;

    }
    cout << "Goodbye. \n";
    return 0;
}