#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include "FireStation.h"
using namespace std;

class Node
{
private:
	FireStation station;
	Node *next;
	Node *previous;

public:
	//constructors
	Node()
	{
		this->station = FireStation();
		this->next = NULL;
		this->previous = NULL;
	}

	Node(FireStation fs, Node *next, Node *previous)
	{
		this->station = fs;
		this->next = next;
		this->previous = previous;
	}

	//gets
	
	FireStation getFireStation()
	{
		return this->station;
	}

	Node *getNext()
	{
		return this->next;
	}

	Node *getPrevious()
	{
		return this->previous;
	}
	
	//sets
	void setNext(Node *n)
	{
		this->next = n;
	}

	void setFireStation(FireStation s)
	{
		this->station = s;
	}

	void setPrevious(Node *n)
	{
		this->previous = n;
	}

	
};
#endif
