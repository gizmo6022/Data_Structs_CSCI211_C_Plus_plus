#ifndef STORMTREE_H
#define STORMTREE_H
#include <iostream>
#include <string>
#include <queue>
#include "Node.h"

class StormTree
{
private:
    Node *root;

    void insert(Node *n, Storm s)
    {
            //greater than value check
        if (s.getCost() > n->getStorm().getCost())
        { 
            //Null Check
            if (n->getRight() != NULL)
            {   
                //recursive insert call
                insert(n->getRight(), s); 
            }
            else
            {
                //set right child when child = null
                Node *rTemp = new Node(s, n);
                n->setRight(rTemp);
            }
        }
        //less than value check
        else if (s.getCost() < n->getStorm().getCost())
        { 
            //null check
            if (n->getLeft() != NULL)
            {
                //recusrive insert call with next left
                insert(n->getLeft(), s);
            }
            else
            {
                //set left when empty
                n->setLeft(new Node(s, n));
            }
        }
        else
        {
            throw runtime_error("Value already exists in the BST"); // Can't have duplicate values in the BST
        }
    }

    //Cout when left probe returns
    void inorder(Node *n)
    {
        if (n == NULL)
        {
            return;
        }
        inorder(n->getLeft());
        cout << n->getStorm().getName() << " ";
        inorder(n->getRight());
    }

    void preorder(Node *n)
    {
        if (n == NULL)
        {
            return;
        }
        //print storm value at force apperance
        cout << n->getStorm().getName() << " ";
        preorder(n->getLeft());
        preorder(n->getRight());
    }

    //Cout at end of right probe
    void postorder(Node *n)
    {
        if (n == NULL)
        {
            return;
        }
        postorder(n->getLeft());
        postorder(n->getRight());
        cout << n->getStorm().getName() << " ";
    }

public:
    StormTree()
    {
        this->root = NULL;
    }

    void insert(Storm s)
    {

        if (root == NULL)
        {
            root = new Node(s, NULL);
        }
        else
        {
            insert(root, s);
        }
    }
    
    //traverse order
    //1 in order
    //2 preoder
    //3 postorder
    void traverse(int type)
    {
        switch(type){
            case 1:
                inorder(root);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                postorder(root);
                break;
            default:
             cout << "invalid input";
        }

    }


    void breadthFirst()
    {
        // check if tree is empty
        if (root == NULL)
        {
            return;
        }
        // create que
        queue<Node *> q;
        q.push(root);

        // get front and pop
        // print value then push left or right if they exist
        while (!q.empty())
        {
            int s = q.size();
            while (s > 0)
            {
                Node *current = q.front();
                q.pop();
                cout << current->getStorm().getName() << " ";
                if (current->getLeft() != NULL)
                {
                    q.push(current->getLeft());
                }
                if (current->getRight() != NULL)
                {
                    q.push(current->getRight());
                }

                s--;
            }
        }
    }
};

#endif