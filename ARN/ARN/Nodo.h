#pragma once
#include <iostream>
using namespace std;
class Nodo
{
public:
	Nodo();//constructor

	int valor;// valor del nodo 
	char color; //color del nodo
	Nodo* antecesor;
	Nodo* izquierdo; 
	Nodo* derecho; 
};

