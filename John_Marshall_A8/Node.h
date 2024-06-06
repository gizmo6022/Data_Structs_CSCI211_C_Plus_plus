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
	Node *left;
	Node *right;
	Node *parent;

public:
	// constructors
	Node()
	{
		this->storm = Storm();
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}

	Node(Storm s, Node *p)
	{
		this->storm = s;
		this->left = NULL;
		this->right = NULL;
		this->parent = p;
	}

	// gets

	Storm getStorm()
	{
		return this->storm;
	}

	Node *getLeft()
	{
		return this->left;
	}

	Node *getRight()
	{
		return this->right;
	}
	Node *getParent()
	{
		return this->parent;
	}

	// sets
	void setLeft(Node *n)
	{
		this->left = n;
	}

	void setStorm(Storm s)
	{
		this->storm = s;
	}

	void setRight(Node *n)
	{
		this->right = n;
	}
};
#endif
