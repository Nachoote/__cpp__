#include <stdio.h>		// Libreria estandar de C, necesaria para el manejo de entrada y salida (printf y scanf)
#include "./constantes.h"	// 
#include <cstdlib>		// Libreria estandar de C, necesaria para la generacion de numeros aleatorios (rand)
#include <ctime>		// Libreria para manejo de fechas y tiempo, necesaria para inicializar el generador de numeros aleatorios (time)
#include <stdlib.h>




/*======================================================
 * 		POR HACER
 * ====================================================
 * * - Normalizar los nombres de variables
 * * - Revisar comentarios
 * */

void clean_stdin(void){
	int c;
	do{
		c = getchar();
	}while(c != '\n' && c != EOF);
}

int main(){	
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
	unsigned int intento; // Entero para control del loop principal
	boolean filas[EJ2_N];
	boolean columnas[EJ2_N];
	boolean diagonales[2];
	boolean ninguno;
	unsigned int aciertos;
	unsigned int errores;
	boolean jugar;
	char reintentar;


/* ====================== Inicio Ejercicio 2 ========================*/
	system("clear");
	printf("==============================\n");
        printf("\t  Ejercicio 2 \n");
        printf("==============================\n");

	printf("Instrucciones: \n \
* El programa le solicitara una serie de numeros enteros entr 0 y 9 con los cuales creara una matriz.\n \
* Una vez cargada la matriz, se le solicitara ingresar la cantidad de intentos que desea jugar\n \
* A continuacion generara un numero aleatorio y le solicitara que indique si la suma de los \n \ 
* elementos de alguna fila, columna o diagonal es igual al mismo.\n \
* \n \
* Presione Enter para continuar.");
	getchar();

	jugar = True;
	
/* ====================== Cargar Matriz ========================*/
/* 
 * Para cada posicion en columna (i) y fila(j) solicito al usuario un numero y lo guardo en la variable valor.
 * Si el numero es mayor que 0 y menor que 9 lo guardo en la posicion (i,j) y permito seguir la iteracion
 * Si no, no avanzo la iteracion y despliego un mensaje indicando el error hasta que el numero ingresado sea valido
 * 
 */
	do{
	for(i = 0; i < EJ2_N; i++){
		j = 0;
		do{
			system("clear");
			printf("==============================\n");	
			printf("\t  Ejercicio 2 \n");	
			printf("==============================\n");	
			printf("Ingresar valor para posicion %d,%d\n", i,j);
			scanf("%d", &valor);
			clean_stdin();
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
	system("clear");
	printf("==============================\n");	
	printf("\t  Ejercicio 2 \n");	
	printf("==============================\n");	
	printf("        ");
	for(i = 0; i < EJ2_N; i++){
		printf("%2d  ", i);
	}
	printf("\n");
	printf("        ");
	for(i = 0; i < EJ2_N; i++){
		printf("----");
	}
	printf("\n");
	for(i = 0; i < EJ2_N; i++){
		printf("%3d -->|", i);
		for(j=0;j<EJ2_N;j++){
			printf("%2d |",mat[i][j]);
		}
		printf("\n");
	}
        printf("\n");
/* ====================== FIN Imprimir Matriz ========================*/

	




/* ====================== Juego  ========================*/

	aciertos = 0;
	errores = 0;
	srand(time(0));
	printf("Ingrese cuantos intentos desea jugar:");
	scanf("%d", &intentos);	
	clean_stdin();

	for(intento = 1; intento <= intentos; intento++){
		
		random = (rand() % (9 * EJ2_N));
		ninguno = True;
	
		system("clear");
		printf("==============================\n");	
		printf("\t  Ejercicio 2 \n");	
		printf("==============================\n");	
		printf("\tIntento numero: %4d\n", intento);	
		printf("\tIntents restantes: %1d\n", (intentos - intento));	
		printf("==============================\n");	
		printf("\tAciertos: %d\n\tErrores: %d\n", aciertos, errores);	
		printf("------------------------------\n");
		printf("\tNumero Aleatorio: %d\n", random);
		printf("------------------------------\n");
	        printf("        ");
        	for(i = 0; i < EJ2_N; i++){
                	printf("%2d  ", i);
        	}
        	printf("\n");
        	printf("        ");
        	for(i = 0; i < EJ2_N; i++){
                	printf("----");
        	}
        	printf("\n");
        	for(i = 0; i < EJ2_N; i++){
                	printf("%3d -->|", i);
                	for(j=0;j<EJ2_N;j++){
                        	printf("%2d |",mat[i][j]);
                	}
                	printf("\n");
        	}
        	printf("\n");
	
	/* ====================== Generar Numero Aleatorio ========================*/
	/*
	 * Primero inicializo el generador de numeros
	 * Despues utilizo la operacion modulo (%) para generar un numero entre 0 y (9 * N)
	 * Muestro el numero aleatorio
	 * */
		
	/* ====================== Fin Numero Aleatorio ========================*/	

		
		
	/* ====================== Calcular filas, columnas y diagonales ========================*/	
				for(i = 0; i < EJ2_N;i++){
					total = 0;
					for(j=0;j<EJ2_N;j++){
						total = total + mat[i][j];
					}
					if(total == random){
						filas[i] = True;
						ninguno = False;
					}
					else{
						filas[i] = False;
					}
				}
				

				for(i = 0;i < EJ2_N;i++){
					total = 0;
					for(j=0;j<EJ2_N;j++){
						total = total + mat[j][i];
					}
					if(total == random){
						columnas[i] = True;
						ninguno = False;
					}
					else{
						columnas[i] = False;
					}
				}


				/* ====================== Sumar Diagonal 1  ========================*/
				/*
				 * Para la diagonal principal inicio la variable i en 0 y la voy incrementando 
				 * para recorrer las posiciones de la diagonal (i,i) y sumando su valor a la variable
				 * total inicializada en 0
				 *
				 * */
				total = 0;
				for(i=0;i<EJ2_N;i++){
					total = total + mat[i][i];
				}
				if(total == random){
					diagonales[0] = True;
					ninguno = False;
				}
				else{
					diagonales[0] = False;
				}
				/* ====================== Sumar Diagonal 2  ========================*/
				/*
				 * Para la diagonal secundaria inicio en la posicion N en columnas y 0 en filas
				 * para recorrer la diagonal voy reduciendo en 1 la variable i que recorre las columnas y 
				 * aumentando el 1 el indice en columnas mediante la operacion N - i
				 * para cada posicion recorrida sumo su valor a la variable total inicializada en 0
				 *
				 * */
				total = 0;
				j = EJ2_N -1;
				for(i=0;i < EJ2_N;i++){
					total = total + mat[i][j];
					j--;
				}

				if(total == random){
					diagonales[1] = True;
					ninguno = False;
				}
				else{
					diagonales[1] = False;
				}

				



		ej2_opcion opcion;
		do{
			printf("Ingresar linea a sumar: (1: fila, 2: columna, 3: diagonal, 4:Ninguno):");
			scanf("%d", &opcion);
			clean_stdin();
		}while(opcion > 4);
		
		switch(opcion){
			case F:
				/* ====================== Sumar Fila  ========================*/
				/*Si es fila, pido el numero de fila y lo guardo en fil, 
				 * despues recorro todas las posiciones de la fila (fil, i) y sumo el valor guardado 
				 * en cada una a la variable total inicializada en 0
				 * */
				do{
					printf("Ingresar numero de la fila a sumar:");
					scanf("%d", &fil);
					clean_stdin();
				}while(fil >= EJ2_N);
				if(filas[fil] == random){
					aciertos = aciertos + 1;
				}
				else{
					errores = errores + 1;
				}
				break;
			case C:
				/* ====================== Sumar Columna  ========================*/
				/*
				 * Si es columna, pido el numero de columna y lo guardo en col,
				 * despues recorro las posiciones de la columna (i, col) y sumo el valor guardado 
				 * en cada una a la variable total inicializada en 0
				 * */
				do{
					printf("Ingresar numero de la columna a sumar:");
					scanf("%d", &col);
					clean_stdin();
				}while(col >= EJ2_N);
				if(columnas[col]){
					aciertos = aciertos + 1;
				}
				else{
					errores = errores + 1;
				}
				break;
			case D:
				do{
					printf("Ingresar numero de la diagonal a sumar:");
					scanf("%d", &diag);
					clean_stdin();
				}while(diag > 2);
				if(diagonales[diag]){
					aciertos = aciertos + 1;
				}
				else{
					errores = errores + 1;
				}
				break;
			case N:
				if(ninguno){
					aciertos = aciertos + 1;
				}
				else{
					errores = errores + 1;
				}
				break;

		}

	}
	system("clear");
	printf("==============================\n");	
	printf("\t  Ejercicio 2 \n");	
	printf("==============================\n");	
	printf("\t Resultado  \n");	
	printf("==============================\n");	
	printf("Intentos jugados: %d\nAciertos: %d\nErrores: %d\n", intento, aciertos, errores);	
	printf("------------------------------\n");
	
	if(aciertos <= (intentos / 3)){
		printf("Hay que seguir practicando las sumas!\n");
	}
	else{
		if(aciertos <= (intentos /3) * 2){
			printf("No está mal, pero puede y debe mejorar.\n");
		}
		else{
			if(aciertos <= intentos - 1){
				printf("Muy buen resultado\n");
			}
			else{
				printf("Rendimiento impecable!\n");
			}
		}
	}
	printf("------------------------------\n");
	do{
		printf("\nReintentar s/n:");
		scanf("%c", &reintentar);
		clean_stdin();
	}while(reintentar != 's' && reintentar != 'n');
	if(reintentar == 's'){
		jugar = True;
	}else{
		jugar = False;
	}

	}while(jugar == True);
}
