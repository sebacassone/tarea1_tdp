#include "AVLTreeNode.h"

AVLNode::AVLNode(State *estado)
{
    state = estado;
    left = nullptr;
    right = nullptr;
    height = 1;
}