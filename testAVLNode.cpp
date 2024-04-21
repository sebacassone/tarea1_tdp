#include "AVLTreeNode.h"

int main(void)
{
    AVLNode *node = new AVLNode(10);
    AVLNode *node2 = new AVLNode(20);
    AVLNode *node3 = new AVLNode(30);
    AVLNode *node4 = new AVLNode(40);
    AVLNode *node5 = new AVLNode(50);
    AVLNode *node6 = new AVLNode(25);

    node->left = node2;
    node->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;

    return 0;
}