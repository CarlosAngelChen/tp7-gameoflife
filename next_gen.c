#include <stdio.h>
#include "matrizctrl.h"
#include "states.h"
#include "back.h"

//usando la informacion guardada en cada posicion, actualiza el estado de las celulas.
void next_gen (int mat[N][M])
{
	int i,j;
	for (i=1; i<(N-1); i++)
	{
		for (j=1; j<(M-1); j++)								//movimiento dentro de la matriz 1 por 1
		{	
			switch (mat [i][j])
			{
				case DEAD: case ALIVE:						//casos en los que no cambian
				{	
					break;
				}
				case REBORN:								//muerta a viva
				{
					mat [i][j]= ALIVE;	
					break;
				}
				case U_DIED:								//viva a muerta
				{
					mat [i][j]= DEAD;
					break;
				}
				default:									//si o si deberia ir a alguno de los anteriores, por precaucion avisa error
				{
					printf ("ERROR");
				}
			}
		}
	}
}