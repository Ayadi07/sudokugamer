#ifndef AFFICHER_ESPACE_H_INCLUDED
#define AFFICHER_ESPACE_H_INCLUDED
void afficher_espace()
{
    int j;
    for(j=0; j<9; j++)
    {
        printf("|     ");
        if((j==2)||(j==5)||(j==8)) printf("|");
    }
    printf("\n");
}
#endif // AFFICHER_ESPACE_H_INCLUDED
