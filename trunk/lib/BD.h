#ifndef BD_H_INCLUDED
#define BD_H_INCLUDED

boolean sauvegarder(grille G)
{
    FILE *ft;
    if((ft=fopen(FT,"r"))==NULL)
    {
        fprintf(stderr,"Impossible d'ouvrir la table des fichiers!");
        return faux;
    }
    while(!feof(ft))
    {

    }

    char fichier[25];
    strcpy(fichier,"")

    if((fp=fopen(FICH_SAUV,"w")))
    {

    }

    return vrai;
}



#endif // BD_H_INCLUDED
