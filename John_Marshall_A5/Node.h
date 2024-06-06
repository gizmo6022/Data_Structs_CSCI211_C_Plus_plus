#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include "Storm.h"

using namespace std;

class Node
{
private:
	Storm storm;
	Node *next;
	Node *previous;

public:
	//constructors
	Node()
	{
		this->storm = Storm();
		this->next = NULL;
		this->previous = NULL;
	}

	Node(Storm s, Node *next, Node *previous)
	{
		this->storm = s;
		this->next = next;
		this->previous = previous;
	}

	//gets
	
	Storm getStorm()
	{
		return this->storm;
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

	void setStorm(Storm s)
	{
		this->storm = s;
	}

	void setPrevious(Node *n)
	{
		this->previous = n;
	}

	
};
#endif
