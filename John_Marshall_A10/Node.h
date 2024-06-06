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

public:
	// constructors
	Node()
	{
		this->storm = Storm();
	}

	Node(Storm s)
	{
		this->storm = s;
	}

	// gets

	Storm getStorm()
	{
		return this->storm;
	}

	// sets
	void setStorm(Storm s)
	{
		this->storm = s;
	}
};
#endif
