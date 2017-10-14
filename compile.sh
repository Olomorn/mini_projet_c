#ROUSSEAU ET GOUGEON
#!/bin/zsh

gcc -Wall -Wextra -pedantic -Wconversion -std=c99 $1 listchar.c -o run
valgrind run
