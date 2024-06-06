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

    int max(int cost1, int cost2) // returns the higher value
    {
        return cost1 > cost2 ? cost1 : cost2;
    }

    int height(Node *n) // checks for children nodes and returns hight of if there
    {
        return n == NULL ? -1 : n->getHeight();
    }

    int balanceFactor(Node* n) {
            return n == NULL ? -1 : height(n->getLeft()) - height(n->getRight()); 
        }

    void rotateRight(Node *n)
    {
        Node *temp1 = n->getLeft();
        Node *temp2 = temp1->getRight();

        temp1->setRight(n);
        n->setLeft(NULL);

        // change pointers in parent node if n is left or right
        if (n->getParent() != NULL)
        {
            if (n == n->getParent()->getLeft())
            {
                n->getParent()->setLeft(temp1);
            }
            if (n == n->getParent()->getRight())
            {
                n->getParent()->setRight(temp1);
            }
        }

            // update parent feild in nodes involved and lower child
            temp1->setParent(n->getParent());
            n->setParent(temp1);
            n->setLeft(temp2);
            if (temp2 != NULL)
            {
                temp2->setParent(n);
            }

            //null root check
            if (root == n)
            {
                root = temp1;
            }

            //set heights
            n->setHeight(max(height(n->getLeft()), height(n->getRight())) + 1);            
            temp1->setHeight(max(height(temp1->getLeft()), height(temp1->getRight())) + 1);
    }

    void rotateLeft(Node *n)
    {
        Node *temp1 = n->getRight();
        Node *temp2 = temp1->getLeft();

        temp1->setLeft(n);
        n->setRight(NULL);

        // change pointers in parent node if n is left or right
        if (n->getParent() != NULL)
        {
            if (n == n->getParent()->getLeft())
            {
                n->getParent()->setLeft(temp1);
            }
            if (n == n->getParent()->getRight())
            {
                n->getParent()->setRight(temp1);
            }
        }

            // update parent feild in nodes involved and lower child
            temp1->setParent(n->getParent());
            n->setParent(temp1);
            n->setRight(temp2);
            if (temp2 != NULL)
            {
                temp2->setParent(n);
            }

            //null root check
            if (root == n)
            {
                root = temp1;
            }

            //set heights
            n->setHeight(max(height(n->getLeft()), height(n->getRight())) + 1);
            temp1->setHeight(max(height(temp1->getLeft()), height(temp1->getRight())) + 1);
    }


        void insert(Node * n, Storm s)
        {
            // greater than value check
            if (s.getCost() > n->getStorm().getCost())
            {
                // Null Check
                if (n->getRight() != NULL)
                {
                    // recursive insert call
                    insert(n->getRight(), s);
                }
                else
                {
                    // set right child when child = null
                    n->setRight(new Node(s, n));
                }
            }
            // less than value check
            else if (s.getCost() < n->getStorm().getCost())
            {
                // null check
                if (n->getLeft() != NULL)
                {
                    // recusrive insert call with next left
                    insert(n->getLeft(), s);
                }
                else
                {
                    // set left when empty
                    n->setLeft(new Node(s, n));
                }
            }
            else
            {
                throw runtime_error("Value already exists in the BST");
            }

            n->setHeight(1 + max(height(n->getLeft()), height(n->getRight())));

            int b = balanceFactor(n);

            if((b > 1 || b < -1) && height(n->getLeft()) > height(n->getRight())) {
                rotateRight(n);
            }
            else if((b > 1 || b < -1) && height(n->getRight()) > height(n->getLeft())) {
                rotateLeft(n);
            }
        }

        // Cout when left probe returns
        void inorder(Node * n)
        {
            if (n == NULL)
            {
                return;
            }
            inorder(n->getLeft());
            cout << n->getStorm().getName() << " ";
            inorder(n->getRight());
        }

        void preorder(Node * n)
        {
            if (n == NULL)
            {
                return;
            }
            // print storm value at force apperance
            cout << n->getStorm().getName() << " ";
            preorder(n->getLeft());
            preorder(n->getRight());
        }

        // Cout at end of right probe
        void postorder(Node * n)
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

        // traverse order
        // 1 in order
        // 2 preoder
        // 3 postorder
        void traverse(int type)
        {
            switch (type)
            {
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