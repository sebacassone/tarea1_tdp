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
    AVLNode *insertNode(AVLNode *node, int value);
    AVLNode *minValueNode(AVLNode *node);
    AVLNode *deleteNode(AVLNode *root, int value);
    void inorder(AVLNode *root);
    void destroyTree(AVLNode *root);
    AVLTree();
    ~AVLTree();
    void insert(int value);
    void remove(int value);
    void search(int value);
    void printInorder();
};

#endif // AVLTREE_H
