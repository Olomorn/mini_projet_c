/*ROUSSEAU ET GOUGEON*/

#include <stdio.h>
#include <stdlib.h>
#include "listchar.h"

/*=cree une liste==============================================================*/
listchar newListe() {
  listchar tmp = NULL;
  return tmp;
}

/*=cree la premiere cellule de la liste=======================================*/
void initCell(listchar *curs, char val) {
  struct Cell* tmp = malloc(sizeof(struct Cell));
  tmp->c = val;
  tmp->suiv = NULL;
  tmp->prec = NULL;
  (*curs) = tmp;
}

/*=ajoute un caractere apres le caractere courrant============================*/
//deplace le curseur sur le caractere cree
//si la liste est vide, cree la premiere cellule
void addCharNext (listchar *curs, char val) {
  if (isEmpty(*curs)) {
    initCell(curs, val);
  } else {
    struct Cell *tmp = malloc(sizeof(struct Cell));
    tmp->c = val;
    tmp->suiv = (*curs)->suiv;
    tmp->prec = (*curs);
    if ((*curs)->suiv != NULL) {
      (*curs)->suiv->prec = tmp;
    }
    (*curs)->suiv = tmp;
    (*curs) = tmp;
  }
}

/*=ajoute un caractere avant le caractere courrant============================*/
//deplace le curseur sur le caractere cree
//si la liste est vide, cree la premiere cellule
void addCharPrev (listchar *curs, char c) {
  if (isEmpty(*curs)) {
    initCell(curs, c);
  } else {
    struct Cell *tmp = malloc(sizeof(struct Cell));
    tmp->c = c;
    tmp->suiv = (*curs);
    tmp->prec = (*curs)->prec;
    if ((*curs)->prec != NULL) {
      (*curs)->prec->suiv = tmp;
    }
    (*curs)->prec = tmp;
    (*curs) = tmp;
  }
}

/*=deplace le curseur sur le caractere suivant================================*/
bool mvNext(listchar *curs) {
  if ((*curs)->suiv != NULL) {
    (*curs) = (*curs)->suiv;
    return true;
  }
  return false;
}

/*=deplace le curseur sur le caractere precedent==============================*/
bool mvPrev(listchar *curs) {
  if ((*curs)->prec != NULL) {
    (*curs) = (*curs)->prec;
    return true;
  }
  return false;
}

/*=deplace le curseur au debut de la liste====================================*/
void gotoFirst(listchar *curs) {
  if (!(isEmpty(*curs))) {
    while ((*curs)->prec != NULL) {
      (*curs) = (*curs)->prec;
    }
  }
}

/*=deplace le curseur a la fin de la liste====================================*/
void gotoLast(listchar *curs) {
  if (!(isEmpty(*curs))) {
    while ((*curs)->suiv != NULL) {
      (*curs) = (*curs)->suiv;
    }
  }
}

/*=supprime le caractere selectionne==========================================*/
void delCurrent(listchar *curs) {
  listchar tmp = *curs;
  if(tmp != NULL) {
    if (tmp->suiv == NULL && tmp->prec == NULL) {
      (*curs) = NULL;
    } else if (tmp->suiv != NULL && tmp->prec == NULL) {
      tmp->suiv->prec = NULL;
      (*curs) = (*curs)->suiv;
    } else if (tmp->suiv == NULL && tmp->prec != NULL) {
      tmp->prec->suiv = NULL;
      (*curs) = (*curs)->prec;
    } else {
      tmp->prec->suiv = tmp->suiv;
      tmp->suiv->prec = tmp->prec;
      (*curs) = (*curs)->prec;
    }
    free(tmp);
  }
}

/*=vide la liste==============================================================*/
void erase(listchar *curs) {
  if((*curs) != NULL) {
    gotoFirst(curs);
    while ((*curs) != NULL) {
      delCurrent(curs);
    }
  }
}

/*=test si la liste est vide==================================================*/
bool isEmpty (listchar curs) {
  if (curs == NULL) {
    return true;
  }
  return false;
}

/*=affiche la liste===========================================================*/
void printList (listchar curs) {
  listchar tmp = curs;
  gotoFirst(&tmp);
  while (tmp != NULL) {
    printf("%c", tmp->c);
    tmp = tmp->suiv;
  }
  //printf("\n");
}

/*=donne la position entre 2 '\n' (sur une ligne) ou se trouve le curseur=====*/
int lineLength(listchar curs) {
  int i = 0;
  listchar tmpCurs = curs;
  if (!isEmpty(curs)) {
    while (tmpCurs->c != '\n' && tmpCurs->prec != NULL) {
      mvPrev(&tmpCurs);
    }
    while (tmpCurs->c != '\n' && mvNext(&tmpCurs)) {
      if (tmpCurs->c != -61) { //si c'est un caractere, accentue il est compose de deux caracteres, donc il ne faut en compter qu'un seul.
        i++;
      }
    }
  }
  return i;
}

/*=donne la position du curseur depuis le dernier '\n'========================*/
int cursPos(listchar curs) {
  int i = 0;
  if (!isEmpty(curs)) {
    while (curs->c != '\n' && mvPrev(&curs)) {
      if (curs->c != -61) { //si c'est un caractere accentue, il est compose de deux caracteres, donc il ne faut en compter qu'un seul.
        i++;
      }
    }
  }
  return i;
}

/*=donne la valeur du caractere pointe========================================*/
char currentChar (listchar curs) {
  if (!isEmpty(curs)){
    return curs->c;
  } else {
    return ' ';
  }
}
