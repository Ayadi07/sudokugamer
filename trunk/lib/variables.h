#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED

typedef unsigned short grille[9][9];
#define T sizeof(grille)
unsigned short pivot=0;

typedef enum choix {jeux=1,tutorial=2,quitter=3} Choix;
typedef enum absent {faux=0,vrai=1} Absent;
typedef Absent boolean;

unsigned short modifier[81]={0};
unsigned short cache[3]={0};
unsigned short menu_state=0;
unsigned short game_saved_state=0;
clock_t start;
clock_t now;

char *rawdata="data\\Raw";
char *save="data\\Save";

int persiste[3]={0};
#define T2 sizeof(persiste)

long taille=0;

grille raw;/*complete*/
unsigned short completer[81]={0};/*Reference*/
#define T3 sizeof(completer)
grille sudoku;/*visible*/

unsigned short difficulte=1;
unsigned short caches;
long depth=0;
unsigned short affichage=0;

#endif // VARIABLES_H_INCLUDED
