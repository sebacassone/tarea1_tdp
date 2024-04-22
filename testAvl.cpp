#include "AVLTree.h"
#include <algorithm>
#include <random>

int **createBoard()
{
    int **board = new int *[5];
    for (int i = 0; i < 5; ++i)
    {
        board[i] = new int[5];
    }

    // Genera una secuencia del 0 al 24
    std::vector<int> values(25);
    std::iota(values.begin(), values.end(), 0);

    // Mezcla la secuencia aleatoriamente
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(values.begin(), values.end(), g);

    // Llena el tablero con los valores mezclados
    int index = 0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            board[i][j] = values[index++];
        }
    }

    return board;
}

int main()
{
    AVLTree *avl = new AVLTree();

    // Crea 5 tableros de 5x5 con valores del 0 al 24 sin repetir y todos distintos entre si
    int **board1 = createBoard();
    int **board2 = createBoard();
    int **board3 = createBoard();
    int **board4 = createBoard();
    int **board5 = createBoard();

    // Crea 5 estados con los tableros creados
    State *state1 = new State(5, nullptr, board1);
    State *state2 = new State(5, nullptr, board2);
    State *state3 = new State(5, nullptr, board3);
    State *state4 = new State(5, nullptr, board4);
    State *state5 = new State(5, nullptr, board5);

    // Se muestran los tableros
    state1->print_board();
    std::cout << std::endl;
    state2->print_board();
    std::cout << std::endl;
    state3->print_board();
    std::cout << std::endl;
    state4->print_board();
    std::cout << std::endl;
    state5->print_board();

    // Crea las distancias y las asigna a los estados
    state1->distancia = state1->setDistancia(state1);
    state2->distancia = state2->setDistancia(state2);
    state3->distancia = state3->setDistancia(state3);
    state4->distancia = state4->setDistancia(state4);
    state5->distancia = state5->setDistancia(state5);

    // Imprime las distancias
    std::cout << "Distancia 1: " << state1->distancia << std::endl;
    std::cout << "Distancia 2: " << state2->distancia << std::endl;
    std::cout << "Distancia 3: " << state3->distancia << std::endl;
    std::cout << "Distancia 4: " << state4->distancia << std::endl;
    std::cout << "Distancia 5: " << state5->distancia << std::endl;

    // Inserta los estados en el árbol AVL
    avl->push(state1);
    avl->push(state2);
    avl->push(state3);
    avl->push(state4);
    avl->push(state5);

    // Imprime el recorrido inorder del árbol AVL
    avl->printInorder();

    delete avl;

    return 0;
}
