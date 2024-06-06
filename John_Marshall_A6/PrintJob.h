#ifndef PRINTJOB_H
#define PRINTJOB_H
#include <iostream>
#include <string>

class PrintJob
{
    private:
    int jobID;
    int numPages;

    public:
    PrintJob(int id = 0, int pages = 0)
    {
        this->jobID = id;
        this->numPages = pages;
    }

    int getJobID()
    {
        return this->jobID;
    }

    int getNumPages()
    {
        return this->numPages;
    }

};
#endif