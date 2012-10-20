#ifndef ABSENT_RIGION_H_INCLUDED
#define ABSENT_RIGION_H_INCLUDED
Absent region(unsigned short condid,grille g,unsigned short x,unsigned short y)
{
    int X=x-(x%3),Y=y-(y%3);
    int i,j;
    for (i=X; i < X+3; i++)
        for (j=Y; j < Y+3; j++)
            if((g[i][j]==condid)&&((i*9+j)!=(x*9+y)))
                return faux;
    return vrai;
}
#endif // ABSENT_RIGION_H_INCLUDED
