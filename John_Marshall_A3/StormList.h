#include <iostream>
#include <string.h>
#include "Node.h"
#include "Storm.h"
using namespace std;

class StormList
{
private:
    Node *head;
    Node *tail;
    int count;

public:
    // constructors
    StormList()
    {
        head = NULL;
        tail = NULL;
        count = 0;
    }
    // deconstructors
    ~StormList()
    {
        if (this->head != NULL)
        {
            delete this->head;
        }

        this->head = NULL;
        this->tail = NULL;
    }

    void push(Node *nextNode)
    {
        //is listed populated
        if (head == NULL)
        {
            head = nextNode;
            tail = nextNode;
        }
        else
        {
            tail = head->push(nextNode);
        }
        //increase list recorded size
        this->count++;
    }

    void insert(Storm s, int i)
    {
        // declare new
        Node *temp = this->head;

        // check if list is populated
        
        // find index position
        int wCount = 0;
        while (count < i - 1 && temp != NULL)
        {
            temp = temp->getNext();
            wCount++;
        }

        if (this->head == NULL || temp == NULL)
        {
            return;
        }

        // Data and Swap Next ptr
        Node *newNode = new Node();
        newNode->setStorm(s);
        newNode->setNext(temp->getNext());
        temp->setNext(newNode);
        this->count++;
    }

    Storm get(int i)
    {
        if(i < 0 || head == NULL){
            return Storm();
        }
        Node *current = this->head;

        //iterate list to find desired index
        for (int x = 0; current != NULL && x < i; x++)
        {
             current= current->getNext();
        }
        if (current == NULL){
            return Storm();
        }
        return current->getStorm();
    }


    int getSize()
    {
        return this->count;
    }
};
