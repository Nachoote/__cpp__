#include <stdio.h>		// Libreria estandar de C, necesaria para el manejo de entrada y salida (printf y scanf)
#include "./constantes.h"	// 
#include <cstdlib>		// Libreria estandar de C, necesaria para la generacion de numeros aleatorios (rand)
#include <ctime>		// Libreria para manejo de fechas y tiempo, necesaria para inicializar el generador de numeros aleatorios (time)




/*======================================================
 * 		POR HACER
 * ====================================================
 * 1 - Escribir el loop principal relativo a cantidad de intentos
 * 2 - Escribir condiciones de acierto y no acierto
 * 3 - Escribir el contador de puntaje y su manipulacion
 * 4 - Normalizar los nombres de variables
 *
 * */

int main(){	
/* ====================== Inicio ========================*/
	Matriz mat; 		// Matriz de N * N
	unsigned int i;		// Entero para recorrer array
	unsigned int j;		// Entero para recorrer array
	unsigned int valor;	// Entero para evaluar numero ingresado por el usuario en la carga de matriz
	unsigned int total;	// Entero para guardar el total de la suma de fila, columna o diagonal  
	unsigned int fil;	// Entero para seleccionar la fila que se quiere sumar
	unsigned int col;	// Entero para indicar la columna que se quiere sumar
	unsigned int diag;	// Entero para indicar diagonal principal o secundaria
	unsigned int random;	// Entero para guardar numero aleatorio entre  0 y (9 * N)
	unsigned int intentos;	// Entero para guardar numero de intentos que se desea jugar






/* ====================== Cargar Matriz ========================*/
/* 
 * Para cada posicion en columna (i) y fila(j) solicito al usuario un numero y lo guardo en la variable valor.
 * Si el numero es mayor que 0 y menor que 9 lo guardo en la posicion (i,j) y permito seguir la iteracion
 * Si no, no avanzo la iteracion y despliego un mensaje indicando el error hasta que el numero ingresado sea valido
 * 
 */
	for(i = 0; i < EJ2_N; i++){
		j = 0;
		do{
			printf("Ingresar valor para posicion %d,%d\n", i,j);
			scanf("%d", &valor);
			if(valor >= 0 && valor <= 9){
				mat[i][j] = valor;
				j++;
			}
			else{
				printf("[Error]: El numero debe ser mayor que 0 y menor que 9\n");
			}
		}
		while (j < EJ2_N);
	}
/* ====================== FIN Cargar Matriz ========================*/

/* ====================== Imprimir Matriz ========================*/
/*
 * Para cada posicion de columna imprimo el valor guardado en la misma
 * Una vez recorrida la fila imprimo un salto de linea para formar la cuadricula.
 *
 */
	for(i = 0; i < EJ2_N; i++){
		printf("|");
		for(j=0;j<EJ2_N;j++){
			printf(" %d |",mat[i][j]);
		}
		printf("\n");
	}
/* ====================== FIN Imprimir Matriz ========================*/

	printf("Ingrese cuantos intentos desea jugar:");
	scanf("%d", &intentos);	
	




/* ====================== Juego  ========================*/

	
/* ====================== Generar Numero Aleatorio ========================*/
/*
 * Primero inicializo el generador de numeros
 * Despues utilizo la operacion modulo (%) para generar un numero entre 0 y (9 * N)
 * Muestro el numero aleatorio
 * */
	srand(time(0));
	random = (rand() % (9 * EJ2_N));
	
/* ====================== Fin Numero Aleatorio ========================*/	

	
	
/* ====================== Evaluacion de filas, columnas y diagonales ========================*/	
/*
 * Utilizo un tipo enumerado (sumas) para almacenar las posibles opciones  (F: fila, C: columna, D: diagonal)
 * Pregunto al usuario si la suma de algun elemento es igual al numero aleatorio y que indique si el elemento es fila,columna o diagonal
 * Despues pido que indique el numero de fila, columna o diagonal y lo guardo en la variable fil, col o diag dependiando del caso
 **/

	sumas sum;
	printf("Ingresar linea a sumar: (F: fila, C: columna, D: diagonal):");
	scanf("%d", &sum);
	
	total = 0;
	switch(sum){
		case 1:
			/* ====================== Sumar Fila  ========================*/
			/*Si es fila, pido el numero de fila y lo guardo en fil, 
			 * despues recorro todas las posiciones de la fila (fil, i) y sumo el valor guardado 
			 * en cada una a la variable total inicializada en 0
			 * */
			printf("Ingresar numero de la fila a sumar:");
			scanf("%d", &fil);
			total = 0;
			for(i=0;i<EJ2_N;i++){
				total = total + mat[fil][i];
			}
			break;
		case 2:
			/* ====================== Sumar Columna  ========================*/
			/*
			 * Si es columna, pido el numero de columna y lo guardo en col,
			 * despues recorro las posiciones de la columna (i, col) y sumo el valor guardado 
			 * en cada una a la variable total inicializada en 0
			 * */
			printf("Ingresar numero de la columna a sumar:");
			scanf("%d", &col);
			total = 0;
			for(i=0;i<EJ2_N;i++){
				total = total + mat[i][col];
			}
			break;
		case 3:
			printf("Ingresar numero de la diagonal a sumar:");
			scanf("%d", &diag);
			total = 0;
			if(diag == 1){
			/* ====================== Sumar Diagonal 1  ========================*/
			/*
			 * Para la diagonal principal inicio la variable i en 0 y la voy incrementando 
			 * para recorrer las posiciones de la diagonal (i,i) y sumando su valor a la variable
			 * total inicializada en 0
			 *
			 * */
				for(i=0;i<EJ2_N;i++){
					total = total + mat[i][i];
				}
			}
			else { 
				if(diag == 2){
			/* ====================== Sumar Diagonal 2  ========================*/
			/*
			 * Para la diagonal secundaria inicio en la posicion N en columnas y 0 en filas
			 * para recorrer la diagonal voy reduciendo en 1 la variable i que recorre las columnas y 
			 * aumentando el 1 el indice en columnas mediante la operacion N - i
			 * para cada posicion recorrida sumo su valor a la variable total inicializada en 0
			 *
			 * */
					for(i=EJ2_N -1;i>=0;i--){
						total = total + mat[i][EJ2_N - i];
					}
				}
				else {
					printf("Las diagonales pueden ser 1 o 2\n");
				}
			}
			break;
		default:
			printf("Opcion Incorrecta\n");
			break;

	}
	printf("Total: %d\n", total);	
}

