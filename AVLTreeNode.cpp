#include "AVLTreeNode.h"

AVLNode::AVLNode(int value)
{
    data = value;
    left = nullptr;
    right = nullptr;
    height = 1;
}