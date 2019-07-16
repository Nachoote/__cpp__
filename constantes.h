#if !defined(MYLIB_CONSTANTS_H)
#define MYLIB_CONSTANTS_H 1

const int EJ2_N = 3;

typedef int Matriz[EJ2_N][EJ2_N];
typedef enum {F=1,C,D,N} ej2_opcion;
typedef enum {False, True} boolean;


/* 
Declarar constantes arriba del #endif
esto despues se incluye a los ejercicios con #include <constantes.h>
*/

#endif
