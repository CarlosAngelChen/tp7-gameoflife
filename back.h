#ifndef BACK_H
#define BACK_H

#define FLAGOFF 0                                   //estos flags se usan en el analisis de vida de las celulas, 
#define FLAGON 1                                    //1 indica que va a vivir, 0 que va a morir												//estos flags se usan en el analisis de vida de las celulas, 1 indica que va a vivir, 0 que va a morir


void stange(int fil, int col, int mat [N] [M]);     //Resume todo el analisis de cambio de generacion

void next_gen (int mat[N][M]);                      //Actualiza los valores de la matriz para la nueva generacion 

#endif /*BACK_H*/


