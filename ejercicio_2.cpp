#include <stdio.h>
#include "./constantes.h"
#include <cstdlib>
#include <ctime>


int main(){	
	Matriz mat;
	int i;
	int j;
	int valor;
	int total;
	int fil;
	int col;
	int diag;
	int random;

/* ====================== Cargar Matriz ========================*/
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
	for(i = 0; i < EJ2_N; i++){
		printf("|");
		for(j=0;j<EJ2_N;j++){
			printf(" %d |",mat[i][j]);
		}
		printf("\n");
	}
/* ====================== FIN Imprimir Matriz ========================*/

	
	

	
/* ====================== Generar Numero Aleatorio ========================*/
	srand(time(0));
	random = (rand() % (9 * EJ2_N)) + 0;
	
/* ====================== Fin Numero Aleatorio ========================*/

	sumas sum;
	printf("Ingresar linea a sumar: (F: fila, C: columna, D: diagonal):");
	scanf("%d", &sum);
	
	total = 0;
	switch(sum){
		case 1:
			/* ====================== Sumar Fila  ========================*/
			printf("Ingresar numero de la fila a sumar:");
			scanf("%d", &fil);
			total = 0;
			for(i=0;i<EJ2_N;i++){
				total = total + mat[fil][i];
			}
			break;
		case 2:
			/* ====================== Sumar Columna  ========================*/
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
				for(i=0;i<EJ2_N;i++){
					total = total + mat[i][i];
				}
			}
			else { 
				if(diag == 2){
			/* ====================== Sumar Diagonal 2  ========================*/
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
