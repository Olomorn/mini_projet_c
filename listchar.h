/*ROUSSEAU ET GOUGEON*/

#ifndef listcharh
#define listcharh

#include <stdbool.h>

/*Implementation des structures*/

typedef struct Cell *listchar;

struct Cell {
  char c;
  struct Cell *suiv;
  struct Cell *prec;
};

/*Prototypes des fonctions*/

/*Créer une listchar qui pointe sur NULL*/
listchar newListe();

/*Ajoute une valeur à la liste en insertion.
Déplace le pointeur sur la valeur ajoutée.
Si la liste est vide, créé la première cell.*/
void addCharNext(listchar *curs, char val);

void addCharPrev(listchar *curs, char val);

void mvNext(listchar *curs);

void mvPrev(listchar *curs);

void gotoFirst(listchar *curs);

void gotoLast(listchar *curs);

void delCurrent(listchar *curs);

void erase(listchar *curs);

bool isEmpty(listchar curs);

void printList(listchar curs);

#endif /*listcharh*/
