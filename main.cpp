#include <stdio.h>
#include <cstdlib>		// Libreria estandar de C, necesaria para la generacion de numeros aleatorios (rand)
#include <ctime>		// Libreria para manejo de fechas y tiempo, necesaria para inicializar el generador de numeros aleatorios (time)
#include <stdlib.h>
#include <iostream>

/*Obligatorio Programacion 1
Integrantes: 
Ignacio Otegui 
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
const int EJ2_N = 3;
const int MAX = 100;

typedef int Matriz[EJ2_N][EJ2_N];
typedef enum {F=1,C,D,N} ej2_opcion;
typedef enum {FALSE, TRUE} boolean;
typedef char string [MAX];

boolean seguir = FALSE;
int maxPalabras ;// cantidad maxima de palabras a buscar en del arreglo, se la pedimos al usuario
int cantPalabrasMax = 0;
int l;
int aux;
int ej1_max;
int oraciones;
int inicio_oracion;
int largo_palabra;
int coincidencias;
int dif;
int p ;
int k;
char car;
string ej1_cad;
string ej1_cad_upper;
string palabra;
boolean ej1_existe = FALSE;
boolean ej1_valido = FALSE;

//Fin declaraciones Ejercicio 1
//Inicio Declaraciones Ejercicio 2
Matriz mat;             // Matriz de N * N
unsigned int i;         // Entero para recorrer array
unsigned int j;         // Entero para recorrer array
unsigned int valor;     // Entero para evaluar numero ingresado por el usuario en la carga de matriz
unsigned int total;     // Entero para guardar el total de la suma de fila, columna o diagonal  
unsigned int fil;       // Entero para seleccionar la fila que se quiere sumar
unsigned int col;       // Entero para indicar la columna que se quiere sumar
unsigned int diag;      // Entero para indicar diagonal principal o secundaria
unsigned int aleatorio;    // Entero para guardar numero aleatorio entre  0 y (9 * N)
unsigned int intentos;  // Entero para guardar numero de intentos que se desea jugar
unsigned int intento; // Entero para control del loop principal
boolean filas[EJ2_N];
boolean columnas[EJ2_N];
boolean diagonales[2];
boolean ninguno;
unsigned int aciertos;
unsigned int errores;
boolean jugar;
char reintentar;

//Fin Declaraciones Ejercicio 2


int main()
{
    boolean entrar = TRUE;
    int opcion = 0;
    printf("============================================\n");
    printf("=                                          =\n");
    printf("=     Trabajo Obligatorio Programacion     =\n");
    printf("=                                          =\n");
    printf("============================================\n");
    while(entrar)
    {
      printf("Ingrese el numero del ejercicio que desea: \n");
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
            calcule la cantidad total de palabras que lo componen y avise al docente: cuantas palabras posee, y
            (en caso de excederse) por cuantas palabras está pasado el texto respecto a lo pretendido por el
            docente.

            */

             //declaro la variable donde cargare las letras del string
            
            ////////////// Parte de ingresar la oracion y mostrarla al usuario///////////////////////////
            printf ("\nIngrese una oracion que comience con una letra mayuscula, y termine con '.': \n"); //solicito al usuario una oracion y le indico como debe terminarla correctamente
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
            printf ("\nTexto ingresado: \n"); //muestro al usuario la oracion que ingreso con un while
            while (ej1_cad[l] != '\0')
                {
                    printf ("%c", ej1_cad[l]);
                    l++;
                }
	    printf("\n");
	    printf("Cantidad de caracteres: %d\n", l);

            /* ================ Fin Imprimir Cadena ================ */

            

            /* ================ Validar oracion ================ */
	    l =0;
	    oraciones = 0;
	    do{
	    	if(ej1_cad[l] >= 'A' && ej1_cad[l] <= 'Z' && inicio_oracion == 0){
			inicio_oracion = 1;
		}else{
			if((ej1_cad[l] == '.' && inicio_oracion == 1 && ej1_cad[l + 1] != '.') || ej1_cad[l + 1] == '\0'){
				oraciones = oraciones + 1;
				inicio_oracion = 0;
			}
		}
		l++;
	    }while(ej1_cad[l] != '\0');

	    printf("Cantidad de oraciones correctas: %d\n", oraciones);

            /* ================ Fin Validar oracion ================ */

            /* Convertir texto a mayusculas para la evaluacion */
            l = 0;
            while (ej1_cad[l] != '\0'){
                if (!(ej1_cad[l] >= 'A' && ej1_cad[l] <= 'Z') && !(ej1_cad[l] >= 'a' && ej1_cad[l] <= 'z') && ej1_cad[l] != ' '){
                    ej1_cad_upper[l] = ' ';
                }
                else {
                    if (ej1_cad[l] >= 'a' && ej1_cad[l] <= 'z'){
                        ej1_cad_upper[l] = ej1_cad[l] - 32;
                    }
                    else{
                        ej1_cad_upper[l] = ej1_cad[l];
                    }
                }
                l++;
            }            
            ej1_cad_upper[l] = '\0';


            /* ================ Solicitar maximo y  contar palabras ================ */
            aux =0;
            clean_stdin(); //limpio la variable
            printf ("\nIngrese una cantidad maxima de palabras: ");
            scanf ("%d", &ej1_max );
            



            l = 0;
            while (ej1_cad_upper[l] !='\0'){
                if ((ej1_cad_upper[l] == ' ' || ej1_cad_upper[l] == '.')&& ej1_cad_upper[l -1] != ' '){
                    aux = aux + 1;
                }
                l++;
            }

            printf ("\nHay %d cantidad palabras la oracion \n",aux);
            dif = 0;
            dif=ej1_max-aux;
            printf ("\n La diferencia de palabras entre lo solcitado e ingresado es : %d palabras \n",dif);



            /* ================ Fin Solicitar maximo y  contar palabras ================ */

            ////////////// Parte  saber si una palabra dada esta en la oracion ///////////////////////////







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
            clean_stdin();
            scanf ("%c",&car);


            /* Convertir texto a mayusculas para la evaluacion */
            l = 0;
            while (car != '\n'){
                if (!(car >= 'A' && car <= 'Z') && !(car >= 'a' && car <= 'z') && car != ' '){
                    
                }
                else {
                    if (car >= 'a' && car <= 'z'){
                        palabra[l] = car - 32;
                    }
                    else{
                        palabra[l] = car;
                    }
                }
                l++;
                scanf ("%c",&car);
            }            
            palabra[l] = '\0';

            l=0;
            printf("==========================\n");
            while(palabra[l] != '\0'){
                printf("%c", palabra[l]);
            l++;
            }
            
            largo_palabra = l;
            l = 0;


	    coincidencias = 0;
	    
            boolean letra;
            while (ej1_existe == FALSE && ej1_cad[l] != '\0'){
                for(k = 0; k < largo_palabra ; k++){
                   if (palabra[k] == ej1_cad_upper[l + k]){
                          coincidencias = coincidencias +1;   
                   }
		   else{
		   	coincidencias = 0;
		   }
                }
                if(coincidencias  == largo_palabra){
                    ej1_existe = TRUE;                
                }
                l++;
            }

