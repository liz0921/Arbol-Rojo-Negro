// ARN.cpp :

#include <iostream>
#include <stdlib.h>
#include "ArbolRN.h"
using namespace std;


int main()
{
    int opc, x = 0;
    ArbolRN tree;

    //Menu principal
    do
    {
        system("cls");
        cout << "\n\t ARBOL ROJO NEGRO";
        cout << "\n 1. Insertan en el arbol";
        cout << "\n 2. Borrar un nodo del arbol";
        cout << "\n 3. Buscar elemento en el arbol";
        cout << "\n 4. Mostrar el arbol";
        cout << "\n 5. Salir";
        cout << "\n Ingrese la opcion"; cin >> opc;
        switch (opc)
        {

        case 1:
            tree.insertar();
            cout << "\n Nodo Insertado.\n";
            system("pause");
            break;

        case 2:
            tree.borrar();
            system("pause");
            break;

        case 3:
            tree.buscar();
            system("pause");
            break;
        case 4:
            tree.mostrar();
            system("pause");
            break;

        case 5:
            x = 1;
            break;

        default: cout << "\n Ingrese una opción valida.";
        }
        cout << endl;
    } while (x!=1);
    return 1;
}

