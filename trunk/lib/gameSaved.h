#ifndef GAMESAVED_H_INCLUDED
#define GAMESAVED_H_INCLUDED
#include<string.h>
int gameSaved()
{
    FILE *fp;
    long i=0;
    long choi=-1;
    char C[2];
    if(!game_saved_state)
    {
        game_saved_state++;
        fp=fopen(save,"r");
        if(fp!=NULL)
        {
            fseek(fp,0L,2);
            taille=ftell(fp);
            fclose(fp);
            taille/=(2*T+T2+T3);
        }
        else
        {
            fprintf(stderr,"\n**ERREUR:Impossible d'acceder au fichier Save**\n");
            return -1;
        }
    }
    system("cls");
    system("echo ===============================================================================");
	system("echo 			        SUDOKU Game ©");
    system("echo ===============================================================================");
    caracter(6,'\n');
    caracter(3,'\t');
    printf("   Charger:(<q>quitter)\n");
    caracter(3,'\t');
    caracter(2,' ');
    caracter(26,'*');
    caracter(2,'\n');
    caracter(2,'\t');
    if(taille)
        for(;i<taille;i++)
            printf("<%ld> ",i+1);
    else
    {
        printf("Pas de jeux deja enregistrer!\n");
        return -1;
    }

    printf("\n");
    caracter(4,'\t');
    fflush(stdin);/*tna77iha boucle infinie engendrée par scanf() :3*/
    scanf("%s",C);
    choi=atol(C);
    if(!strcmpi("q",C))
    {
        return -1;
    }
    if(choi>taille||choi<=0)
    {
        system("cls");
        return gameSaved();
    }
    else
    {
        game_saved_state=0;
        return (int)choi;
    }
}
#endif // GAMESAVED_H_INCLUDED
