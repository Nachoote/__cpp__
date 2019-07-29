#include <stdio.h>
#include <cstdlib>		// Libreria estandar de C, necesaria para la generacion de numeros aleatorios (rand)
#include <ctime>		// Libreria para manejo de fechas y tiempo, necesaria para inicializar el generador de numeros aleatorios (time)
#include <stdlib.h>
#include <iostream>

/*Obligatorio Programacion 1
Integrantes: 
Ignacio Oteggi 
Patricia Nario 
Fernando Panizza*/

void clean_stdin(void){
	int c;
	do{
		c = getchar();
	}while(c != '\n' && c != EOF);
}

//Inicio declaraciones Ejercicio 1
const int contante=1 ;
<<<<<<< HEAD
const int EJ2_N = 3;
const int MAX = 100;

typedef int Matriz[EJ2_N][EJ2_N];
typedef enum {F=1,C,D,N} ej2_opcion;
typedef enum {FALSE, TRUE} boolean;
typedef char string [MAX];
=======
const int N = 3;
typedef int Matriz[N][N];
typedef enum {FIL=1,COL,DIA,NIN} Ej2_opcion;
typedef enum {False, True} boolean;

>>>>>>> 8c39c9e87a5bbe0d7353572eac8b8f3aa06aca07

boolean seguir = FALSE;
int maxPalabras ;// cantidad maxima de palabras a buscar en del arreglo, se la pedimos al usuario
int cantPalabrasMax = 0;
int l;
int aux;
int ej1_max;
int dif;
char car;
string ej1_cad;
string ej1_cad_upper;
boolean ej1_existe = FALSE;
boolean ej1_valido = FALSE;

//Fin declaraciones Ejercicio 1
//Inicio Declaraciones Ejercicio 2
Matriz mat;             // Matriz de N * N
unsigned int i;         // Entero para recorrer array
unsigned int j;         // Entero para recorrer array
unsigned int ej2_valor;     // Entero para evaluar numero ingresado por el usuario en la carga de matriz
unsigned int ej2_total;     // Entero para guardar el ej2_total de la suma de fila, columna o diagonal  
unsigned int ej2_fil;       // Entero para seleccionar la fila que se quiere sumar
unsigned int ej2_col;       // Entero para indicar la columna que se quiere sumar
unsigned int ej2_diag;      // Entero para indicar diagonal principal o secundaria
unsigned int ej2_aleatorio;    // Entero para guardar numero aleatorio entre  0 y (9 * N)
unsigned int ej2_intentos;  // Entero para guardar numero de intentos que se desea jugar
unsigned int ej2_intento; // Entero para control del loop principal
boolean ej2_filas[N];
boolean ej2_columnas[N];
boolean ej2_diagonales[2];
boolean ej2_ninguno;
unsigned int ej2_aciertos;
unsigned int ej2_errores;
boolean ej2_jugar;
char ej2_reintentar;

//Fin Declaraciones Ejercicio 2


