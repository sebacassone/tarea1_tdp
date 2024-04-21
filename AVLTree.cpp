#include "AVLTree.h"

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree()
{
    destroyTree(root);
}

void AVLTree::destroyTree(AVLNode *root)
{
    if (root != nullptr)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

int AVLTree::height(AVLNode *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::balanceFactor(AVLNode *node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

AVLNode *AVLTree::rotateRight(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode *AVLTree::rotateLeft(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode *AVLTree::insertNode(AVLNode *node, int value)
{
    if (node == nullptr)
        return new AVLNode(value);

    if (value < node->data)
        node->left = insertNode(node->left, value);
    else if (value > node->data)
        node->right = insertNode(node->right, value);
    else
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    if (balance > 1 && value < node->left->data)
        return rotateRight(node);

    if (balance < -1 && value > node->right->data)
        return rotateLeft(node);

    if (balance > 1 && value > node->left->data)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && value < node->right->data)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

AVLNode *AVLTree::minValueNode(AVLNode *node)
{
    AVLNode *current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

AVLNode *AVLTree::deleteNode(AVLNode *root, int value)
{
    if (root == nullptr)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        if (root->left == nullptr || root->right == nullptr)
        {
            AVLNode *temp = root->left ? root->left : root->right;

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
            AVLNode *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + std::max(height(root->left), height(root->right));

    int balance = balanceFactor(root);

    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && balanceFactor(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && balanceFactor(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && balanceFactor(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void AVLTree::inorder(AVLNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
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
    AVLNode *node = root;
    while (node != nullptr)
    {
        if (node->data == value)
        {
            std::cout << "El valor " << value << " está presente en el árbol AVL." << std::endl;
            return;
        }
        else if (node->data < value)
            node = node->right;
        else
            node = node->left;
    }
    std::cout << "El valor " << value << " no está presente en el árbol AVL." << std::endl;
}

void AVLTree::printInorder()
{
    std::cout << "Recorrido inorder del árbol AVL:" << std::endl;
    inorder(root);
    std::cout << std::endl;
}
