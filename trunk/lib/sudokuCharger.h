#ifndef SUDOKUCHARGER_H_INCLUDED
#define SUDOKUCHARGER_H_INCLUDED
#include"gameSaved.h"
void sudokuMaker();
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
    FILE *fp;
    int i;
    if(!enregistre)
    {
        fp=fopen(rawdata,"r");
        if(fp!=NULL)
        {
            randomFseek(&fp);
            fread(raw,T,1,fp);
            fclose(fp);
            return vrai;
        }
        else
        {
            fprintf(stderr,"\n**ERREUR:Impossible d'acceder au fichier RAW**\n");
            system("pause");
            sudokuMaker();
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
                fseek(fp,i*(2*T+T2+T3),0);
                fread(raw,T,1,fp);/*charger la complète*/
                fread(sudoku,T,1,fp);/*charger l'incomplète*/
                fread(persiste,T2,1,fp);
                fread(completer,T3,1,fp);
                fclose(fp);
                return vrai;
            }
            else
            {
                fclose(fp);
                return faux;
            }
        }
        else
        {
            fprintf(stderr,"\n**ERREUR:Impossible d'acceder au fichier Save**\n");
            system("pause");
            sudokuMaker();
            return faux;
        }
    }
}
#endif // SUDOKUCHARGER_H_INCLUDED
