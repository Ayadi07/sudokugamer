#ifndef AFFICHER_H_INCLUDED
#define AFFICHER_H_INCLUDED
#include"afficher_espace.h"
#include"caractere.h"
#include"afficher_ligne.h"

void afficher(grille r,int validation)
{
    int i,j;
    char c='A';
    system("cls");
    system("echo ===============================================================================");
    system("echo 			        SUDOKU Game ©");
    system("echo ===============================================================================");
    caracter(6,'\n');
    caracter(3,' ');
    for(j=0; j<9; j++)
    {
        printf("|  %d  ",j+1);
        if((j==2)||(j==5)||(j==8)) printf("|");
    }
    printf("\n");

    for(i=0; i<9; i++)
    {
        printf("   ");
        afficher_ligne();

        if((i==3)||(i==6))
        {
            printf("   ");
            afficher_ligne();
        }

        printf("   ");
        afficher_espace();
        printf(" %c ",c++);
        for(j=0; j<9; j++)
        {
            if(!r[i][j])
                printf("|     ");
            else
            {
                if(completer[i*9+j])
                {
                    if(validation&&(raw[i][j]!=r[i][j]))
                        printf("| X%huX ",r[i][j]);
                    else
                        printf("| *%hu  ",r[i][j]);
                }
                else
                    printf("|  %hu  ",r[i][j]);
            }
            if((j==2)||(j==5)||(j==8)) printf("|");
        }
        printf("\n");
        printf("   ");
        afficher_espace();
    }
    printf("   ");
    afficher_ligne();
}
#endif // AFFICHER_H_INCLUDED
