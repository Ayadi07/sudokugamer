#ifndef SUDOKUMAKER_H_INCLUDED
#define SUDOKUMAKER_H_INCLUDED
void sudokuStarter();
void sudokuInit(grille g)
{
    int i,j;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            g[i][j]=0;
}
void sudokuMaker()
{
    int i=0;
    /*init des variables globales*/
    sudokuInit(raw);
    sudokuInit(sudoku);
    for(i=0;i<81;i++)
        {completer[i]=modifier[i]=0;}
    for(i=0;i<3;i++)
        {persiste[i]=cache[i]=0;}
    /*fin init des variables globales*/
    switch(gameMenu())
    {
    case '3':
    {
        sudokuStarter();
    };
    break;
    case '2':
    {
        joueur(faux);
    }
    break;
    case '1':
    {
        joueur(vrai);
    };
    break;
    }

}
#endif // SUDOKUMAKER_H_INCLUDED
