/* Ejercicio 2
Se desea implementar un juego, a partir de una matriz cuadrada de enteros de tamaño N.
Para los ejemplos siguientes supondremos N = 5, pero el programa debe servir para cualquier valor
de N.
Inicialmente, el programa deberá cargar la matriz con enteros entre 0 y 9 solicitados al usuario,
validando que no se ingrese otro valor fuera de este rango.
Una vez cargada, debe mostrar la matriz por pantalla con formato de cuadrícula.
Luego se solicita al usuario que indique cuantos intentos como máximo desea jugar.
A continuación, en el desarrollo de cada intento:
El programa generará un número al azar entre 0 y 9*N el cual se desplegará al usuario.
o (Se debe investigar el procedimiento para producir números aleatorios).
o Por ejemplo, para un valor de N = 5, el número al azar será un entero entre 0 y 45.
Solicitar al usuario indique: número de fila, número de columna, diagonal (principal o
secundaria) o la opción “ninguna”, que considere que la suma de sus elementos es igual al
número obtenido al azar.
En caso de que el usuario haya indicado alguna fila, columna o diagonal, verificar si la suma
de sus elementos es igual al número obtenido al azar. De haber respondido “ninguna”,
verificar que no exista efectivamente alguna fila, columna o diagonal que sume ese valor.
Posterior a la validación se debe informar si el usuario acertó, o que su respuesta no es
correcta mostrando el valor real de la suma de lo elegido por el usuario.
En el caso que el usuario haya elegido que ninguna fila, columna o diagonal suma el valor,
solamente indicar si la respuesta es correcta o no. Ante error, no es necesario indicar donde
se cumple la suma.
Se debe llevar un contador de la cantidad de aciertos y de fracasos del usuario, y darle la chance al
usuario si quiere dejar de jugar (si viene perdiendo o se aburrió), independientemente que aún le
queden intentos por realizar.
La matriz se carga una vez sola al comienzo del juego, pero lo que irá cambiando es el valor al azar
generado en cada uno de los intentos y siempre y cuando el usuario quiera seguir jugando. El juego
terminará su ejecución cuando el usuario lo pida o cuando se llegue al último intento, lo que ocurra
primero.
Al finalizar, se le mostrará al jugador: el total de intentos, total de aciertos, total de fracasos, y un
mensaje final de acuerdo con el siguiente criterio:
* La cantidad de aciertos es contra la cantidad máxima de intentos
Cantidad de aciertos
Mensaje emitido
0 a 1/3 de los intentos
Hay que seguir practicando las sumas!
Más de 1/3 de los intentos a 2/3 de los intentos
No está mal, pero puede y debe mejorar.
Más de 2/3 de los intentos al máximo de intentos-1
Muy buen resultado
Máximo de intentos
Rendimiento impecable!
*/
