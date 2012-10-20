#ifndef NOMBRECONDIDAT_H_INCLUDED
#define NOMBRECONDIDAT_H_INCLUDED
unsigned short nombreCondidat(unsigned short pos,grille G)
{
    unsigned short x=pos/9;
    unsigned short y=pos%9;
    unsigned short i=1;
    unsigned short nbr=0;

    for(; i<10; i++)
    {
        if(trouve(i,G,x,y))
            nbr++;
    }
    return nbr;
}
#endif // NOMBRECONDIDAT_H_INCLUDED