int main()
{
    boolean entrar = TRUE;
    int opcion = 0;
    while(entrar)
    {
		system("clear");
    	printf("============================================\n");
    	printf("=                                          =\n");
    	printf("=     Trabajo Obligatorio Programacion     =\n");
    	printf("=                                          =\n");
    	printf("============================================\n");
      printf("Ingrese el nro. del ejercicio que desea: \n");
      printf("Escriba 1 para el Ejercicio 1 \n");
      printf("Escriba 2 para el Ejercicio 1 \n");
      printf("Escriba 0 para Salir \n");
      scanf("%d", &opcion);
      switch(opcion)
      {
          case 1:
            clean_stdin();
	        system("clear");
            printf("--- Ejercicio 1 --- \n");
            // Inicio Ejericio 1
            /*
            1. Declare un tipo de datos adecuado para almacenar el texto, el cual será ingresado por teclado por
            parte del usuario.
            2. Validar oraciones. Se desea chequear si cada oración del texto ingresado comienza con una letra
            mayúscula y termina con signo de puntuación ‘.’.
            3. Solicite al docente una cantidad máxima de palabras para el trabajo. A partir del texto ingresado,
            calcule la cantidad ej2_total de palabras que lo componen y avise al docente: cuantas palabras posee, y
            (en caso de excederse) por cuantas palabras está pasado el texto respecto a lo pretendido por el
            docente.

            */

             //declaro la variable donde cargare las letras del string
            
            ////////////// Parte de ingresar la oracion y mostrarla al usuario///////////////////////////
            printf ("\nIngrese una oracion que termine con '.': \n"); //solicito al usuario una oracion y le indico como debe terminarla correctamente
            fflush(stdin);            
            scanf ("%c", &car);
            //limpio la variable
            
            /* ================ Cargar Cadena ================ */
            l =0;
            while (car !='\n' && l < MAX -1)
                {
                    ej1_cad[l] = car;            
                    l++;
                    scanf ("%c", &car);
                }
            ej1_cad[l] = '\0';

            /* ================ Fin Cargar Cadena ================ */   

         

            /* ================ Imprimir Cadena ================ */

            l=0; //seteo a 0 la variable l
            printf ("\nLa oracion ingresada es: "); //muestro al usuario la oracion que ingreso con un while
            while (ej1_cad[l] != '\0')
                {
                    printf ("%c", ej1_cad[l]);
                    l++;
                }

            /* ================ Fin Imprimir Cadena ================ */

            

            /* ================ Validar oracion ================ */

            if (ej1_cad[0] > 'A' && ej1_cad[0] < 'Z' && ej1_cad[l -1] == '.') ej1_valido = TRUE;

            //mientras la palabra comience con mayuscula y termine con punto es valida

            if (ej1_valido)
            printf ("\nLa oracion ingresada ES VALIDA  \n");
            else
            printf ("\nLa oracion ingresada NO ES VALIDA   \n");

            /* ================ Fin Validar oracion ================ */

            /* ================ Solicitar maximo y  contar palabras ================ */
            aux =0;
            clean_stdin(); //limpio la variable
            printf ("\nIngrese una cantidad maxima de palabras: ");
            scanf ("%d", &ej1_max );



            l = 0;
            while (ej1_cad[l] !='\0'){
                if ((ej1_cad[l] == ' ' || ej1_cad[l] == '.')&& ej1_cad[l -1] != ' '){
                    aux = aux + 1;
                }
                l++;
            }

            printf ("\nHay %d cantidad palabras la oracion \n",aux);
            dif = 0;
            dif=ej1_max-aux;
            printf ("\n La diferencia de palabras entre lo solcitado e ingrasado es : %d palabras \n",dif);



            /* ================ Fin Solicitar maximo y  contar palabras ================ */

            ////////////// Parte  saber si una palabra dada esta en la oracion ///////////////////////////


            /* Convertir texto a mayusculas para la evaluacion */
            l = 0;
            while (ej1_cad[l] != '\0'){
                if (ej1_cad[l] >= 'a' && ej1_cad[l] <= 'z'){
                    ej1_cad_upper[l] = ej1_cad[l] - 32;
                }
                else{
                    ej1_cad_upper[l] = ej1_cad[l];
                }
                l++;
            }            
            ej1_cad_upper[l] = '\0';




            l=0; //seteo a 0 la variable l
            printf ("\nLa oracion ingresada es: "); //muestro al usuario la oracion que ingreso con un while
            while (ej1_cad_upper[l] != '\0')
                {
                    printf ("%c", ej1_cad_upper[l]);
                    l++;
                }




            
            l = 0;
            ej1_existe = FALSE;
            printf ("\nIngrese una palabra : ");
            fflush(stdin);
            scanf ("%c",&car);


            while (!ej1_existe && ej1_cad[l] != '\0' && (ej1_cad[l] !='.') && (ej1_cad[l] !=' '))
            {
            if (ej1_cad[l] == car)
            ej1_existe = TRUE;
            else
            l++;
            }
            if (ej1_existe)
            printf ("\nLa palabra SI pertenece a la oracion ");
            else
            printf ("\nLa palabra NO pertenece a la oracion ");


            //Fin Ejercicio 1

          break;

      case 2:
        
       // Inicio Ejericio 2
        clean_stdin();
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

<<<<<<< HEAD
	jugar = TRUE;
=======
	ej2_jugar = True;
>>>>>>> 8c39c9e87a5bbe0d7353572eac8b8f3aa06aca07

/* ====================== Cargar Matriz ========================*/
/*
 * Para cada posicion en columna (i) y fila(j) solicito al usuario un numero y lo guardo en la variable ej2_valor.
 * Si el numero es mayor que 0 y menor que 9 lo guardo en la posicion (i,j) y permito seguir la iteracion
 * Si no, no avanzo la iteracion y despliego un mensaje indicando el error hasta que el numero ingresado sea valido
 *
 */
	do{
	for(i = 0; i < N; i++){
		j = 0;
		do{
			system("clear");
			printf("==============================\n");
			printf("=         Ejercicio 2        =\n");
			printf("==============================\n");
			printf("Ingresar ej2_valor para posicion %d,%d\n", i,j);
			scanf("%d", &ej2_valor);
			clean_stdin();
			if(ej2_valor >= 0 && ej2_valor <= 9){
				mat[i][j] = ej2_valor;
				j++;
			}
			else{
				printf("[Error]: El numero debe ser mayor que 0 y menor que 9\n");
			}
		}
		while (j < N);
	}
/* ====================== FIN Cargar Matriz ========================*/

/* ====================== Imprimir Matriz ========================*/
/*
 * Para cada posicion de columna imprimo el ej2_valor guardado en la misma
 * Una vez recorrida la fila imprimo un salto de linea para formar la cuadricula.
 *
 */
	system("clear");
	printf("==============================\n");
	printf("=         Ejercicio 2        =\n");
	printf("==============================\n");
	printf("        ");
	for(i = 0; i < N; i++){
		printf("%2d  ", i);
	}
	printf("\n");
	printf("        ");
	for(i = 0; i < N; i++){
		printf("----");
	}
	printf("\n");
	for(i = 0; i < N; i++){
		printf("%3d -->|", i);
		for(j=0;j<N;j++){
			printf("%2d |",mat[i][j]);
		}
		printf("\n");
	}
        printf("\n");
/* ====================== FIN Imprimir Matriz ========================*/






/* ====================== Juego  ========================*/

	ej2_aciertos = 0;
	ej2_errores = 0;
	srand(time(0));
	printf("Ingrese cuantos intentos desea jugar:");
	scanf("%d", &ej2_intentos);
	clean_stdin();

	for(ej2_intento = 1; ej2_intento <= ej2_intentos; ej2_intento++){

<<<<<<< HEAD
		aleatorio = (rand() % (9 * EJ2_N));
		ninguno = TRUE;
=======
		ej2_aleatorio = (rand() % (9 * N));
		ej2_ninguno = True;
>>>>>>> 8c39c9e87a5bbe0d7353572eac8b8f3aa06aca07

		system("clear");
		printf("==============================\n");
		printf("=         Ejercicio 2        =\n");
		printf("==============================\n");
		printf("\tIntento numero: %4d\n", ej2_intento);
		printf("\tIntents restantes: %1d\n", (ej2_intentos - ej2_intento));
		printf("==============================\n");
		printf("\tAciertos: %d\n\tErrores: %d\n", ej2_aciertos, ej2_errores);
		printf("------------------------------\n");
		printf("\tNumero Aleatorio: %d\n", ej2_aleatorio);
		printf("------------------------------\n");
	        printf("        ");
        	for(i = 0; i < N; i++){
                	printf("%2d  ", i);
        	}
        	printf("\n");
        	printf("        ");
        	for(i = 0; i < N; i++){
                	printf("----");
        	}
        	printf("\n");
        	for(i = 0; i < N; i++){
                	printf("%3d -->|", i);
                	for(j=0;j<N;j++){
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
				for(i = 0; i < N;i++){
					ej2_total = 0;
					for(j=0;j<N;j++){
						ej2_total = ej2_total + mat[i][j];
					}
<<<<<<< HEAD
					if(total == aleatorio){
						filas[i] = TRUE;
						ninguno = FALSE;
					}
					else{
						filas[i] = FALSE;
=======
					if(ej2_total == ej2_aleatorio){
						ej2_filas[i] = True;
						ej2_ninguno = False;
					}
					else{
						ej2_filas[i] = False;
>>>>>>> 8c39c9e87a5bbe0d7353572eac8b8f3aa06aca07
					}
				}


				for(i = 0;i < N;i++){
					ej2_total = 0;
					for(j=0;j<N;j++){
						ej2_total = ej2_total + mat[j][i];
					}
<<<<<<< HEAD
					if(total == aleatorio){
						columnas[i] = TRUE;
						ninguno = FALSE;
					}
					else{
						columnas[i] = FALSE;
=======
					if(ej2_total == ej2_aleatorio){
						ej2_columnas[i] = True;
						ej2_ninguno = False;
					}
					else{
						ej2_columnas[i] = False;
>>>>>>> 8c39c9e87a5bbe0d7353572eac8b8f3aa06aca07
					}
				}


				/* ====================== Sumar Diagonal 1  ========================*/
				/*
				 * Para la diagonal principal inicio la variable i en 0 y la voy incrementando
				 * para recorrer las posiciones de la diagonal (i,i) y sumando su ej2_valor a la variable
				 * ej2_total inicializada en 0
				 *
				 * */
				ej2_total = 0;
				for(i=0;i<N;i++){
					ej2_total = ej2_total + mat[i][i];
				}
<<<<<<< HEAD
				if(total == aleatorio){
					diagonales[0] = TRUE;
					ninguno = FALSE;
				}
				else{
					diagonales[0] = FALSE;
=======
				if(ej2_total == ej2_aleatorio){
					ej2_diagonales[0] = True;
					ej2_ninguno = False;
				}
				else{
					ej2_diagonales[0] = False;
>>>>>>> 8c39c9e87a5bbe0d7353572eac8b8f3aa06aca07
				}
				/* ====================== Sumar Diagonal 2  ========================*/
				/*
				 * Para la diagonal secundaria inicio en la posicion N en columnas y 0 en filas
				 * para recorrer la diagonal voy reduciendo en 1 la variable i que recorre las columnas y
				 * aumentando el 1 el indice en columnas mediante la operacion N - i
				 * para cada posicion recorrida sumo su ej2_valor a la variable ej2_total inicializada en 0
				 *
				 * */
				ej2_total = 0;
				j = N -1;
				for(i=0;i < N;i++){
					ej2_total = ej2_total + mat[i][j];
					j--;
				}

<<<<<<< HEAD
				if(total == aleatorio){
					diagonales[1] = TRUE;
					ninguno = FALSE;
				}
				else{
					diagonales[1] = FALSE;
=======
				if(ej2_total == ej2_aleatorio){
					ej2_diagonales[1] = True;
					ej2_ninguno = False;
				}
				else{
					ej2_diagonales[1] = False;
>>>>>>> 8c39c9e87a5bbe0d7353572eac8b8f3aa06aca07
				}





		Ej2_opcion opcion;
		do{
			printf("Ingresar linea a sumar: (1: fila, 2: columna, 3: diagonal, 4:Ninguno):");
			scanf("%d", &opcion);
			clean_stdin();
		}while(opcion > 4);

		switch(opcion){
			case FIL:
				/* ====================== Sumar Fila  ========================*/
				/*Si es fila, pido el numero de fila y lo guardo en fil,
				 * despues recorro todas las posiciones de la fila (fil, i) y sumo el ej2_valor guardado
				 * en cada una a la variable ej2_total inicializada en 0
				 * */
				do{
					printf("Ingresar numero de la fila a sumar:");
					scanf("%d", &ej2_fil);
					clean_stdin();
				}while(ej2_fil >= N);
				if(ej2_filas[ej2_fil] == ej2_aleatorio){
					ej2_aciertos = ej2_aciertos + 1;
				}
				else{
					ej2_errores = ej2_errores + 1;
				}
				break;
			case COL:
				/* ====================== Sumar Columna  ========================*/
				/*
				 * Si es columna, pido el numero de columna y lo guardo en col,
				 * despues recorro las posiciones de la columna (i, col) y sumo el ej2_valor guardado
				 * en cada una a la variable ej2_total inicializada en 0
				 * */
				do{
					printf("Ingresar numero de la columna a sumar:");
					scanf("%d", &ej2_col);
					clean_stdin();
				}while(ej2_col >= N);
				if(ej2_columnas[ej2_col]){
					ej2_aciertos = ej2_aciertos + 1;
				}
				else{
					ej2_errores = ej2_errores + 1;
				}
				break;
			case DIA:
				do{
					printf("Ingresar numero de la diagonal a sumar:");
					scanf("%d", &ej2_diag);
					clean_stdin();
				}while(ej2_diag > 2);
				if(ej2_diagonales[ej2_diag]){
					ej2_aciertos = ej2_aciertos + 1;
				}
				else{
					ej2_errores = ej2_errores + 1;
				}
				break;
			case NIN:
				if(ej2_ninguno){
					ej2_aciertos = ej2_aciertos + 1;
				}
				else{
					ej2_errores = ej2_errores + 1;
				}
				break;

		}

	}
	system("clear");
	printf("==============================\n");
	printf("=         Ejercicio 2        =\n");
	printf("==============================\n");
	printf("\t Resultado  \n");
	printf("==============================\n");
	printf("Intentos jugados: %d\nAciertos: %d\nErrores: %d\n", ej2_intento, ej2_aciertos, ej2_errores);
	printf("------------------------------\n");

	if(ej2_aciertos <= (ej2_intentos / 3)){
		printf("Hay que seguir practicando las sumas!\n");
	}
	else{
		if(ej2_aciertos <= (ej2_intentos /3) * 2){
			printf("No está mal, pero puede y debe mejorar.\n");
		}
		else{
			if(ej2_aciertos <= ej2_intentos - 1){
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
		scanf("%c", &ej2_reintentar);
		clean_stdin();
<<<<<<< HEAD
	}while(reintentar != 's' && reintentar != 'n');
	if(reintentar == 's'){
		jugar = TRUE;
	}else{
		jugar = FALSE;
	}

	}while(jugar == TRUE);
=======
	}while(ej2_reintentar != 's' && ej2_reintentar != 'n');
	if(ej2_reintentar == 's'){
		ej2_jugar = True;
	}else{
		ej2_jugar = False;
	}

	}while(ej2_jugar == True);
>>>>>>> 8c39c9e87a5bbe0d7353572eac8b8f3aa06aca07

            //Fin Ejercicio 2
          break;
      case 0:
          entrar = FALSE;
          break;
      default:
          printf("ERROR: Opcion incorrecta \n");
  }
}
}

