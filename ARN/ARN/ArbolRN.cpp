#include "ArbolRN.h"

void ArbolRN::insertar()
{
	//iniciamos el valor entero "z" para ingresar un valor al nodo.
	int z = 0;
	cout << "\n Entre el valor del nodo para ingresar:";
	cin >> z;
	Nodo * p, * q; //objetos de la clase nodo.
	Nodo* t = new (Nodo);
	//usamos t para ingresar los valores del nodo.
	t->valor = z;
	t->izquierdo = NULL;
	t->derecho = NULL;
	t->color = 'R';//Cargamos por defecto el color rojo.

	//Cargamos los valores de la raiz en el objeto p y vaciamos q.
	p = raiz; 
	q = NULL;

	// si la raiz esta vacia:
	if (raiz == NULL) {
		//NO tendra antecesores, sera la raiz
		raiz = t;
		t->antecesor = NULL;// se vacia para que no cree un archivo basura.
	}
	else
	{
		// si la raiz no esta vacia 
		while (p != NULL)
		{
			//cargamos p en q.
			q = p;
			//si el valor ingresado es mayor ira a la derecha.
			if(p->valor < t->valor){
				p = p->derecho;}
			//caso contraio a la izquierda.
			else
			p = p->izquierdo;
		}
			//cargamos "q" como antecesor (padre) de "t".
			t->antecesor = q;
			//verificamos a que lado iria el hijo izquierdo o derecho.
			if (q->valor < t->valor)
				q->derecho = t;
			else
				q->izquierdo = t; 
	}
	//llamamos al metodo acomodar  para crear el arbol cumpliendo las reglas.
	//enviamos objrto t
	acomodar(t);
}

void ArbolRN::acomodar(Nodo*t)
{
	Nodo* u; //creamos otro objeto de la clase nodo.
	//si la raiz es igual al nodo recibido el color sera negro.
	//la raiz siempre debe ser negra.
	if (raiz == t)
	{
		t->color = 'n';
		return;
	}
	//mientras que el antecesor no este vacio y el antecesor sea de color rojo
	// linea de codigo "45" se carga por defecto el color rojo.
	while (t->antecesor != NULL && t->antecesor->color =='r')
	{
		//creamos otro objeto de ayuda para los abuelos
		Nodo* g = t->antecesor->antecesor;
		//si el hijo izquierdo de "g" es igual al padre de "t"
		if (g->izquierdo == t->antecesor)
		{
		//si el hijo derecho de "g" no esta vacio
			if (g->valor!=NULL)
			{
				//Cargamos el hijo derecho de "g" en "u".
				u = g->derecho;
				//preguntamos si el color de "u" es rojo.
				if (u->color == 'r')
				{
					//cambiamos el color de su padre a negro.
					//no pueden haber 2 nodos rojos seguidos.
					t->antecesor->color = 'n';
					u->color = 'n';
					g->color = 'r';//cambiamos el color del abuelo a rojo.
					t = g;//cargamos "g" en "t".
				}
			}
			// si el hijo derecho de "g" esta vacio 
			else
			{
				//si el hijo derecho de "t" es igual a "t"
				if (t->antecesor->derecho == t)
				{
					//cargamos el padre de "t" y llamamos al metodo "rotarIzquierda"
					t = t->antecesor;
					rotarIzquierda(t);//rotamos "t" a la izquierda.
				}
				//le ponemos color negro al padre de "t".
				t->antecesor->color = 'n';
				//cargamos el color rojo a "g".
				g->color = 'r';
				rotarDerecha(g);// rotamos "g" a la derecha.
			}
		}
		// si el hijo izquierdo de "g" no es igual al padre de "t".
		else
		{
			// si el hijo izquierdo de "g" no esta vacio 
			if (g->izquierdo != NULL)
			{
				//cargamos el hijo izquierdo de "g" en "u".
				u = g->izquierdo;
				// si el color de "u" es rojo
				if(u->color == 'r'){
				// el padre de "t" sera negro
					t->antecesor->color = 'n';
					u->color = 'n';// color de u cambia a negro.
					g->color = 'r';//g cambia a rojo.
					t = g;
				}
			}
			// si el hijo izquierdo de g esta vacio
			else
			{
				//si el hijo izquierdo del padre de "t" es igual a "t".
				if (t->antecesor->izquierdo == t)
				{
					//cargamos el padre de "t".
					t = t->antecesor;
					rotarDerecha(t); //rotamos t a la derecha.
				}
				//el padre de "t" es de color negro.
				t->antecesor->color = 'n';
				g->color = 'r'; // el color de "g" sera rojo
				rotarIzquierda(g);// rotamos "g" a la izquierda.
			}
		}
		raiz->color = 'n';// la raiz siempre tiene que ser negra.
	}
}

void ArbolRN::rotarIzquierda(Nodo*p)
{
	//verifica que le hijo drecha no este vacio 
	if (p->derecho == NULL)
		return;
	else
	{
		Nodo* y = p->derecho; //carga la estructura del hijo derecho de "p" en "y".
		if (y->izquierdo != NULL)// si y tiene hijo izquierdo.
		{
			p->derecho = y->izquierdo; // carga el hijo izquierdo de "y" en el hijo derecho de "p"
			y->izquierdo->antecesor = p;//carga p en y .
		}
		else
			p->derecho = NULL;//p no tiene hijo derecho.
			if (p->antecesor != NULL)// si p tiene padre
				y->antecesor = p->antecesor; //carga el padre de p en el padre de y.
			if (p->antecesor == NULL)//si p es la raiz
				raiz = y; //carga y en la raiz.
			else
			{
				if (p == p->antecesor->izquierdo)// si p es el hijo izquierdo de su padre
					p->antecesor->izquierdo = y;// carga  y en p siendo este el hijo izquierdo.
				else
					p->antecesor->derecho = y;// carga y en p siendo este el hijo derecho.
			}
			y->izquierdo = p;//carga p en el hijo izquierdo de y.
			p->antecesor = y;//carga y en el padre de p.
	
	}
}

