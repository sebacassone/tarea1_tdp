#include "AVLTree.h"

int main()
{
    AVLTree *avl = new AVLTree();

    // Insertar nodos en el árbol AVL
    avl->insert(10);
    avl->insert(20);
    avl->insert(30);
    avl->insert(40);
    avl->insert(50);
    avl->insert(25);

    // Imprimir el árbol AVL en orden
    avl->printInorder();

    // Buscar un valor en el árbol AVL
    avl->search(30);

    // Eliminar un nodo del árbol AVL
    avl->remove(30);

    // Imprimir el árbol AVL después de eliminar el nodo
    avl->printInorder();

    // Buscar el valor eliminado en el árbol AVL
    avl->search(30);

    delete avl;

    return 0;
}
