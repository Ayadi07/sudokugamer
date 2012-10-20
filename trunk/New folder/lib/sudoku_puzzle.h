#ifndef SUDOKU_PUZZLE_H_INCLUDED
#define SUDOKU_PUZZLE_H_INCLUDED
#include<time.h>

unsigned short nombreCondidat(unsigned short pos,grille G)
{
    unsigned short x=pos/9;
    unsigned short y=pos%9;
    unsigned short i=1;
    unsigned short nbr=0;

    for(; i<10; i++)
    {
        if((ligne_colonne(1,i,G,x))&&ligne_colonne(0,i,G,y)&&region(i,G,x,y))
            nbr++;
    }
    return nbr;
}
void bar();
void sudokuPuzzle()
{
    int pos=randomInteger(81);
    if(!(clock()%(CLOCKS_PER_SEC)))
        bar();
    if (nombreCondidat(pos,sudoku)==1)
    {
        if(sudoku[pos/9][pos%9])
        {

            sudoku[pos/9][pos%9]=0;
            completer[pos]=1;
            if (!--caches)
            {
                goto fin;
            }
        }
    }
    sudokuPuzzle();
fin:;
}
void bar()
{
    char p='%';
    printf("%2.0f %c \r",(caches*1.0/affichage)*100,p);
}
#endif // SUDOKU_PUZZLE_H_INCLUDED
