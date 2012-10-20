#ifndef SUOKU_RISE_H_INCLUDED
#define SUOKU_RISE_H_INCLUDED
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
            taille/=T;
        }
        else
        {
            fprintf(stderr,"\n**ERREUR:Impossible d'acceder au fichier Save**\n");
            return -1;
        }
    }
    system("cls");
    caracter(20,'\n');
    caracter(3,'\t');
    printf("   Charger:\n");
    caracter(3,'\t');
    caracter(2,' ');
    caracter(26,'*');
    caracter(2,'\n');
    caracter(4,'\t');
    if(taille)
        for(;i<(taille/2);i++)
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
    if((choi>taille)||choi<=0)
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

int randomInteger(int n)
{
    if(n)
    {
        now=clock();
        srand(now);
        return(rand()%n);
    }
    else
        return n;
}

void randomFseek(FILE **p)
{
    int i;
    if(*p!=NULL)
    {
        i=randomInteger(5);
        fseek(*p,i*T,0);
    }
}

boolean sudokuCharger(boolean enregistre)
{
    unsigned char middlraw[9][9];

    FILE *fp;
    int i,j;
    if(!enregistre)
    {
        fp=fopen(rawdata,"r");
        if(fp!=NULL)
        {
            randomFseek(&fp);
            fread(middlraw,T,1,fp);
            fclose(fp);
            for(i=0; i<9; i++)
                for(j=0; j<9; j++)
                {
                    raw[i][j]=middlraw[i][j];
                }
            return vrai;
        }
        else
        {
            fprintf(stderr,"\n**ERREUR:Impossible d'acceder au fichier RAW**\n");
            return faux;
        }
    }
    else
    {
        fp=fopen(save,"r");/*partie enregistrées*/
        if(fp!=NULL)
        {
            i=gameSaved();
            if(i!=-1)
            {
                i--;
                fseek(fp,i*T,0);
                fread(raw,T,1,fp);/*charger la complète*/
                fread(sudoku,T,1,fp);/*charger l'incomplète*/
                fclose(fp);
                return vrai;
            }
            else
                return faux;
        }
        else
        {
            fprintf(stderr,"\n**ERREUR:Impossible d'acceder au fichier Save**\n");
            return faux;
        }
    }
}

void sudokuTornado()
{
    int swap1=randomInteger(9);
    int swap2=randomInteger(swap1);
    int i,j;
    i=j=0;
    if(!swap1)swap1++;
    if(!swap2)swap2++;
    if(sudokuCharger(faux)==vrai)
    {
        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
            {
                sudoku[i][j]=raw[i][j];
                if(raw[i][j]==swap1)
                {
                    sudoku[i][j]=raw[i][j]=swap2;
                    continue;
                }
                if(raw[i][j]==swap2)
                {
                    sudoku[i][j]=raw[i][j]=swap1;
                    continue;
                }
            }
        }
    }
}
#endif // SUOKU_RISE_H_INCLUDED
