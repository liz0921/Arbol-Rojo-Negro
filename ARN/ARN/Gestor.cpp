#include "Gestor.h"

Gestor::Gestor() {
    arbolRN = new ArbolRN();
}
ArbolRN* Gestor::getArbolARN() const
{
    return arbolRN;
}
void Gestor::setArbolARN(ArbolRN* arbolRN)
{
    arbolRN = arbolRN;
}
bool Gestor::insertarElem(int pValor)
{
    return arbolRN->insertar(pValor);
}
string Gestor::preOrden() {
    string preorden = getArbolARN()->preOrden();

    preorden = preorden.substr(0, preorden.length() - 3);
    return preorden;
}

string Gestor::postOrden() {
    string postOrden = getArbolARN()->postOrden();
    postOrden = postOrden.substr(0, postOrden.length() - 3);
    return postOrden;
}
string Gestor::inOrden() {
    string inOrden = getArbolARN()->inOrden();
    inOrden = inOrden.substr(0, inOrden.length() - 3);
    return inOrden;
}


bool Gestor::esVacio() {
    return arbolRN->esVacioARN();
}

void Gestor::mostrar()
{
    getArbolARN()->mostrar();
}
