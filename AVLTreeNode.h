#include <iostream>

class AVLNode
{
public:
    int data;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(int value);
};
