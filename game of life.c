#include <stdio.h>
#include "matrizctrl.h"
#include "front.h"
#include "back.h"
#include "states.h"

void next_gen (int mat [N][M]);
void print_mat (int mat [N][M]);
int analVec (int, int, int mat [N] [M]);
int parca (int, int, int, int mat [N] [M]);
void futpre (int, int, int, int mat [N] [M]);
void stange (int, int, int mat [N] [M]);

int main (void)
{	
	int mat [N][M]={	
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0},
		{0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0},
		{0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0},
		{0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0},
		{0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0},
		{0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0},
		{0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

	int i, j; 
	int n=0;
	print_mat(mat);											//imprime la generacion 0, y deja espacio
	printf("\n\n");
	while (n<LOOP)											//este es un loop 
	{
		for (i=1; i<(N-1); i++)								//en estos bloques se mueve celda por celda y se fija si la celula morira o vivira
		{
			for (j=1; j<(M-1); j++)
			{	
				stange (i, j, mat);
			}
		}
		next_gen (mat);										//llamada a las dos funciones de fin de generacion
		print_mat (mat);
		printf("\n\n");										//separacion entre matrices
		n++;
	}
	return 0;
}
