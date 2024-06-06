#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>

#include "PrintJob.h"


class Node
{   
    private:
    PrintJob data;
    Node *next;

    public:
    Node()
    {
        this->data = PrintJob(0,0);
        this->next = NULL;
    }
    //getters
        PrintJob getData()
        {
            PrintJob temp = PrintJob(this->data.getJobID(), this->data.getNumPages());
            return temp;  
        }

        Node *getNext()
        {
            return this->next;
        }

    //setters
        void setData(PrintJob p)
        {
            this->data = p;
        }
        void setNext(Node *n)
        {
            this->next = n;
        }

};

#endif