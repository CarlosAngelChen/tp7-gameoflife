#include <stdio.h>
#include "matrizctrl.h"
#include "states.h"
#include "back.h"

void futpre (int fil, int col, int flag, int mat [N] [M]);
int parca (int cantVivos, int fil, int col, int mat [N] [M]);
int analVec (int fil, int col, int mat [N][M]);

void stange(int fil, int col, int mat [N] [M])
{	
	int cantViv, flag;
	cantViv = analVec (fil, col, mat); 
	flag = parca(cantViv, fil, col, mat);
	futpre(fil, col, flag, mat);
}

//esta funcion futpre, recibe la posicion a anlizar y un flag de la funcion parca
//hace un XOR entre el flag (lo que le ocurre en la proxima generacion) y el estado actual de la posicion a analizar
//luego del analisis XOR reemplaze el valor en la posicion de matriz a analizar 
void futpre (int fil, int col, int flag, int mat [N] [M])
{
	int x;
	x = flag ^ (mat[fil][col]);
	if(x)
	{
		if (mat[fil][col])
			mat[fil][col] = U_DIED;
		else
			mat[fil][col] = REBORN;	 
	}
}

//esta funcion recibe como parametro de valor la cantidad de vivos de la funcion analVec y la posicion en que se esta analizando
//la funcion parca, decide si en la siguiente generacion la unidad va a estar muerta o viva, devolviendo un flag de 0 o 1 respectivamente
int parca (int cantVivos, int fil, int col, int mat [N] [M])
{
	if(fil==0 || fil==(N-1) || col==0 || col==(N-1))							//Para los casos fuera de los bordes de la matriz, va a ser todo 0
	{
		return FLAGOFF;
	}

	if (cantVivos < 2 || cantVivos > 3)											//si cantidad de vivos es menor que 2 o mayor que 3, la siguiente generacion va a estar muerto
	{
		return FLAGOFF;		
	}

	if (cantVivos == 3)															//si la cantidad de vivos es igual que 3, vive en la siguiente generacion
	{
		return FLAGON;		
	}

	if (cantVivos == 2)															//si la cantidad de vivo es 2, pregunta si en el presente esta vivo o no
	{
		if(mat[fil][col] == ALIVE)												//si esta vivo en el presente, va a estar vivo en la proxima generacio, de lo 
		{																		//contrario, morira en la proxima generacion
			return FLAGON;
		}	
		else
		{
			return FLAGOFF;																
		}	
	}
	return 0;
}

//esta funcion recibe la posicion de la matriz y analiza a sus 8 vecinos contiguos y cuenta la cantidad de vecinos vivos que tiene
int analVec (int fil, int col, int mat [N][M]) 													//si la celda tiene valor 0 esta muerto, de lo contrario, vive
{
	int cantViv =0;

	if (mat[fil][col + 1] == ALIVE  || mat[fil][col + 1] == U_DIED) 														//posicion derecha
	{
		cantViv++;
	}

	if (mat[fil + 1][col + 1] == ALIVE || mat[fil + 1][col + 1] == U_DIED) 													//posicion derecha inferior
	{
		cantViv++;
	}

	if (mat[fil + 1][col] == ALIVE || mat[fil + 1][col] == U_DIED) 														//posicion  abajo
	{
		cantViv++;
	}

	if (mat[fil + 1][col - 1] == ALIVE || mat[fil + 1][col - 1] == U_DIED) 													//posicion izquierda inferior
	{
		cantViv++;
	}

	if (mat[fil][col - 1] == ALIVE || mat[fil][col - 1] == U_DIED) 														//posicion  izquierda
	{
		cantViv++;
	}

	if (mat[fil - 1][col - 1] == ALIVE || mat[fil - 1][col - 1] == U_DIED) 													//posicion izquierda superior
	{
		cantViv++;
	}

	if (mat[fil - 1][col] == ALIVE || mat[fil - 1][col] == U_DIED) 														//posicion  arriba
	{
		cantViv++;
	}

	if (mat[fil - 1][col + 1] == ALIVE || mat[fil - 1][col + 1] == U_DIED) 													//posicion  derecha superior
	{
		cantViv++;
	}

	return cantViv;
}
