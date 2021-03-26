#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/*
 * Instituto Tecnológico de Costa Rica
 * Estructuras de Datos
 * Profesor: Aurelio Sanabria
 * Estudiante: Adrian Araya Morera
 * Tarea Corta 4
 *
 * Para compilar se utilizó gcc -g guerra49.c -o guerra48
 * Para ejecutar ./guerra48
 *
 * De momento no se utiliza makefile
 * Última modificación: 25 marzo 2021
 */

// Funcion abreviada para limpiar las impresiones anteriores en la terminal
void clrscr() {
    system("@cls||clear");
}

/*  Funcion que imprime las opciones del juego en la terminal
*   Retorna un valor entero entre 1 y 4 para ser utilizado en un switch-main
*   Maneja validaciones para las opciones invalidas ingresadas por el usuario
*/
int menu(){

    printf("\n%s\n", "GUERRA DEL 48 | Todos contra todos\n" );
    printf("\t%s\n", "1. Iniciar << Declarar la guerra >>" );
    printf("\t%s\n", "2. Acuerdo de paz");

    int seleccion = 0;
    scanf("%d", &seleccion);

    while (seleccion < 1 || seleccion > 3) {
        printf("\n%s\n%s\n", "ERROR!   Opción fuera de parámetros.",
                                 "Por favor ingrese una opción válida.");
        scanf("%d", &seleccion);
    }

    if (seleccion == 2){
			printf("%s\n", "Se ha llegado a un acuerdo de paz y la guerra terminara en 3 segundos.");
			sleep(4);   // relentiza el inicio del juego para poder leer el mensaje de feedback
			return 0;
		}

    printf("\nUsted ha seleccionado satisfactoriamente la opción: %d\n\n", seleccion);
    printf("%s\n", "-------- El juego iniciará en pocos segundos --------"); // feedback

    sleep(4);   // relentiza el inicio del juego para poder leer el mensaje de feedback
    clrscr();   // limpia la terminal

    return seleccion;
}


/*  Retorna un entero en el rango [0, maximo]
*   Recibe como parametro un entero maximo (inclusive)
*/
int int_random(int maximo) {
    return rand()%(maximo+1);
}


typedef struct _nodo {
	int poder;
	int vida;
	char team;
	struct _nodo *sigt;
} Nodo;


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

void addJupa(ListaSimple *lista, int poder, int vida, char team) {
	//Pasar un puntero void permite agregar cualquier tipo de dato
	Nodo *nodo = (Nodo*) malloc(sizeof(Nodo)); //Se asigna la memoria para el nodo
	nodo-> poder = poder;	//Se agrega el dato del parametro 1
	nodo-> vida = vida;	//Se agrega el dato del parametro 1
	nodo-> team = team;	//Se agrega el dato del parametro 1
	if (lista-> jupa == NULL) { //Se verifica si la lista esta vacia
		lista-> cola == nodo;	//Si esta vacia se agrega el nodo
		nodo-> sigt == NULL;	//Si apunta a NULL el nodo siguiente
	} else {	//Si no esta vacia
		nodo-> sigt = lista-> jupa;	//Se agrega al inicio de la lista
	}
	lista-> jupa = nodo; //Se declara como nueva cabeza de la lista
}

/*
//Un nodo siempre puede ser agregado a la cola si la lista no está vacia
void addCola(ListaSimple *lista, int poder, int vida, int team){
	Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));
	nodo-> poder = poder;	//Se agrega el dato del parametro 1
	nodo-> vida = poder;	//Se agrega el dato del parametro 1
	nodo-> team = poder;	//Se agrega el dato del parametro 1
	nodo-> sigt = NULL;
	if (lista->jupa == NULL) { //Si la lista esta vacia, jupa sera NULL
		lista->jupa = nodo; //Si esta vacia el nuevo nodo sera la jupa
	} else {
		lista-> cola-> sigt = nodo; //Si no esta vacia se agrega al final
	}
	lista-> cola = nodo; //La nueva cola es el nuevo nodo
}
*/

void eliminaNodo(ListaSimple *lista, Nodo *nodo){ //para aplicar aritmetica *
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
void imprimirLista(ListaSimple *lista, int valor) {
    if (lista-> jupa == NULL) { //Si la lista está vacía
        printf("La lista ingresada está vacia./n");
    } else {
			Nodo *temp = lista-> jupa; //Temp para recorrido de la lista
			while(temp != NULL) {
				if (valor == 1) {
					printf("%0*d ", 2, temp-> vida);
				}
				if (valor == 2) {
					printf("%0*d ", 2, temp-> poder);
				}
				if (valor == 3) {
					printf("%c  ", temp-> team);
				}
				temp = temp-> sigt;
			}
			printf("\n");
    }
}

void imprimeTablero(ListaSimple lista){
	printf("\n");
	printf("Vida\t: ");
	imprimirLista(&lista, 1);
	printf("Poder\t: ");
	imprimirLista(&lista, 2);
	printf("Team\t: ");
	imprimirLista(&lista, 3);
}

ListaSimple inicia_guerra(int nivel) {
	ListaSimple listaSimple;
	inicializaLista(&listaSimple);

	int max_naves = 6;
	for (size_t i = 0; i < max_naves; i++) {

		int ran_poder = int_random(nivel); //El nivel se pide entre 1 y 10
		int ran_vida = int_random(nivel);

		if (i % 2 == 0) {
			addJupa(&listaSimple, ran_poder/2, ran_vida, 'X');
		} else {
			addJupa(&listaSimple, ran_poder/2, ran_vida, 'Z');
		}
	}
	return listaSimple;
}

void disparar(ListaSimple *lista, int posicion){
	lista-> actual = lista-> jupa;

	int contador = 1;
	while (contador < posicion-1) {
		lista-> actual = lista-> actual -> sigt;
		contador++;
	}
	int poder = lista-> actual -> sigt -> poder;
	if (posicion > 1) {
		lista-> actual-> vida = lista-> actual-> vida - poder; //resta a la izq
	}
	if (posicion < 6) {
		lista-> actual -> sigt-> sigt-> vida = lista-> actual-> sigt -> sigt-> vida - poder; //resta a la izq
	}

}



int main(int argc, char const *argv[]) {

	srand(time(NULL));

	int entrada = menu(); // optiene la entrada del usuario
	int nivel = 0;
	int carreta = 0;

	switch(entrada) {
		case 1:
				printf("%s\n", "Ingrese el nivel del juego entre 1 y 99: ");
				scanf("%d", &nivel);

				ListaSimple listaSimple;
				listaSimple = inicia_guerra(nivel);
				imprimeTablero(listaSimple);

				printf("%s\n", "Jugador Z seleccione cual carreta desea dispara 1, 3 o 5 ");
				scanf("%d", &carreta);

				disparar(&listaSimple, carreta);
				imprimeTablero(listaSimple);

				break;

		case 2:
				printf("%s\n", "Se ha llegado a un acuerdo de paz y la guerra terminara en 3 segundos.");
				sleep(4);   // relentiza el inicio del juego para poder leer el mensaje de feedback

				break;

	} //cierra el switch



	return 0;
}
