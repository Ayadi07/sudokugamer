#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
char menu()
{
    menu_state++;
    char C='2';
    char c='x';
    system("cls");
    system("color b0");
    system("echo ===============================================================================");
	system("echo 			        SUDOKU Game ©");
    system("echo ===============================================================================");
    caracter(6,'\n');
    caracter(3,'\t');
    printf("   Inserer votre choix SVP:\n");
    caracter(3,'\t');
    caracter(2,' ');
    caracter(26,'*');
    caracter(2,'\n');
    caracter(4,'\t');
    printf("<1>   Jeux\n");
    caracter(4,'\t');
    printf("<2> Tutorial\n");
    caracter(4,'\t');
    printf("<3>  Quitter\n");
    caracter(4,'\t');
    fflush(stdin);/*tna77iha boucle infinie engendrée par scanf() :3*/
    scanf("%[1,2,3]c",&c);
    if(c=='x')
    {
        menu_state++;
        system("cls");
        C=menu();
        goto last;
    }
    C=c;
last:
    return C;
}
#endif // MENU_H_INCLUDED
