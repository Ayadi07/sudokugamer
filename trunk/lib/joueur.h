#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include"difficulteMenu.h"
#include"jouer.h"
void joueur(boolean type)
{
    char c='x';
    if(!type)
    {
        if(sudokuCharger(!type))
        {
            goto jouer;
        }
        else
        {
            sudokuMaker();
        }
    }
    else
    {
        difficulteMenu();
        sudokuTornado();
        printf("\nChargement de votre partie....\n");
        sudokuPuzzle();
        jouer:
        system("cls");
        system("color f1");
        afficher(sudoku,0);
        start=clock();
        printf("\n|<q> pour quitter |:");
        printf("\n|<r> Pour retour arriere|:");
        printf("\n|<m> pour modifier|:");
        /*contrôle de saisie*/
loop:
        fflush(stdin);
        c=getch();
        switch(c)
        {
        case 'm':
            jouer();
            break;
        case 'M':
            jouer();
            break;
        case 'Q':
            sudokuMaker();
            break;
        case 'q':
            sudokuMaker();
            break;
        default:
            goto loop;
            break;

        }
        /*Fin contrôle*/
    }
}
#endif // JOUEUR_H_INCLUDED
