#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLTreeNode.h"
#include "State.h"

class AVLTree
{
public:
    State *root;

    int height(State *node);
    int balanceFactor(State *node);
    State *rotatederNodo(State *y);
    State *rotateizqNodo(State *x);
    State *insertNode(State *node, int value);
    State *minValueNode(State *node);
    State *deleteNode(State *root, int value);
    void inorder(State *root);
    AVLTree();
    ~AVLTree();
    void destroyTree(State *root);
    void insert(int value);
    void remove(int value);
    void search(int value);
    void printInorder();
};

#endif /* AVLTREE_H */
