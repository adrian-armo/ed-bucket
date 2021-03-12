#include <stdio.h>
#include <stdlib.h>

/*
 * Instituto Tecnológico de Costa Rica
 * Estructuras de Datos
 * Profesor: Aurelio Sanabria
 * Estudiante: Adrian Araya Morera
 * Tarea Corta 1
 * 
 * Para compilar se utilizó gcc -g ejercicios1.c -o ejercicios1
 * Para ejecutar ./ejercicios1
 * 
 * De momento no se utiliza makefile ni gcc
 */

// La función determina si un numero es par o impar
// El numero debe ser entero, otros casos no estan contemplados
int parImpar(int numero) {
	//Se verifica el residuo modulo 2 del numero
	if (numero % 2 == 0) { //Si el residuo es 0 = par
		printf("El número es par.\n"); 
	}
	else { //En cualquier otro caso el residuo 1 indica impar
		printf("El número es nones.\n");
	}
	return 0; //Sale de la funcion
}

// Calcula la secuencia Fibonacci del numero entero de secuencia ingresado
int fibonacci(int numero) {
	if (numero <= 1) { // Si la secuencia es 0 o 1 se retorna su numero
		return numero;
	// Esta es la condicion base para resolver la recursividad
	}
	else {
		return fibonacci(numero - 1) + fibonacci(numero - 2); // Recursivo
		// Cuando alcanza los casos base, se pueden resolver la sucesion
	}
}

// Calcula el factorial de un numero entero ingresado
int factorial(int numero) {
	if (numero == 0) { 
		return 1; // Caso base para la fase recursiva
	}
	else {
		return numero * factorial(numero - 1); // Llamada recursiva
	}
}

// Calcula la cantidad de cifras de un numero de manera iterativa con for
int largoNumeroFor(int numero) {
	int contador = 1; // Inicializa el contador
	// Se inicializa en 1 dado que un caso minimo tendra 1 una cifra
	for(numero; // Se utiliza el parametro numero como expresion inicial
		numero/10 > 0; // Se ejecutara siempre que tenga mas de dos cifras
		numero = numero / 10) { // Se disminuye el numero y se modifica
		contador++; // Lleva la cuenta de la cantidad de cifras
	}
	return contador; // Se retorna el resultado
}

// Calcula la cantidad de cifras de un numero de manera iterativa con while
int largoNumeroWhile(int numero) {
	int contador = 1;
	while(numero/10 > 0) { // Mientras el numero tenga mas de dos cifras
		numero = numero / 10; // Se disminuye en un valor posicional N
		contador++; // Se aumenta la cantidad de cifras
	}
	return contador; // Se retorna el resultado
}

// Calcula la sumatoria de Cero a N usando For
int sumatoriaZNFor(int numero) {
	int sumatoria = 0; // Inicializa el resultado	
	int contador = 1; 
	for(contador; //Inicializa la expresion inicial
		contador<= numero; //Mientras el numero sumado no alcance a N.
		contador++) { //Se aumenta el numero a sumar en el ciclo siguiente
		sumatoria = sumatoria + contador; // Se suma el numero actual
	}
	return sumatoria; // Se retorna la sumatoria
}

// Calcula la sumatoria de Cero a N usando While
int sumatoriaZNWhile(int numero) {
	int sumatoria, contador = 0; //En este caso se inicializan en 0 ambos
	while(contador <= numero) { //Mientras el numero sumado no alcance a N.
		sumatoria = sumatoria + contador; //Se suma el numero al resultado
		contador++; //Se aumenta el numero a sumar en el siguiente ciclo
	}
	return sumatoria; // Se retorna la sumatoria
}

// La funcion recibe un numero entero e invierte sus valores posicionales
int invertirNumero(int numero) {
	int residuo, resultado = 0; // Se utiliza el residuo de %10 y resultado
	while(numero != 0) { // Mientras el numero sea diferente de 0
		residuo = numero%10; // Se obtiene el residuo, en este caso las unidades
		numero = numero/10; // Se disminuye el numero, truncando las unidades
		resultado = resultado*10 + residuo; // Se aumenta el valor posicional
		// y se adjunta la unidad anteriormente obtenida
	}
	return resultado; // Se retorna el resultado invertido
}

// Determina si un numero entero es palindromo o no
// Reutiliza la funcion de invertir un numero
int numeroPalindromo(int numero) { // Se recibe el numero a analizar
	int temporal = 0; // Se reserva espacio temporal
	temporal = invertirNumero(numero); // Se llama la funcion y se invierte
	// el numero sin modificar su valor
	// Se compara el numero con su version invertida
	if (temporal == numero){ // Si son iguales, es palindromo
		printf("El numero ingresado SI es palindromo.\n");
	}
	else { // En cualquier otro caso no
		printf("El numero ingresado NO es palindromo.\n");
	}
}


int main(void) {
  // !!!!!! Para probar una funcion primero descomente la funcion a probar !!!!!
  int continuar = 1;
  while (continuar) {
	  int numero = 0;
	  printf("\n Ingrese el numero a evaluar: ");
	  scanf("%d", &numero); // El valor ingresado se almacena en la direccion
							// de memoria apuntada por numero
	//parImpar(numero);
	//printf("\n La secuencia Fibonacci calculada es: %d.\n", fibonacci(numero));
	//printf("\n El factorial calculado es: %d.\n", factorial(numero));
	//printf("\n El numero ingresado tiene %d cifras.\n", largoNumeroFor(numero));
	//printf("\n El numero ingresado tiene %d cifras.\n", largoNumeroWhile(numero));
	//printf("\n La sumatoria de 0 al numero ingresado inclusive es: %d.\n", sumatoriaZNFor(numero));
	//printf("\n La sumatoria de 0 al numero ingresado inclusive es: %d.\n", sumatoriaZNWhile(numero));
	//printf("\n El numero invertido del ingresado es: %d.\n", invertirNumero(numero));
	//numeroPalindromo(numero);
	//numeroPalindromo(numero);  
	
	printf("\n ¿Desea evaluar otro numero? \n 1 = SI \n 0 = NO \n");
	scanf("%d", &continuar);
	if (continuar == 0) continuar = 0;
	}
	return 0;
}