/*
            while (!ej1_existe && ej1_cad[l] != '\0' && (ej1_cad[l] !='.') && (ej1_cad[l] !=' '))
            {
            if (ej1_cad[l] == car)
            ej1_existe = TRUE;
            else
            l++;
            }
*/
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

	jugar = TRUE;

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
	printf("Indique cuantos intentos desea jugar:");
	scanf("%d", &intentos);
	clean_stdin();

	for(intento = 1; intento <= intentos; intento++){

		aleatorio = (rand() % (9 * EJ2_N));
		ninguno = TRUE;

		system("clear");
		printf("==============================\n");
		printf("\t  Ejercicio 2 \n");
		printf("==============================\n");
		printf("\tIntento numero: %4d\n", intento);
		printf("\tIntentos restantes: %1d\n", (intentos - intento));
		printf("==============================\n");
		printf("\tAciertos: %d\n\tErrores: %d\n", aciertos, errores);
		printf("------------------------------\n");
		printf("\tNumero Aleatorio: %d\n", aleatorio);
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
					if(total == aleatorio){
						filas[i] = TRUE;
						ninguno = FALSE;
					}
					else{
						filas[i] = FALSE;
					}
				}


				for(i = 0;i < EJ2_N;i++){
					total = 0;
					for(j=0;j<EJ2_N;j++){
						total = total + mat[j][i];
					}
					if(total == aleatorio){
						columnas[i] = TRUE;
						ninguno = FALSE;
					}
					else{
						columnas[i] = FALSE;
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
				if(total == aleatorio){
					diagonales[0] = TRUE;
					ninguno = FALSE;
				}
				else{
					diagonales[0] = FALSE;
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

				if(total == aleatorio){
					diagonales[1] = TRUE;
					ninguno = FALSE;
				}
				else{
					diagonales[1] = FALSE;
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
				if(filas[fil] == aleatorio){
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
		jugar = TRUE;
	}else{
		jugar = FALSE;
	}

	}while(jugar == TRUE);

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

