#ifndef GAMEMENU_H_INCLUDED
#define GAMEMENU_H_INCLUDED
char gameMenu()/*printf("<1>   Jeux\n");*/
{
    char C='2';
    char c='g';
    system("cls");
    system("color 0b");
    system("echo ===============================================================================");
	system("echo 			        SUDOKU Game ©");
    system("echo ===============================================================================");
    caracter(6,'\n');
    caracter(4,'\t');
    printf("   Lancer:\n");
    caracter(3,'\t');
    caracter(2,' ');
    caracter(26,'*');
    caracter(2,'\n');
    caracter(3,'\t');
    printf("  <1>   Nouveau Jeux\n");
    caracter(3,'\t');
    printf("  <2> Jeux Enregistre\n");
    caracter(3,'\t');
    printf("  <3>   Menu Principale\n");
    caracter(3,'\t');
    fflush(stdin);/*tna77iha boucle infinie engendrée par scanf() :3*/
    scanf("%[1,2,3]c",&c);
    if(c=='g')
    {
        system("cls");
        C=gameMenu();
        goto last;
    }
    C=c;
last:
    return C;
}
#endif // GAMEMENU_H_INCLUDED
