#ifndef ABSENT_LIGNE_COLONNE_H_INCLUDED
#define ABSENT_LIGNE_COLONNE_H_INCLUDED
Absent ligne_colonne(unsigned short sens,unsigned short condid,grille g,unsigned short x,unsigned short y)
{
    int s;
    for(s=0;s<9; s++)
    {
        if(sens)
        {
            if((g[x][s]==condid)&&(s!=y))
                return faux;
        }
        else
        {
            if((g[s][y]==condid)&&(s!=x))
                return faux;
        }
    }
    return vrai;
}
#endif // ABSENT_LIGNE_COLONNE_H_INCLUDED
