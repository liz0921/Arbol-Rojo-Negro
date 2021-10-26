#pragma once
#include "ArbolRN.h"
#include <iostream>
using namespace std;

class Gestor {
private:
    ArbolRN* arbolRN;
public:
    Gestor();

    ArbolRN* getArbolARN() const;
    void setArbolARN(ArbolRN* arbolRN);
    bool insertarElem(int);
    bool esVacio();
    void mostrar();
    string preOrden(); // Imprime el Arbin de forma RID (raíz - izquierda - derecha)

    string inOrden(); // Imprime el Arbin de forma IRD (izquierda - raíz - derecha)

    string postOrden(); // Imprime el Arbin de forma IDR (izquierda - derecha - raíz)


};

