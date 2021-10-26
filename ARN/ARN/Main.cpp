// ARN.cpp :

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "ArbolRN.h"
# include "Gestor.h"
# include "Validar.h"

Validar validar;
Gestor gestor;
ArbolRN tree;
int ingresarNum(string);
void insertarEnARN();
void preOrden();
void postOrden();
void inOrden();
void mostar();
int main()
{
    int opc, x = 0;
  

    //Menu principal
    do
    {
        system("cls");
        cout << "\n\t ARBOL ROJO NEGRO";
        cout << "\n 1. Insertan en el arbol";
        cout << "\n 2. Borrar un nodo del arbol";
        cout << "\n 3. Buscar elemento en el arbol";
        cout << "\n 4. Mostrar el arbol";
        cout << "\n 5. Arbol PreOrden";
        cout << "\n 6. Arbol PostOrden";
        cout << "\n 7. Arbol InOrden";
        cout << "\n 8. Salir";
        cout << "\n Ingrese la opcion"; cin >> opc;
        switch (opc)
        {

        case 1:
            insertarEnARN();
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
            mostar();
            system("pause");
            break;

        case 5:
            preOrden();
            system("pause");
            break;

        case 6:
            postOrden();
            system("pause");
            break;

        case 7:
            inOrden();
            system("pause");
            break;

        case 8:
            x = 1;
            break;


        default: cout << "\n Ingrese una opción valida.";
        }
        cout << endl;
    } while (x!=1);
    return 1;
}

void mostar() {
    gestor.mostrar();
}

void preOrden() {
    cout << "\n PreOrden:";
        cout << gestor.preOrden() << endl;
}

void postOrden() {
    cout << "\n PostOrden:";
        cout << gestor.postOrden() << endl;
    
}

void inOrden() {
    cout << "\n InOrden:";
        cout << gestor.inOrden() << endl;
}


void insertarEnARN() {
    string msg = "Ingrese la cantidad de numeros que desea cargar al arbol AVL\n";
    int ciclos = ingresarNum(msg);
    for (int i = 0; i < ciclos; ++i) {
        msg = "ingrese el valor " + to_string(i + 1);
        bool carga = gestor.insertarElem(ingresarNum(msg));
        if (carga) {
            cout << "Cargado satisfactoriamente el valor ingresado\n";
        }
        else {
            cout << "No se cargo el valor ingresado; ya existe en el arbol AVL\n";
        }
    }
    cout << "Finalizado el procesamiento de datos\n";
}



int ingresarNum(string msg) {
    int num;
    string valor;
    do {
        cout << msg << endl;
        cin >> valor;
        num = validar.ingresarInt(valor);
        if (num == -1) {
            cout << "El valor ingresado es incorrecto\nVuelva a intentarlo\n";
        }
    } while (num == -1);
    return num;
}