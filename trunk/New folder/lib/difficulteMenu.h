#ifndef DIFFICULTEMENU_H_INCLUDED
#define DIFFICULTEMENU_H_INCLUDED
void difficulteMenu()
{
    char c='g';
    char rep;
    difficulte=4;
    system("cls");
    system("color 0b");
    system("echo ===============================================================================");
	system("echo 			        SUDOKU Game ©");
    system("echo ===============================================================================");
    caracter(6,'\n');
    caracter(4,'\t');
    printf(" Difficulte :\n");
    caracter(3,'\t');
    caracter(2,' ');
    caracter(26,'*');
    caracter(2,'\n');
    caracter(4,'\t');
    printf("<1> Facile\n");
    caracter(4,'\t');
    printf("<2> Difficile\n");
    caracter(4,'\t');
    printf("<3> Challenge!\n");
    caracter(4,'\t');
    printf("<q> Menu Jeux\n");
    here:
    fflush(stdin);
    c=getch();
    switch(c)
    {
        case '1':;break;
        case '2':;break;
        case '3':;break;
        case 'q':sudokuMaker();break;
        default:goto here;break;
    }
    printf("Difficulte choisie: %c|<o>/<n>?|\r",c);
    here2:
    fflush(stdin);
    rep=getch();
    switch(rep)
    {
        case 'o':;break;
        case 'O':;break;
        case 'n':printf("                                   \r");goto here;break;
        case 'N':printf("                                   \r");goto here;break;
        default:goto here2;break;
    }
    difficulte=(c=='1')?1:((c=='2')?2:3);
    affichage=caches=(difficulte==1)?20:(16*difficulte);
    persiste[0]=difficulte;
}
#endif // DIFFICULTEMENU_H_INCLUDED