void ArbolRN::rotarDerecha(Nodo* p)
{
	//verifica sino tiene hijo izquierdo.
	if (p->izquierdo == NULL)
		return;
	else
	{
		//carga la estructura del hijo izquierdo de "p" en "y".
		Nodo* y = p->izquierdo;
	if (y->derecho != NULL)// verifica que tenga hijo derecho.
	{// carga el hijo derecho de "y" en el hijo izquierdo de "p"
		p->izquierdo = y->derecho;
		y->derecho->antecesor = p;//carga p en y .
	}
	else
		p->izquierdo = NULL;//p no tiene hijo izquierdo.
	if (p->antecesor != NULL)// si p tiene padre
		y->antecesor = p->antecesor; //carga el padre de p en el padre de y.
	if (p->antecesor == NULL)//si p es la raiz
		raiz = y; //carga y en la raiz.
	else
	{
		if (p == p->antecesor->izquierdo)// si p es el hijo izquierdo de su padre
			p->antecesor->izquierdo = y;// carga  y en p siendo este el hijo izquierdo.
		else
			p->antecesor->derecho = y;// carga y en p siendo este el hijo derecho.
	}
	y->derecho = p;//carga p en el hijo derecho de y.
	p->antecesor = y;//carga y en el padre de p.

}
}


void ArbolRN::borrar()
{
}
Nodo* ArbolRN::sucesor(Nodo*)
{
	return nullptr;
}
void ArbolRN::reparar(Nodo*)
{
}

void ArbolRN::mostrar()
{
	mostarArbol(raiz);//llama a la funcion mostrar arbol enviando la estructura raiz.
}

void ArbolRN::mostarArbol(Nodo*p)
{
	//Verifica si el arbol esta vacio
	if (raiz==NULL)
	{
		cout << "\n Arbol vacio."; 
		return;
	}
	//Arma el arbol mostrando hijos llamandose a si misma.
	if (p!=NULL)
	{
		cout << "\n \t NODO:";
		cout << "\n  Valor:"<<p->valor;// muestra el valor del nodo.
		cout << "\n  Color:";
		if(p->color=='n')//muestra el color del nodo.
			cout << "Negro.";
		else
			cout << "Rojo.";
		if(p->antecesor!=NULL)// si no es el nodo raiz.
			cout << "\n  Antecesor:"<<p->antecesor->valor;// muestra a su padre.
		else
			cout << "\n Raiz:";
		if(p->izquierdo != NULL)//muestra el hijo izquierdo
			cout << "\n Hijo Izquierdo:"<<p->izquierdo->valor;
		if (p->derecho != NULL)//muestra el hijo derecho
			cout << "\n Hijo Derecho:" << p->derecho->valor;
		cout << endl;
		if(p->izquierdo)// si tiene hijo hisquierdo
		{
			cout << "\n \n Izquierdo:\n";
			mostarArbol(p->izquierdo);//llama a la funcion para crear el arbol.
		}
		if (p->derecho)// si tiene hijo derecho
		{
			cout << "\n \n Derecho:\n";
			mostarArbol(p->derecho);//llama a la funcion para crear el arbol.
		}

	}
}

void ArbolRN::buscar()
{
	// verifica si el arbol esta vacio 
	if (raiz == NULL) {
		cout << "\n Arbol vacio.";
		return;
	}
	// Pide que ingrese el valor del nodo a buscar
	int x = 0; 
	cout << "Ingrese el valor a buscar: ";
	cin >> x;
	//carga los valores del arbol en p 
	Nodo* p = raiz;
	int encontrar = 0;//bandera.
	//verifica que p este vacio
	while (p!=NULL && encontrar==0)
	{
		//buscar el valor ingresado en el arbol empezando por la raiz.
		if(p->valor == x)
			encontrar = 1;
		//Escoge el camino a tomar al no encontrar  el valor en la raiz.
		if (encontrar==0)
		{
			if (p->valor < x)
				p = p->derecho;//hijo derecho.
			else
				p = p->izquierdo;//hijo izquierdo.

		}
	}
	// si no encuentra el elemento muestra que no se encontro
	if (encontrar==0)
	{
		cout << "\n Nodo no encontrado"<<endl;
	}
	else
	{
		//muestra el nodo, color, antecesor e hijos.
		cout << "\n \t NODO ENCONTADO:";
		cout << "\n Valor: " << p->valor;// muestra el valor del nodo.
		cout << "\n Color: ";
		//verifica el color
		if(p->color=='n')
			cout << "Negro";
		else
			cout << "Rojo";
		//muestra su antecesor.
		if(p->antecesor!=NULL)
			cout << "\n Antecesor: " << p->antecesor->valor;// muestra el  nodo padre.
		else
			cout << "\n Este nodo es la Raiz: ";
		// muestra los hijos si es que hay.
		if(p->izquierdo!=NULL)
			cout << "\n Hijo Izquierdo: " << p->izquierdo->valor;// muestra el hijo izquierdo.
		if (p->derecho != NULL)
			cout << "\n Hijo Derecho: " << p->derecho->valor;// muestra el hijo derecho.
		cout << endl;
	}
}
