/*ROUSSEAU ET GOUGEON*/

#include <stdio.h>
#include <stdlib.h>
#include "listchar.h"

listchar newListe() {
  listchar tmp = NULL;
  return tmp;
}

void initCell(listchar curs, char val) {
  Cell* tmp = malloc(sizeof(Cell));
  tmp->c = val;
  tmp->suiv = NULL;
  tmp->prec = NULL;
  printf("là\n");
  curs = tmp;
  printf("là\n");
}

void addCharNext (listchar curs, char val) {
  if (isEmpty(curs)) {
    initCell(curs, val);
  } else {
    Cell *tmp = malloc(sizeof(Cell));
    tmp->c = val;
    tmp->suiv = curs->suiv;
    tmp->prec = curs;
    if (curs->suiv != NULL) {
      //curs->suiv->prec = tmp;
    }
    curs->suiv = tmp;
    curs = tmp;
  }
}

void addCharPrev (listchar curs, char c) {
  if (isEmpty(curs)) {
    initCell(curs, c);
  } else {
    Cell *tmp = malloc(sizeof(Cell));
    tmp->c = c;
    tmp->suiv = curs;
    tmp->prec = curs->prec;
    if (curs->prec != NULL) {
      //curs->prec->suiv = tmp;
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
  if (curs == NULL) {
    return true;
  }
  return false;
}

void printList (listchar curs) {
  listchar tmp = curs;
  gotoFirst(tmp);
  while (tmp != NULL) {
    printf("%c", tmp->c);
    tmp = tmp->suiv;
  }
  printf("\n");
}

void gotoFirst(listchar curs) {
  if (!(isEmpty(curs))) {
    while (curs->prec != NULL) {
      curs = curs->prec;
    }
  }
}

void gotoLast(listchar curs) {
  if (!(isEmpty(curs))) {
    while (curs->suiv != NULL) {
      curs = curs->suiv;
    }
  }
}
