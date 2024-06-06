#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <string>
#include "Storm.h"
#include "Node.h"

class MinHeap
{
private:
    const int arraySize = 16;
    Node *array[16] = {};
    int nextAvailable;

    // gets parent of given index
    int getParentIndex(int i)
    {
        return i / 2;
    }

    // gets left child of given index
    int getLeftChildIndex(int i)
    {
        return i * 2;
    }

    // gets right Child of given index
    int getRightChildIndex(int i)
    {
        return i * 2 + 1;
    }

    // turns if index has child
    bool hasChildren(int i)
    {
        int left = getLeftChildIndex(i);
        int right = getRightChildIndex(i);
        // check if indexs exceeds array size
        if (left >= arraySize)
        {
            return false;
        }
        // check if they have No child nodes
        else if (array[left] == NULL && array[right] == NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    // swap values without swapping values
    void swap(Node *s1, Node *s2)
    {
        Storm s = s1->getStorm();
        s1->setStorm(s2->getStorm());
        s2->setStorm(s);
    }

    // makes sure all values are greater than parent
    void fixHeap()
    {
        int i = 1;                      // root Node
        Storm s = array[i]->getStorm(); // get Strom
        while (hasChildren(i))
        {
            Node *left = array[getLeftChildIndex(i)];
            Node *right = array[getRightChildIndex(i)];
            if (left != NULL)
            {
                // At least a left child
                if (right != NULL)
                {
                    // has both children
                    if (left->getStorm().getCost() < right->getStorm().getCost())
                    {
                        // left is smaller? swap and change working index
                        if (s.getCost() > left->getStorm().getCost())
                        {
                            swap(array[i], left);
                            i = getLeftChildIndex(i);
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        // righ child is smallest
                        if (s.getCost() > right->getStorm().getCost())
                        {
                            swap(array[i], right);
                            i = getRightChildIndex(i);
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                // no right
                else
                {
                    if (s.getCost() > left->getStorm().getCost())
                    {
                        swap(array[i], left);
                        i = getLeftChildIndex(i);
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            // is bottom leaf
            else
            {
                break;
            }
        }
    }

public:
    // Constructor
    MinHeap()
    {
        nextAvailable = 1;
    }

    // Adds node to heap
    void add(Storm s)
    {
        // check if heap is full
        if (nextAvailable > arraySize - 1)
        {
            return;
        }
        // place storm into next available
        array[nextAvailable] = new Node(s);

        int p = getParentIndex(nextAvailable);
        int i = nextAvailable;
        // iterate through until parent is/self it root and swap values until in the right place
        while (p >= 1)
        {
            if (array[p]->getStorm().getCost() > s.getCost())
            {
                swap(array[p], array[i]);
            }
            i = p;
            p = getParentIndex(p);
        }
        // incrment next available
        nextAvailable++;
    }

    // remove
    Storm remove()
    {
        // is heap empty
        if (array[1] == NULL)
        {
            return Storm();
        }

        // get root storm
        Storm r = array[1]->getStorm();
        // reduce next avaliable
        nextAvailable--;
        // is last node check
        if (nextAvailable == 1)
        {
            array[nextAvailable] = NULL;
        }
        // set root node to next available storm, set next to null and fix heap
        else
        {
            array[1]->setStorm(array[nextAvailable]->getStorm());
            array[nextAvailable] = NULL;
            fixHeap();
        }
        return r;
        // return popped storm
    }

    // is Empty?
    bool isEmpty()
    {
        return nextAvailable == 1 ? true : false;
    }
};

#endif
