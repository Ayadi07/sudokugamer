#ifndef TROUVE_H_INCLUDED
#define TROUVE_H_INCLUDED
#include"absent_region.h"
#include"absent_ligne_colonne.h"

Absent trouve(unsigned short condid,grille g,unsigned short x,unsigned short y)
{
    if((ligne_colonne(1,condid,g,x,y))&&ligne_colonne(0,condid,g,x,y)&&region(condid,g,x,y))
        return vrai;
    return faux;
}
#endif // TROUVE_H_INCLUDED
