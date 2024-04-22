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

    // Se imprime los valores de los nodos
    std::cout << "Valor del nodo: " << node->data << std::endl;
    std::cout << "Valor del nodo izquierdo: " << node->left->data << std::endl;
    std::cout << "Valor del nodo derecho: " << node->right->data << std::endl;
    std::cout << "Valor del nodo izquierdo del nodo izquierdo: " << node->left->left->data << std::endl;
    std::cout << "Valor del nodo derecho del nodo izquierdo: " << node->left->right->data << std::endl;
    std::cout << "Valor del nodo izquierdo del nodo derecho: " << node->right->left->data << std::endl;

    return 0;
}