#include "State.h"
/*
Este archivo esta dedicado a definir los metodos de la clase State

*/

State::State()
{
    board = nullptr; // NULL
    size = 0;
    parent = nullptr;
}

State::State(int size)
{
    this->size = size;
    this->board = new int *[size];
    for (int i = 0; i < size; i++)
    {
        this->board[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            this->board[i][j] = 0;
        }
    }
    this->parent = nullptr;
}

State::State(int size, State *parent)
{
    this->size = size;
    this->board = new int *[size];
    // Se inicializa el tablero con 0
    for (int i = 0; i < size; i++)
    {
        this->board[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            this->board[i][j] = 0;
        }
    }
    this->parent = parent;
}
State::State(int size, State *parent, int **board)
{
    this->size = size;
    this->board = new int *[size];
    for (int i = 0; i < size; i++)
    {
        this->board[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            // std::cout << "i=" << i << " j=" << j << " board[i][j]=" << board[i][j] << std::endl;
            this->board[i][j] = board[i][j];
        }
    }
    this->parent = parent;
}

State::~State()
{
    int size = 0;
    for (int i = 0; i < this->size; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}

void State::print_board()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void State::print()
{
    static int callCount = 0;
    if (parent != nullptr)
    {
        parent->print();
    }

    std::cout << "Paso " << callCount++ << std::endl;
    print_board();
    std::cout << std::endl;
}

bool State::isSol()
{
    int k = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (this->board[i][j] != (k % (size * size)))
            {
                return false;
            }
            k++;
        }
    }
    return true;
}

State *State::copy()
{
    State *new_state = new State(size, this);
    new_state->board = new int *[size];
    for (int i = 0; i < size; i++)
    {
        new_state->board[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            new_state->board[i][j] = board[i][j];
        }
    }
    new_state->i0 = i0;
    new_state->j0 = j0;
    return new_state;
}

State *State::up()
{
    if (i0 != 0)
    { // si no esta en la primera fila entonces puedo subir el 0
        State *new_state = copy();
        new_state->board[i0][j0] = board[i0 - 1][j0];
        new_state->board[i0 - 1][j0] = 0;
        new_state->i0--;
        new_state->distancia = setDistancia(new_state);
        return new_state;
    }
    return (nullptr);
}

State *State::down()
{
    if (i0 != size - 1)
    { // si no esta en la última fila entonces puedo subir el 0
        State *new_state = copy();
        new_state->board[i0][j0] = board[i0 + 1][j0];
        new_state->board[i0 + 1][j0] = 0;
        new_state->i0++;
        new_state->distancia = setDistancia(new_state);
        return new_state;
    }
    return (nullptr);
}

State *State::right()
{
    if (j0 != size - 1)
    { // si no esta en la primera fila entonces puedo subir el 0
        State *new_state = copy();
        new_state->board[i0][j0] = board[i0][j0 + 1];
        new_state->board[i0][j0 + 1] = 0;
        new_state->j0++;
        new_state->distancia = setDistancia(new_state);
        return new_state;
    }
    return (nullptr);
}

State *State::left()
{
    if (j0 != 0)
    { // si no esta en la primera fila entonces puedo subir el 0
        State *new_state = copy();
        new_state->board[i0][j0] = board[i0][j0 - 1];
        new_state->board[i0][j0 - 1] = 0;
        new_state->j0--;
        new_state->distancia = setDistancia(new_state);
        return new_state;
    }
    return (nullptr);
}

bool State::equals(State *s)
{
    // comparamos solo el tablero
    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            if (this->board[i][j] != s->board[i][j])
            {
                return false;
            }
        }
    }
    // el resto de los elementos (size,parent,i0,j0) de state debiesen ser iguales
    // sino existe un error en la implementacion
    return true;
}

// Función para calcular la distancia de Manhattan
int State::manhattanDistance()
{
    int distance = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (board[i][j] != 0)
            {                                                          // Ignorar la casilla vacía
                int expected_i = (board[i][j] - 1) / size;             // Fila esperada
                int expected_j = (board[i][j] - 1) % size;             // Columna esperada
                distance += abs(i - expected_i) + abs(j - expected_j); // Calcular la distancia Manhattan
            }
        }
    }
    return distance;
}

// Función para contar el número de casillas mal colocadas
int State::countMisplacedTiles()
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (board[i][j] != 0 && board[i][j] != (i * size + j + 1))
            {            // Ignorar la casilla vacía y las colocadas correctamente
                ++count; // Incrementar el contador si la casilla no está en la posición correcta
            }
        }
    }
    return count;
}

double State::euclideanDistance()
{
    double distance = 0.0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            int value = board[i][j];
            if (value != 0)
            { // No calcular la distancia para el espacio vacío
                int targetRow = (value - 1) / size;
                int targetCol = (value - 1) % size;
                double dx = i - targetRow;
                double dy = j - targetCol;
                distance += sqrt(dx * dx + dy * dy); // Distancia euclidiana
            }
        }
    }
    return distance;
}

int State::setDistancia(State *estado)
{
    return estado->euclideanDistance();
}