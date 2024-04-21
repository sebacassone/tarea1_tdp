#include "Puzzle.h"

int main()
{
    int size = 2;
    Puzzle *p = new Puzzle();
    p->board = new int *[size];
    p->size = size;

    for (int i = 0; i < size; i++)
    {
        p->board[i] = new int[size];
    }
    p->board[0][0] = 0;
    p->board[0][1] = 1;
    p->board[1][0] = 3;
    p->board[1][1] = 2;

    p->solve();

    return 0;
}