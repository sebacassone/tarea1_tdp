#include "AVLTree.h"

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree()
{
    destroyTree(root);
}

void AVLTree::destroyTree(State *root)
{
    if (root != nullptr)
    {
        destroyTree(root->izqNodo);
        destroyTree(root->derNodo);
        delete root;
    }
}

int AVLTree::height(State *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::balanceFactor(State *node)
{
    if (node == nullptr)
        return 0;
    return height(node->izqNodo) - height(node->derNodo);
}

State *AVLTree::rotatederNodo(State *y)
{
    State *x = y->izqNodo;
    State *T2 = x->derNodo;

    x->derNodo = y;
    y->izqNodo = T2;

    y->height = std::max(height(y->izqNodo), height(y->derNodo)) + 1;
    x->height = std::max(height(x->izqNodo), height(x->derNodo)) + 1;

    return x;
}

State *AVLTree::rotateizqNodo(State *x)
{
    State *y = x->derNodo;
    State *T2 = y->izqNodo;

    y->izqNodo = x;
    x->derNodo = T2;

    x->height = std::max(height(x->izqNodo), height(x->derNodo)) + 1;
    y->height = std::max(height(y->izqNodo), height(y->derNodo)) + 1;

    return y;
}

State *AVLTree::insertNode(State *node, int value)
{
    if (node == nullptr)
        return new State(value);

    if (value < node->distancia)
        node->izqNodo = insertNode(node->izqNodo, value);
    else if (value > node->distancia)
        node->derNodo = insertNode(node->derNodo, value);
    else
        return node;

    node->height = 1 + std::max(height(node->izqNodo), height(node->derNodo));

    int balance = balanceFactor(node);

    if (balance > 1 && value < node->izqNodo->distancia)
        return rotatederNodo(node);

    if (balance < -1 && value > node->derNodo->distancia)
        return rotateizqNodo(node);

    if (balance > 1 && value > node->izqNodo->distancia)
    {
        node->izqNodo = rotateizqNodo(node->izqNodo);
        return rotatederNodo(node);
    }

    if (balance < -1 && value < node->derNodo->distancia)
    {
        node->derNodo = rotatederNodo(node->derNodo);
        return rotateizqNodo(node);
    }

    return node;
}

State *AVLTree::minValueNode(State *node)
{
    State *current = node;
    while (current->izqNodo != nullptr)
        current = current->izqNodo;
    return current;
}

State *AVLTree::deleteNode(State *root, int value)
{
    if (root == nullptr)
        return root;

    if (value < root->distancia)
        root->izqNodo = deleteNode(root->izqNodo, value);
    else if (value > root->distancia)
        root->derNodo = deleteNode(root->derNodo, value);
    else
    {
        if (root->izqNodo == nullptr || root->derNodo == nullptr)
        {
            State *temp = root->izqNodo ? root->izqNodo : root->derNodo;

            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            State *temp = minValueNode(root->derNodo);
            root->distancia = temp->distancia;
            root->derNodo = deleteNode(root->derNodo, temp->distancia);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + std::max(height(root->izqNodo), height(root->derNodo));

    int balance = balanceFactor(root);

    if (balance > 1 && balanceFactor(root->izqNodo) >= 0)
        return rotatederNodo(root);

    if (balance > 1 && balanceFactor(root->izqNodo) < 0)
    {
        root->izqNodo = rotateizqNodo(root->izqNodo);
        return rotatederNodo(root);
    }

    if (balance < -1 && balanceFactor(root->derNodo) <= 0)
        return rotateizqNodo(root);

    if (balance < -1 && balanceFactor(root->derNodo) > 0)
    {
        root->derNodo = rotatederNodo(root->derNodo);
        return rotateizqNodo(root);
    }

    return root;
}

void AVLTree::inorder(State *root)
{
    if (root == nullptr)
        return;
    inorder(root->izqNodo);
    std::cout << root->distancia << " ";
    inorder(root->derNodo);
}

void AVLTree::insert(int value)
{
    root = insertNode(root, value);
}

void AVLTree::remove(int value)
{
    root = deleteNode(root, value);
}

void AVLTree::search(int value)
{
    State *node = root;
    while (node != nullptr)
    {
        if (node->distancia == value)
        {
            std::cout << "El valor " << value << " está presente en el árbol AVL." << std::endl;
            return;
        }
        else if (node->distancia < value)
            node = node->derNodo;
        else
            node = node->izqNodo;
    }
    std::cout << "El valor " << value << " no está presente en el árbol AVL." << std::endl;
}

void AVLTree::printInorder()
{
    std::cout << "Recorrido inorder del árbol AVL:" << std::endl;
    inorder(root);
    std::cout << std::endl;
}
