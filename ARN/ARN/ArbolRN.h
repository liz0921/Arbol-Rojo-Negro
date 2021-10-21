#pragma once
#include <iostream>
#include "Nodo.h"
using namespace std;
class ArbolRN:Nodo//Hereda los valores de nodo.
{
//private:
	//inicializamos objetos de la clase nodo
	Nodo* raiz;
	Nodo* q;// ayuda para rellenar poco a poco el arbol. 


public: 
	ArbolRN()//constructor 
	{
		//vaciamos objetos
		q = NULL; 
		raiz = NULL;
	}

//Metodos a usar:
	void insertar();//insertar el nodo.
	void acomodar(Nodo*);//acomodar los nodos.
	void rotarIzquierda(Nodo*); //rotar izquierda.
	void rotarDerecha(Nodo*);//rotar derecha.
	void borrar();//borrar un nodo.
	Nodo* sucesor(Nodo*);
	void reparar(Nodo*);//raparar el arbol una vez borrado el nodo.
	void mostrar();// llama a la funcion mostrarArbol.
	void mostarArbol(Nodo*);//muestra las rutas del arbol.
	void buscar(); //busca un nodo en todo el arbol.
};

