#include <stdio.h>
#include <stdlib.h>


typedef struct _nodo {
	void *data;
	struct _nodo *sigt;
} Nodo;

typedef struct _nave {
	unsigned int poder;
	unsigned int vida;
	unsigned int team;
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
	if (lista->jupa == NULL) { //Si la lista esta vacia, jupa sera NULL
		lista->jupa = nodo; //Si esta vacia el nuevo nodo sera la jupa
	} else {
		lista-> cola-> sigt = nodo; //Si no esta vacia se agrega al final
	}
	lista-> cola = nodo; //La nueva cola es el nuevo nodo
}

void eliminaNodo(ListaSimple *lista, Nodo *nodo){
	if (nodo == lista-> jupa){ //Maneja cuando el nodo a eliminar es 1er
		if (lista-> jupa-> sigt == NULL) { //Si el primer nodo es el unico
			lista-> jupa = lista-> cola = NULL; //Reasiga a NULL los nodos de la lista
		} else { //Si el nodo no es unico
			lista-> jupa = lista-> jupa-> sigt; //se asigna el 1er al sigt nodo en lista
		}
	} else { //Se recorre la lista
		Nodo *temp = lista-> jupa; //Usando un puntero temporal
		//Termina si temp es asignado a NULL, lo que indica que el elemento no esta
		while (temp != NULL && temp-> sigt != nodo) {
			temp = temp-> sigt; //Avanza
		}
		if (temp != NULL) {
			temp-> sigt = nodo-> sigt; //Se obtiene el nodo siguiente al eliminar
			//temp conserva la direccion al nodo anterior al eliminar,
			//nodo conserva la direccion del nodo a eliminar
			//se reasigna desde la dir del nodo anterior, la dir del nodo subsecuente
			//de esta manera se "brinca" el nodo a eliminar
		}
	}
	free(nodo); //Se libera la direccion del nodo buscado para eliminar
}

//Imprime una lista del campo de dato ingresado como parámetro
void imprimirLista(ListaSimple *lista, void *data) {
    if (lista-> jupa == NULL) { //Si la lista está vacía
        printf("La lista ingresada está vacia.");
    } else {
        Nodo *temp = lista-> jupa; //Temp para recorrido de la lista
        while(temp != NULL) {
            printf("%d "; temp-> data);
        }
    }
}

int main(int argc, char const *argv[]) {
	ListaSimple listaSimple;

	Nave *nave1 = (Nave*) malloc(sizeof(Nave));
	nave1-> poder = 5;
	nave1-> vida = 100;
	nave1-> team = 1;

	Nave *nave2 = (Nave*) malloc(sizeof(Nave));
	nave2-> poder = 7;
	nave2-> vida = 200;
	nave2-> team = 2;

	inicializaLista(&listaSimple);

	addJupa(&listaSimple, nave1);
	addJupa(&listaSimple, nave2);

	return 0;
}
