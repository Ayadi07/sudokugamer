#ifndef SUDOKU_PUZZLE_H_INCLUDED
#define SUDOKU_PUZZLE_H_INCLUDED
#include<time.h>
#include"nombreCondidat.h"
void bar()
{
    char p='%';
    printf("%2.0f %c \r",(caches*1.0/affichage)*100,p);
}
void sudokuPuzzle()
{
    int pos=randomInteger(81);

    depth++;
    if(!(clock()%(CLOCKS_PER_SEC)))
        bar();
    if(sudoku[pos/9][pos%9])
    {
        pivot=sudoku[pos/9][pos%9];
        sudoku[pos/9][pos%9]=0;
        if (nombreCondidat(pos,sudoku)==1)
        {
            completer[pos]=1;
            if (!--caches||depth>20000000)
            {
                depth=0;
                goto fin;
            }
        }
        else
            {sudoku[pos/9][pos%9]=pivot;}
    }
    if(depth>20000000)
        {
            depth=0;
            goto fin;
        }
    sudokuPuzzle();
fin:;
}
#endif // SUDOKU_PUZZLE_H_INCLUDED
