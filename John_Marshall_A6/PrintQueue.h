#ifndef PRINTQUE_H
#define PRINTQUE_H
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;



class PrintQue
{
    private:
    Node *head;
    Node *tail;

    public:
    PrintQue()
    {
      this->head = NULL;
      this->tail = NULL;
    }

    void push(PrintJob p)
    {
        Node *temp = new Node();
        temp->setData(p);

        if(this->tail == NULL)
        {
            this->head = temp;
        }
        else
        {
            tail->setNext(temp);
        }
        this->tail = temp;
    }

    PrintJob pop()
    {
        if(this->head == NULL)
        {
            throw std::out_of_range ("que is empty");
        }
        PrintJob tempJob = this->head->getData();
        Node *tempNode = this->head->getNext();
        free(this->head);
        this->head = tempNode;
        return tempJob;

    }

    bool isEmpty()
    {
        if(this->head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};
#endif