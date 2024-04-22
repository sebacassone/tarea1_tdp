#include "Puzzle.h"

/// Aqui se implementan los cuerpo de las funciones

Puzzle::Puzzle()
{
    size = 0;
    board = nullptr;
    open = new AVLTree(); // sirve para almacenar los nodos abiertos (por visitar)
    all = new AVLTree();  // Sirve para almacenar todos los nodos visitados
}

State *Puzzle::generate_init()
{
    // asumiendo que board ya esta cargado
    State *e = new State(size, nullptr, board);
    e->parent = nullptr;
    e->i0 = -1; // caso de no encontrar el cero
    e->j0 = -1;
    e->distancia = e->setDistancia(e);
    if (board == nullptr)
    {
        cout << "No se ha cargado el tablero" << endl;
        return nullptr;
    }

    // buscar el cero
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == 0)
            {
                e->i0 = i;
                e->j0 = j;
                return e;
            }
        }
    }

    return e;
}

// Dado el nombre de dominio Puzzle (classe) defino la funcion Puzzle
// utiliza el algoritmo A* para resolver el puzzle
void Puzzle::solve()
{
    State *e_init = generate_init(); // genera el estado inicial con
    if (e_init == nullptr)
    {
        cout << "No se pudo generar el estado inicial" << endl;
        return;
    }
    open->push(e_init); // agrega en los abierto el tablero inicial
    all->push(e_init);  // agrega en todos (ex cerrados )el tablero inicial
    while (!open->isEmpty())
    {                           // mientras existan nodos por visitar
        State *e = open->pop(); // deberia obtener el mejor estado
        cout << "Estado actual:" << e << " i0:" << e->i0 << " j0:" << e->j0 << " size:" << e->size << " parent:" << e->parent << endl;
        if (e->isSol())
        {
            cout << "Encontramos la solucion:" << endl;
            e->print();
            return;
        }
        // Iterar sobre los posibles movimientos (arriba, abajo, izquierda, derecha)
        // for (auto move : {&State::up, &State::down, &State::left, &State::right})
        // {
        //     // Generar el nuevo estado aplicando el movimiento correspondiente
        //     State *new_state = (e->*move)(); // Llamar al método de movimiento dinámicamente
        //     // Verificar si el movimiento es válido y el estado no se ha explorado antes
        //     if (new_state != nullptr && !all->search(new_state))
        //     {
        //         // Agregar el nuevo estado a las listas open y all
        //         open->push(new_state);
        //         all->push(new_state);
        //     }
        // }
        State *e_up = e->up(); // si genera estado invalido, genera nullptr
        if (e_up != nullptr && // si es valido
            !all->search(e_up))
        { // si no esta en todos
            open->push(e_up);
            all->push(e_up);
        }

        State *e_down = e->down(); // si genera estado invalido, genera nullptr
        if (e_down != nullptr &&
            !all->search(e_down))
        {
            open->push(e_down);
            all->push(e_down);
        }

        State *e_left = e->left(); // si genera estado invalido, genera nullptr
        if (e_left != nullptr &&
            !all->search(e_left))
        {
            open->push(e_left);
            all->push(e_left);
        }

        State *e_right = e->right(); // si genera estado invalido, genera nullptr
        if (e_right != nullptr &&
            !all->search(e_right))
        {
            open->push(e_right);
            all->push(e_right);
        }
    }
    cout << "No se encontro solucion" << endl;
}