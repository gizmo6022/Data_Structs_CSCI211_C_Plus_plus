#ifndef FIRESTATIONLIST_H
#define FIRESTATIONLIST_H
#include <iostream>
#include <string.h>
#include "Node.h"
using namespace std;

class FireStationList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    // constructors
    FireStationList()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
    // deconstructors
    ~FireStationList()
    {
        if (this->head != NULL)
        {
            delete this->head;
        }

        this->head = NULL;
        this->tail = NULL;
    }

//Push
    void push(FireStation fs)
    {
        Node *temp = new Node;
        temp->setFireStation(fs);
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
//Insert
    void insert(FireStation newStation, int index)
    {
        Node *temp = this->head;
        int counter = 0;
        while (counter < index - 1 && temp != NULL)
        {
            temp = temp->getNext();
            counter++;
        }

        Node *newNode = new Node;
        newNode->setFireStation(newStation);
        newNode->setNext(temp->getNext());
        newNode->setPrevious(temp->getPrevious());
        temp->getNext()->setPrevious(newNode);
        temp->getNext()->setNext(newNode);
        this->size++;
    }
//set 
    void set(FireStation fs, int i)
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
        current->setFireStation(fs);
        return;
    }
    
//get
    FireStation get(int i)
    {
        if (i < 0 || head == NULL)
        {
            return FireStation();
        }
        Node *current = this->head;

        // iterate list to find desired index
        for (int x = 0; current != NULL && x < i; x++)
        {
            current = current->getNext();
        }
        if (current == NULL)
        {
            return FireStation();
        }
        return current->getFireStation();
    }

    int getSize()
    {
        return this->size;
    }

//sort
    void bubbleSort(int length)
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
                if (current->getFireStation().getStation() > current->getNext()->getFireStation().getStation())
                {
                    FireStation temp = current->getNext()->getFireStation();
                    current->getNext()->setFireStation(current->getFireStation());
                    current->setFireStation(temp);
                }
                current = current->getNext();
            }
        }
        bubbleSort(length - 1);
    }
//prints
    void printForward()
    {
        if (this->head != NULL)
        {
            Node *current = this->head;
            cout << (current->getFireStation().toString() + "\n");

            while (current->getNext() != NULL)
            {
                cout << (current->getNext()->getFireStation().toString() + "\n");
                current = current->getNext();
            }
        }
    }

    void printBackward()
    {
        if (this->tail != NULL)
        {
            Node *current = this->tail;
            cout << (current->getFireStation().toString() + "\n");

            while (current->getPrevious() != NULL)
            {
                cout << (current->getPrevious()->getFireStation().toString() + "\n");
                current = current->getPrevious();
            }
        }
    }
};
#endif
