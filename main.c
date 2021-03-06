/*ROUSSEAU ET GOUGEON*/

#include <stdio.h>
#include <stdlib.h>
#include "listchar.h"

int main(/*int argc, char const *argv[]*/) {
  listchar listeTest = newListe();

  if (isEmpty(listeTest)) {
    printf("Liste est vide\n");
  } else {
    printf("Liste non vide\n");
  }

  addCharNext(&listeTest, 'c');
  addCharNext(&listeTest, ' ');
  addCharNext(&listeTest, '1');
  addCharNext(&listeTest, ' ');
  addCharNext(&listeTest, 't');
  addCharNext(&listeTest, 'e');
  addCharNext(&listeTest, 's');
  addCharNext(&listeTest, 't');

  printList(listeTest); printf("\n");

  if (isEmpty(listeTest)) {
    printf("Liste est vide\n");
  } else {
    printf("Liste non vide\n");
  }

  gotoFirst(&listeTest);

  mvNext(&listeTest);
  addCharPrev(&listeTest, 't');
  addCharPrev(&listeTest, 's');
  addCharPrev(&listeTest, 'e');
  addCharPrev(&listeTest, '\'');

  printList(listeTest); printf("\n");

  mvNext(&listeTest);
  mvNext(&listeTest);
  mvNext(&listeTest);

  delCurrent(&listeTest);
  delCurrent(&listeTest);
  delCurrent(&listeTest);
  delCurrent(&listeTest);

  printList(listeTest); printf("\n");

  gotoFirst(&listeTest);
  delCurrent(&listeTest);
  delCurrent(&listeTest);
  gotoLast(&listeTest);

  if (isEmpty(listeTest)) {
    printf("Liste est vide\n");
  } else {
    printList(listeTest); printf("\n");
  }

  erase(&listeTest);

  if (isEmpty(listeTest)) {
    printf("Liste est vide\n");
  } else {
    printList(listeTest); printf("\n");
  }

  return 0;
}
