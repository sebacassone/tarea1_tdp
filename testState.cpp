#include "State.h"

int main()
{
    int size = 2;
    int size2 = 5;
    int **board;
    board = new int *[size];
    for (int i = 0; i < size; i++)
    {
        board[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            board[i][j] = i * 2 + j;
        }
    }
    int **board1;
    board1 = new int *[size];
    for (int i = 0; i < size; i++)
    {
        board1[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            board1[i][j] = i + j * 2;
        }
    }
    int **board2;
    board2 = new int *[size2];
    // Genera un tablero de 5x5 con valores del 0 al 24 sin repetir de manera aleatoria
    for (int i = 0; i < size2; i++)
    {
        board2[i] = new int[size2];
        for (int j = 0; j < size2; j++)
        {
            board2[i][j] = i * size2 + j;
        }
    }
    State *s = new State(size, nullptr, board);
    State *s1 = new State(size, nullptr, board1);
    State *s2 = new State(size2, nullptr, board2);
}