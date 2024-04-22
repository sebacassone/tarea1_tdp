#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLTreeNode.h"

class AVLTree
{
public:
    AVLNode *root;

    int height(AVLNode *node);
    int balanceFactor(AVLNode *node);
    AVLNode *rotateRight(AVLNode *y);
    AVLNode *rotateLeft(AVLNode *x);
    AVLNode *insertNode(AVLNode *node, State *value);
    AVLNode *minValueNode(AVLNode *node);
    AVLNode *deleteNode(AVLNode *root, State *value);
    void inorder(AVLNode *root);
    void destroyTree(AVLNode *root);
    AVLTree();
    ~AVLTree();
    void push(State *value);
    void pop();
    void search(int value);
    void printInorder();
};

#endif // AVLTREE_H
