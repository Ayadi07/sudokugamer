#ifndef SUDOKUTORNADO_H_INCLUDED
#define SUDOKUTORNADO_H_INCLUDED
#include"sudokuCharger.h"
void sudokuTornado()
{
    int i,j;
    int swap1;
    int swap2;
    swap1=randomInteger(9);
    swap2=randomInteger(swap1);
    i=j=0;
    if(!swap1)swap1++;
    if(!swap2)swap2++;
    if(sudokuCharger(faux)==vrai)
    {
        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
            {
                if(raw[i][j]==swap1)
                {
                    raw[i][j]=swap2;
                    continue;
                }
                if(raw[i][j]==swap2)
                {
                    raw[i][j]=swap1;
                    continue;
                }
            }
        }/*fin permutation de deux chiffres*/
        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
            {
                    sudoku[i][j]=raw[i][j];
            }
        }
    }
}
#endif // SUDOKUTORNADO_H_INCLUDED
