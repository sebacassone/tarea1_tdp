#include <iostream>
#include "State.h"

class AVLNode
{
public:
    State *state; // Estado del puzzle
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(State *state);
};
