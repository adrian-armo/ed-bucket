#include <stdio.h>
#include <stdlib.h>


typedef struct _nodo {
	void *data;
	struct _nodo *sigt;
} Nodo;

typedef struct _nave {
	unsigned int poder;
	unsigned int vida;
	unsigned char team;
} Nave;


typedef struct _listaSimple {
	Nodo *jupa;
	Nodo *cola;
	Nodo *actual;
} ListaSimple;

void inicializaLista (ListaSimple *lista) {
	lista-> jupa = NULL;
	lista-> cola = NULL;
	lista-> actual = NULL;
}

void addJupa(ListaSimple *lista, void *data) {
	//Pasar un puntero void permite agregar cualquier tipo de dato
	Nodo *nodo = (Nodo*) malloc(sizeof(Nodo)); //Se asigna la memoria para el nodo
	nodo-> data = data;	//Se agrega el dato del parametro 1
	if (lista-> jupa == NULL) { //Se verifica si la lista esta vacia
		lista-> cola == nodo;	//Si esta vacia se agrega el nodo
		nodo-> sigt == NULL;	//Si apunta a NULL el nodo siguiente
	} else {	//Si no esta vacia
		nodo-> sigt = lista-> jupa;	//Se agrega al inicio de la lista
	}
	lista-> jupa = nodo; //Se declara como nueva cabeza de la lista
}

//Un nodo siempre puede ser agregado a la cola si la lista no está vacia
void addCola(ListaSimple *lista, void *data){
	Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));
	nodo->data = data;
	if (lista-jupa == NULL) { //Si la lista esta vacia, jupa sera NULL
		lista->jupa = nodo; //Si esta vacia el nuevo nodo sera la jupa
	} else {
		lista-> cola-> sigt = nodo; //Si no esta vacia se agrega al final
	}
	lista-> cola = nodo; //La nueva cola es el nuevo nodo
}
