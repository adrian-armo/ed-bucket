#include <stdio.h>
#include <stdlib.h>

/*
 * Instituto Tecnológico de Costa Rica
 * Estructuras de Datos
 * Profesor: Aurelio Sanabria
 * Estudiante: Adrian Araya Morera
 * Tarea Corta 2
 * 
 * Para compilar se utilizó gcc -g ejercicios1.c -o ejercicios1
 * Para ejecutar ./ejercicios1
 * 
 * De momento no se utiliza makefile
 * Última modificación: 05 marzo 2021
 */


/* Funcion len_string
 * Calcula la cantidad de caracteres de una linea de texto
 * Argumentos:	Puntero a la linea a evaluar
 * Retornos:	Un int con la cantidad de caracteres
 * 				0 si la linea estaba vacia o ocurrio un error
 */
int len_string ( char* linea ) {
	if (linea == NULL) return 0;
	
	int i = 0;
	while ( linea [i] != '\0' ) { // Hasta encontrar el final de linea
		i++;
	}
	return i;
}


/* Funcion obtiene_linea
 * Lee una linea de la entrada standar a memoria asignada dinamicamente
 * Reemplaza el caracter de linea nueva con un \0
 * Argumentos:	El maximo de linea a leer
 * Retornos:	Un puntero a la linea leida, o
 * 				NULL si el final de linea fue leido o hubo un problema
 */
char* obtiene_linea ( unsigned int largo_maximo ) {
	
	char* pt_linea = calloc ( largo_maximo+1, sizeof( char ) ); //Se reserva un espacio más para EOF
	
	if ( pt_linea != NULL ) {
		// Lee la linea de texto y reemplaza el \n con EOF
		int c = EOF;
		unsigned int i = 0;
	
		while ( i < largo_maximo && ( c = getchar() ) != '\n' && c != EOF ) {
			pt_linea[i++] = ( char ) c; // Concatena el caracter ingresado
		}
		pt_linea[i] = '\0'; // Agrega el final de la linea de referencia
		
		if ( c == EOF && i == 0 ) {	// Si se leyo el salto de linea antes
			free( pt_linea );		// de que se leyera cualquier char
			pt_linea = NULL;		// libera el buffer completo
		}
		else {
			pt_linea = realloc  ( pt_linea, i+1 );	// i conserva el len
		}
		return pt_linea; // Retorna el puntero a la linea recibida
	}	
}


/* Funcion elimina_caracter
 * Elimina el caracter seleccionado, todas las veces que aparece en una linea
 * Crea una linea auxiliar con el resultado del filtrado
 * Argumentos:	El caracter a buscar, la linea a filtar
 * Retornos:	Un puntero a la nueva linea modificada
 */
char* elimina_caracter ( char caracter, char* linea ) {
	
	int largo = len_string ( linea );
	char* auxiliar = calloc ( largo+1 , sizeof( char ) ); // Asigna mem
	
	if (linea == NULL) return 0; // Verificar que la linea tenga algo
	
	int i = 0; 	// Contar para recorrer la linea orginal
	int ii = 0;	// Para recorrer la linea auxiliar
	while ( i < largo ) { // Mientras no se llegue al '\0'
		if ( linea[i] != caracter ) {
			auxiliar[ii] = linea[i];// Se recorren con contadores diferentes
			ii++;					// Solamente se aumenta el auxiliar si se
		}							// concatena un char nuevo, de lo contrario
		i++;						// va a avanzar dejando bytes con basura
	}
	auxiliar[ii] = '\0'; // Se agrega el final de linea
	auxiliar = realloc  ( auxiliar, ii+1 );	// ii conserva el len de la
	return auxiliar;						// nueva linea
}


/* Funcion inverte texto
 * Invierte una linea de texto generando una nueva linea
 * Crea una linea auxiliar con el resultado de invertir la linea
 * Argumentos:	La linea a invertir
 * Retornos:	Un puntero a la nueva linea modificada
 */
char* invierte_texto(char* linea) {
	
	int largo = len_string ( linea );
	char* auxiliar = calloc ( largo+1, sizeof( char ) );
	
	if (linea == NULL) return 0;	
	
	int i = largo-1;	// Encuentro el ultimo char de la linea
	int ii = 0;			// Empiezo a recorrer el auxiliar en contrario
	while ( i >= 0 ) {	// Mientras no llegue al principio de la linea
		auxiliar[ii] = linea[i];	// Se empieza a llenar al contrario
		i--;	// Aqui esta la magia
		ii++;
	}
	return auxiliar; // Retorna la linea modificada
}


/* Funcion literal_heap
 * Traslada una linea literal constante a la seccion heap de la memoria
 * Crea una linea auxiliar alojada en el heap
 * Retornos:	Un puntero a la nueva linea en heap
 */
char* literal_heap() {
	char* literal = "Texto de prueba"; // Se utiliza un texto "alambrado"
	printf ( "\t La línea literal es: %s \n", literal ); // Comprobacion
	
	char* linea_heap = calloc ( len_string ( literal )+1, sizeof ( char ) );
	
	int i = 0;
	while ( literal [i] != '\0' ) {		// Se recorre la linea original
		linea_heap[i] = literal[i];		// se pasa a los bloques de mem
		i++;							// previamente solicitados en el
	}									// heap.
	linea_heap[i+1] = '\0';		// Se agrega el final de linea
	return linea_heap;
}


int main(void) {
	
	unsigned int largo_maximo = 128; // Esto se puede definir para todo el programa
	char* linea = NULL;	// Se crea el puntero, hasta ahora sin memoria asignada
	
	printf ( "\n  Ingrese una linea nueva a transformar: " );
	linea = obtiene_linea ( largo_maximo ); // Se actualiza el puntero
	if ( linea != NULL ) { // Si la linea no esta vacia
		
	printf( "\t La linea ingresada es: %s.\n", linea);
	
	printf( "\t El largo de la linea es: %d.\n", len_string ( linea ) );
	
	printf( "\t La linea filtrada sin el caracter 'c' es: %s.\n", elimina_caracter( 'c', linea ) );
	
	printf( "\t La linea invertida es: %s.\n", invierte_texto( linea ) );
	
	printf( "\t La linea en heap es: %s \n", literal_heap() );
	}
}
