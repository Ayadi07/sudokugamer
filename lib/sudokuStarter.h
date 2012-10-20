#ifndef SUDOKUSTARTER_H_INCLUDED
#define SUDOKUSTARTER_H_INCLUDED
#include"menu.h"
#include"gameMenu.h"
#include"sudokuMaker.h"
#include"tuto.h"
void sudokuStarter()
{
    sudokuInit(raw);
    sudokuInit(sudoku);
    if(!menu_state)system("main.bat");
    switch(menu())
    {
    case '2':
        tuto();
        break;
    case '1':
    {
        system("cls");
        system("jeux.bat");
        sudokuMaker();
    };
    break;
    case '3':
    {
        printf("\nA la prochaine fois ;)\n");
        getch();
        exit(0);
        system("exit");
    };
    break;

    }
}
#endif // SUDOKUSTARTER_H_INCLUDED
