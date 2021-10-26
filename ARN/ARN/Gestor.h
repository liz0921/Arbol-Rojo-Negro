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
    string preOrden(); // Imprime el Arbin de forma RID (ra�z - izquierda - derecha)

    string inOrden(); // Imprime el Arbin de forma IRD (izquierda - ra�z - derecha)

    string postOrden(); // Imprime el Arbin de forma IDR (izquierda - derecha - ra�z)


};

