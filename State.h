#include <iostream>

/// vamos a definir la clase State de manera abstracta
class State
{
public:
    // Atributos
    int **board; // tablero size x size
    int size;
    // al cargar el archivo busco donde esta el 0
    int i0;        // fila del cero
    int j0;        // columna del cero
    int distancia; // la distancia obtenido con heuristica
    State *parent;

    // Para el árbol
    State *izqNodo;
    State *derNodo;
    int height;

    // Metodos
    State();
    State(int size);
    State(int size, State *parent);
    State(int size, State *parent, int **board);
    bool isSol(); // verifica si es solucion
    ~State();
    void print(); // print recursively
    void print_board();
    State *up();
    State *down();
    State *left();
    State *right();
    State *copy();
    int setDistancia(State *estado); // setea la distancia según la heurística
    int manhattanDistance();
    int countMisplacedTiles();
    bool equals(State *s); // compara dos estados
                           // bool equals(State *s); // compara dos estados
};