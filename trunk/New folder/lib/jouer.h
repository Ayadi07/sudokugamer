#ifndef JOUER_H_INCLUDED
#define JOUER_H_INCLUDED
void sudokuMaker();
boolean retour()
{
    if(cache[2])
    {
        sudoku[cache[0]][cache[1]]=0;
        modifier[81-cache[2]]=0;
        cache[2]--;
        persiste[2]--;
        afficher(sudoku,0);
        printf("\n|<q> pour quitter |:");
        printf("\n|<v> pour valider |:");
        printf("\n|<r> Pour retour arriere|:\n");
        printf("\nAction annulee a |<%c><%c>|",cache[0]+65,cache[1]+49);
        getch();
        cache[0]=(cache[2])?(modifier[81-cache[2]]/9):82;
        cache[1]=(cache[2])?(modifier[81-cache[2]]%9):81;
        return vrai;
    }
    return faux;
}
boolean checkAll()
{
    int i,j=0;
    for(i=0;i<81;i++)
    if(completer[i])
    {
        if(sudoku[i/9][i%9]!=raw[i/9][i%9])
        {
            system("color fc");j++;
            printf("\nNombre invalide a |<%c><%c>|",(i/9)+65,(i%9)+49);
        }
    }
    if(j)
    {
        printf("\nVerification terminee: votre grille est invalide\n");
        getch();
        system("color f1");
        return faux;
    }
    else
    {
        persiste[1]+=(now-start)/CLOCKS_PER_SEC;
        printf("\nVerification terminee: votre grille est valide :) %c",1);
        printf("\nVotre score est              |%.0f|   ",10.0*persiste[0]*persiste[2]*persiste[2]/persiste[1]);
        getch();
        return vrai;
    }

}
boolean check(char l,char c, char v)
{
    unsigned short val=v-48;
    int pos=(((int)l<97)?((int)l)-65:((int)l)-97)*9+((int)c)-49;
    if(!completer[pos])
    {
        system("color fc");
        printf("\rLa case est deja remplie!         ");
        getch();
        system("color f1");
        printf("\r                         \r");
        return faux;
    }
    else
    {
        if(trouve(val,sudoku,(pos/9),(pos%9)))/*valeur absente sur L C R*/
        {
            sudoku[pos/9][pos%9]=val;/*insertion*/
            modifier[80-cache[2]]=pos;/*sauvegarder la position modifiée*/
            cache[2]++;/*nombre de sauvegardes*/
            persiste[2]++;
            cache[0]=pos/9;/*sauvegarder la dernière position modifiée*/
            cache[1]=pos%9;
            return vrai;
        }
        else
        {
            system("color fc");
            printf("\rValeure invalide!                 ");
            getch();
            system("color f1");
            printf("\r                         \r");
            return faux;
        }
    }
}
boolean sauvegarder()
{
    long taille;
    char c;
    FILE *ft;
    now=clock();
    persiste[1]+=(now-start)/CLOCKS_PER_SEC;
    printf("\rdifficultee: %d|caches: %d|temps :%dhh:%dmm:%dss  ",persiste[0],persiste[2],persiste[1]/3600,(persiste[1]%3600)/60,(persiste[1]%3600)%60);
    getch();
    here:
    printf("\rVoulez vous enregistrer?<o>/<n>                   ");
    fflush(stdin);
    c=getch();
    if((c=='o')||(c=='O'))
    {

        if((ft=fopen(save,"a"))==NULL)
        {
            fprintf(stderr,"Impossible d'ouvrir le fichier d'enregistrement!");
            return faux;
        }
        fwrite(raw,T,1,ft);
        fwrite(sudoku,T,1,ft);
        fwrite(persiste,T2,1,ft);
        fwrite(completer,T3,1,ft);
        fseek(ft,0L,2);
        taille=ftell(ft);
        taille/=(2*T+T2+T3);
        fclose(ft);
        printf("\nVotre partie est enregistree avec le numéro: | %ld |",taille);
        getch();
        sudokuMaker();

        return vrai;
    }
    else
        if((c=='n')||(c=='N'))
        {
            printf("\nGood bye ;)");
            getch();
            sudokuMaker();
            return vrai;
        }
        else
        {
            goto here;
        }
}
void jouer()
{
    char l='x';
    char c='x';
    char v='x';
    printf("\rInserer <ligne><colonne><valeur>: ");
check1:
    fflush(stdin);
    l=getch();
    switch(l)
    {
    case 'Q':
        sauvegarder();
        break;
    case 'q':
        sauvegarder();
        break;
    case 'v':
    {
        if(checkAll())
        {
            jouer();
        }
        else
        {
            afficher(sudoku,1);
            printf("\n|<q> pour quitter |:");
            printf("\n|<v> pour valider |:");
            printf("\n|<r> Pour retour arriere|:");
            jouer();
        }
    }
    break;
    case 'V':
    {
        if(checkAll())
        {
            sauvegarder();
        }
        else
        {
            afficher(sudoku,1);
            printf("\n|<q> pour quitter |:");
            printf("\n|<v> pour valider |:");
            printf("\n|<r> Pour retour arriere|:");
            jouer();
        }
    }
    break;
    case 'r':
    {
        retour();
        jouer();
    }
    break;
    case 'R':
    {
        retour();
        jouer();
    }
    break;
    default :
        if((('a'>l)||('i'<l))&&(('I'<l)||('A'>l)))goto check1;
        break;
    }
    putchar(l);
check2:
    fflush(stdin);
    c=getch();
    switch(c)
    {
    case 'Q':
        sauvegarder();
        break;
    case 'q':
        sauvegarder();
        break;
    case 'r':
    {
        retour();
        jouer();
    }
    break;
    case 'R':
    {
        retour();
        jouer();
    }
    break;
    default :
        if(('1'>c)||('9'<c))goto check2;
        break;
    }
    putchar(c);
check3:
    fflush(stdin);
    v=getch();
    switch(v)
    {
    case 'Q':
        sauvegarder();
        break;
    case 'q':
        sauvegarder();
        break;
    case 'r':
    {
        retour();
        jouer();
    }
    break;
    case 'R':
    {
        retour();
        jouer();
    }
    break;
    default :
        if(('1'>v)||('9'<v))goto check3;
        break;
    }
    putchar(v);
    if(check(l,c,v))
    {
        afficher(sudoku,0);
        printf("\n|<q> pour quitter |:");
        printf("\n|<v> pour valider |:");
        printf("\n|<r> Pour retour arriere|:\n");
        jouer();
    }
    else
    {
        jouer();
    }
}
#endif // JOUER_H_INCLUDED
