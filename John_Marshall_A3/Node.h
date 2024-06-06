
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include "Storm.h"
using namespace std;

class Node
{
private:
	Storm s;
	Node *next;
public:
	Node(){
		this->s= Storm();
		this->next = NULL;
	}
	void setStorm (Storm s){
		this->s = s;
	}
	
	Storm getStorm(){
		return this->s;
	}
	
	void setNext(Node *n){
		this->next = n;
	}
	
	Node *getNext(){
		return this->next;
	}
	
	Node *push(Node *nextNode)
    {
        if (this->next == NULL)
        {
            this->next = nextNode;
            return this->next;
        }
        else
        {
            return this->next->push(nextNode);
        }
    }	
};
#endif
