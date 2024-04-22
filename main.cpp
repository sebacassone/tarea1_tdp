#include "Puzzle.h"
#include <ctime>

int main()
{
    Puzzle *p;

    // Se hace un menú para cargar el tablero
    // Menú principal
    int choice = 0;
    time_t ti, tf; // Declarar las variables fuera del switch
    string filename;
    int board_size;
    while (choice != 3)
    {
        cout << "Menú:" << endl;
        cout << "1. Cargar tablero desde archivo" << endl;
        cout << "2. Realizar otra operación" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese su elección: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            p = new Puzzle();
            cout << "Ingrese el nombre del archivo: ";
            cin >> filename;
            cout << "Ingrese el tamaño del tablero: ";
            cin >> board_size;
            p->load_board(filename, board_size);
            break;
        case 2:
            if (p->board == nullptr)
            {
                cout << "Primero debe cargar un tablero" << endl;
                break;
            }
            // Se resuelve el puzzle
            ti = clock();
            p->solve();
            tf = clock();
            cout << "Tiempo de carga: " << double(tf - ti) / CLOCKS_PER_SEC << " segundos" << endl;
            break;
        case 3:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Inténtelo de nuevo." << endl;
            break;
        }
    }
    return 0;
}