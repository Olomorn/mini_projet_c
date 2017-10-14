/*ROUSSEAU ET GOUGEON*/

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "listchar.h"

#define clear() printf("\033[2J")

/*=fonction de raffraichissement d'ecran et de recuperation de l'entree=======*/
int getch(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

/*============================================================================*/
int main(/*int argc, char const *argv[]*/) {
  bool stop = false;
	char c = ' ', d = ' ';
	listchar texte = newListe();
	while(!stop)
	{
    d = c; //recupere le deuxieme caractere des touches speciales
		c = (char) getch();
		switch(c)
		{
      case -61 : // caractères accentués
        addCharNext(&texte, c);
        break;
			case 10 : // '/r'
        addCharNext(&texte,c);
        break;
      case 27 : // 'echap'
        break;
      case 43 : // '+' -> deplace le curseur vers la droite (on l'a laisse, c'etait avant qu'on arrive a utiliser les fleches)
        if (currentChar(texte)<0) {
          mvNext(&texte);
        }
        mvNext(&texte);
        break;
      case 45 : // '-' -> deplace le curseur vers la gauche
        if (currentChar(texte)<0) {
          mvPrev(&texte);
        }
        mvPrev(&texte);
        break;
      case 65 :
        if (d == 91) {
          if (currentChar(texte)<0) {
            mvNext(&texte);
          }
          mvNext(&texte);
        }
        break;
      case 66 :
        if (d == 91) {
          if (currentChar(texte)<0) {
            mvPrev(&texte);
          }
          mvPrev(&texte);
        }
        break;
      case 67 :
        if (d == 91) {
          if (currentChar(texte)<0) {
            mvNext(&texte);
          }
          mvNext(&texte);
        }
        break;
      case 68 :
        if (d == 91) {
          if (currentChar(texte)<0) {
            mvPrev(&texte);
          }
          mvPrev(&texte);
        }
        break;
      case 70 : //touche fin > deplace le cruseur a la fin du fichier
        gotoLast(&texte);
        break;
      case 72 :
        gotoFirst(&texte); //touche debut > deplace le curseur au ebut du fichier
        break;
      case 91 : // capture les caractere speciaux
        break;
			case 127 : // 'suppr'
        if (currentChar(texte)<0) {
          delCurrent(&texte);
        }
        delCurrent(&texte);
        break;
			default :
				if(cursPos(texte) == 0 && lineLength(texte) != 0 && currentChar(texte) != 10) {
					addCharPrev(&texte,c);
          mvNext(&texte);
        } else {
          addCharNext(&texte,c);
        }
        break;
    }

    printf("\n");
		clear();
		printList(texte);
		printf("\n");
		for(int i = 0; i< cursPos(texte); i++) {
      printf(" ");
    }
		printf("^");
  }
}
