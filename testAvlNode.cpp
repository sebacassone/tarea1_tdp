#include "AVLTreeNode.h"

int main(void)
{
    // Se crean los estados
    State *state = new State(2, nullptr);
    State *state2 = new State(2, state);
    State *state3 = new State(2, state2);
    State *state4 = new State(2, state3);
    State *state5 = new State(2, state4);
    State *state6 = new State(2, state5);

    // Se crean los nodos nuevos
    AVLNode *node = new AVLNode(state);
    AVLNode *node2 = new AVLNode(state2);
    AVLNode *node3 = new AVLNode(state3);
    AVLNode *node4 = new AVLNode(state4);
    AVLNode *node5 = new AVLNode(state5);
    AVLNode *node6 = new AVLNode(state6);

    // Se imprime los valores de los nodos
    node->state->print();
    std::cout << "Node: " << node->state->size << std::endl;
    std::cout << "Node2: " << node2->state->size << std::endl;
    std::cout << "Node3: " << node3->state->size << std::endl;
    std::cout << "Node4: " << node4->state->size << std::endl;
    std::cout << "Node5: " << node5->state->size << std::endl;
    std::cout << "Node6: " << node6->state->size << std::endl;

    return 0;
}