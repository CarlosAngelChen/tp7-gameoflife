#include <stdio.h>
#include "front.h"
#include "states.h"

//imprime la matriz de la nueva generacion, usa @ para indicar vivos y espacios para indicar muertos
void print_mat (int mat[N][M])
{
	int i,j;
	for (i=1; i<(N-1); i++)
	{
		for (j=1; j<(M-1); j++)								//movimiento en matriz 1 por 1
		{
			if (mat [i][j]== ALIVE)
				printf ("|@");
			else
				printf ("| ");

		}
		printf ("|\n");										//pone la ultima barra de la fila de la matriz
	}
}