#pragma once
#include <iostream>
#include "Nodo.h"
using namespace std;
class ArbolRN :Nodo//Hereda los valores de nodo.
{
	//private:
		//inicializamos objetos de la clase nodo
	Nodo* raiz;
	Nodo* q;// ayuda para rellenar poco a poco el arbol. 

	string preOrdenRecursivo(Nodo*); // Imprime el Arbin de forma RID (raíz - izquierda - derecha)

	string inOrdenRecursivo(Nodo*); // Imprime el Arbin de forma IRD (izquierda - raíz - derecha)

	string postOrdenRecursivo(Nodo*); // Imprime el Arbin de forma IDR (izquierda - derecha - raíz)
public:
	ArbolRN()//constructor 
	{
		//vaciamos objetos
		q = NULL;
		raiz = NULL;
	}

	//Metodos a usar:
	bool insertar(int);//insertar el nodo.
	bool insertarElemento(int);
	bool esVacioARN();
	bool existeElemento(int);
	bool acomodar(Nodo*);//acomodar los nodos.
	void rotarIzquierda(Nodo*); //rotar izquierda.
	void rotarDerecha(Nodo*);//rotar derecha.
	void borrar();//borrar un nodo.
	Nodo* sucesor(Nodo*);
	void reparar(Nodo*);//raparar el arbol una vez borrado el nodo.
	void mostrar();// llama a la funcion mostrarArbol.
	void mostarArbol(Nodo*);//muestra las rutas del arbol.
	void buscar(); //busca un nodo en todo el arbol.

	string inOrden(); // Imprime el Arbin de forma IRD (izquierda - raíz - derecha)
	string postOrden(); // Imprime el Arbin de forma IDR (izquierda - derecha - raíz)
	string preOrden(); // Imprime el Arbin de forma RID (raíz - izquierda - derecha)

};

