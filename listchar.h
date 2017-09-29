/*ROUSSEAU ET GOUGEON*/

#ifndef listchar
#define listchar

#include <stdbool.h>

/*Implementation des structures*/
typedef struct Cell {
  char c;
  Cell *suiv;
  Cell *prec;
} Cell;

typedef struct Cell *listchar;

/*Prototypes des fonctions*/

/*Créer une listchar qui pointe sur NULL*/
listchar newListe();

void mvNext(listchar curs);

void mvPrev(listchar curs);

void gotoFirst(listchar curs);

void gotoLast(listchar curs);

/*Ajoute une valeur à la liste en insertion.
Déplace le pointeur sur la valeur ajoutée.
Si la liste est vide, créé la première cell.*/
void addCharNext(listchar curs, int val);

void addCharPrev(listchar curs, int val);

void delCurrent(listchar curs);

void erase(listchar curs);

bool isEmpty(listchar curs);

void printList(listchar curs);

#endif /*listchar*/
