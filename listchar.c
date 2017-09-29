/*ROUSSEAU ET GOUGEON*/

#include "listchar.h"

listchar newListe() {
  listchar tmp = NULL;
  return tmp;
}

void initCell(listchar curs, char c) {
  Cell *tmp = (Cell)malloc(sizeof(Cell));
  tmp->c = c;
  tmp->suiv = NULL;
  tmp->prec = NULL;
  curs = tmp;
}

void addCharNext (listchar curs, char c) {
  if (isEmpty(curs)) {
    initCell(curs, c);
  } else {
  Cell tmp = (Cell)malloc(sizeof(Cell));
  tmp->c = c;
  tmp->suiv = curs->suiv;
  tmp->prec = curs;
  if (curs->suiv != NULL) {
    curs->suiv->prec = tmp;
  }
  curs->suiv = tmp;
  curs = tmp;
  }
}

void addCharPrev (listchar curs, char c) {
  if (isEmpty(curs)) {
    initCell(curs, c);
  } else {
    Cell tmp = (Cell)malloc(sizeof(Cell));
    tmp->c = c;
    tmp->suiv = curs;
    tmp->prec = curs->prec;
    if (curs->prec != NULL) {
      curs->prec->suiv = tmp;
    }
    curs->prec = tmp;
    curs = tmp;
  }
}

void mvNext(listchar curs) {
  if (curs->suiv != NULL) {
    curs = curs->suiv;
  }
}

void mvPrev(listchar curs) {
  if (curs->prec != NULL) {
    curs = curs->prec;
  }
}

bool isEmpty (listchar curs) {
  
}
