#ifndef STORMLIST_H
#define STORMLIST_H
#include <iostream>
#include <string.h>
#include "Node.h"
using namespace std;

class StormList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    // constructors
    StormList()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
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

//Push
    void pushFront(Storm s)
    {
        Node *temp = new Node;
        temp->setStorm(s);
        temp->setNext(NULL);
        if (head == NULL)
        {
            temp->setPrevious(NULL);
            this->head = temp;
            this->tail = temp;
            this->size++;
            return;
        }
        else
        {
            this->tail->setNext(temp);
            temp->setPrevious(tail);
            this->tail = temp;
        }
        this->size++;
    }
//Push
    void pushBack(Storm s)
    {
        Node *temp = new Node;
        temp->setStorm(s);
        temp->setNext(NULL);
        if (head == NULL)
        {
            temp->setPrevious(NULL);
            this->head = temp;
            this->tail = temp;
            this->size++;
            return;
        }
        else
        {
            this->head->setPrevious(temp);
            temp->setNext(this->head);
            this->head = temp;
        }
        this->size++;
    }
//Insert
    void insert(Storm s, int index)
    {
        Node *temp = this->head;
        int counter = 0;
        while (counter < index - 1 && temp != NULL)
        {
            temp = temp->getNext();
            counter++;
        }

        Node *newNode = new Node;
        newNode->setStorm(s);
        newNode->setNext(temp->getNext());
        newNode->setPrevious(temp);
        newNode->getNext()->setPrevious(newNode);
        temp->setNext(newNode);
        this->size++;
    }
//get
    Storm get(int i)
    {
        if (i < 0 || head == NULL)
        {
            return Storm();
        }
        Node *current = this->head;

        // iterate list to find desired index
        for (int x = 0; current != NULL && x < i; x++)
        {
            current = current->getNext();
        }
        if (current == NULL)
        {
            return Storm();
        }
        return current->getStorm();
    }

    int getSize()
    {
        return this->size;
    }
    
//set
	void set(Storm s,int i)
    {
         if (i < 0 || head == NULL)
        {
            return;
        }
        Node *current = this->head;

        // iterate list to find desired index
        for (int x = 0; current != NULL && x < i; x++)
        {
            current = current->getNext();
        }
        if (current == NULL)
        {
            return;
        }
        current->setStorm(s);
        return;
	}

//sort
    void bubbleSortCategory(int length)
    {
        if (length == 1)
        {
            return;
        }
        Node *current = this->head;
        for (int i = 0; i < length; i++)
        {
            if (current->getNext() != NULL)
            {
                if (current->getStorm().getCategory() > current->getNext()->getStorm().getCategory())
                {
                    Storm temp = current->getNext()->getStorm();
                    current->getNext()->setStorm(current->getStorm());
                    current->setStorm(temp);
                }
                current = current->getNext();
            }
        }
        bubbleSortCategory(length - 1);
    }

    void bubbleSortCost(int length)
    {
        if (length == 1)
        {
            return;
        }
        Node *current = this->head;
        for (int i = 0; i < length; i++)
        {
            if (current->getNext() != NULL)
            {
                if (current->getStorm().getCost() > current->getNext()->getStorm().getCost())
                {
                    Storm temp = current->getNext()->getStorm();
                    current->getNext()->setStorm(current->getStorm());
                    current->setStorm(temp);
                }
                current = current->getNext();
            }
        }
        bubbleSortCost(length - 1);
    }
//prints
    void printForward()
    {
        if (this->head != NULL)
        {
            Node *current = this->head;
            cout << (current->getStorm().toString() + "\n");

            while (current->getNext() != NULL)
            {
                cout << (current->getNext()->getStorm().toString() + "\n");
                current = current->getNext();
            }
        }
    }

    void printBackward()
    {
        if (this->tail != NULL)
        {
            Node *current = this->tail;
            cout << (current->getStorm().toString() + "\n");

            while (current->getPrevious() != NULL)
            {
                cout << (current->getPrevious()->getStorm().toString() + "\n");
                current = current->getPrevious();
            }
        }
    }
};
#endif
