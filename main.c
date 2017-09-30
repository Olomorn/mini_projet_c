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

  printList(listeTest);

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

  printList(listeTest);

  return 0;
}
