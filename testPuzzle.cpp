#include "Puzzle.h"
#include <ctime>

int main()
{
    int size = 5;
    Puzzle *p = new Puzzle();
    p->board = new int *[size];
    p->size = size;

    for (int i = 0; i < size; i++)
    {
        p->board[i] = new int[size];
    }
    p->board[0][0] = 6;
    p->board[0][1] = 1;
    p->board[0][2] = 2;
    p->board[0][3] = 3;
    p->board[0][4] = 4;

    p->board[1][0] = 11;
    p->board[1][1] = 12;
    p->board[1][2] = 7;
    p->board[1][3] = 8;
    p->board[1][4] = 5;

    p->board[2][0] = 16;
    p->board[2][1] = 17;
    p->board[2][2] = 0;
    p->board[2][3] = 9;
    p->board[2][4] = 10;

    p->board[3][0] = 21;
    p->board[3][1] = 18;
    p->board[3][2] = 13;
    p->board[3][3] = 14;
    p->board[3][4] = 15;

    p->board[4][0] = 22;
    p->board[4][1] = 23;
    p->board[4][2] = 24;
    p->board[4][3] = 19;
    p->board[4][4] = 20;

    // p->board[0][0] = 0;
    // p->board[0][1] = 1;
    // p->board[1][0] = 3;
    // p->board[1][1] = 2;

    time_t ti = clock();
    p->solve();
    time_t tf = clock();
    cout << "tiempo:" << (tf - ti);
    // CLOCKS_PER_SEC << " segundos" << endl;

    return 0;
}