// Blake Impecoven -- CSCD240 -- Lab 15 -- October, 2015.

#ifndef LAB15_H
#define LAB15_H

#include <stdlib.h>
#include <stdio.h>

// --Prototypes

int readTotal(FILE * fin);
int menu();
int readType();
int addWord(char ***array, int total);

char ** allWordsSorted(int articleTotal, char **articles, int nounTotal, char **nouns, int verbTotal, char **verbs, int prepTotal, char **preps);
char ** createAndFillArray(FILE * fin, int total);
char ** generateSentence(int articleTotal, char **articles, int nounTotal, char **nouns, int verbTotal, char **verbs, int prepTotal, char **preps);
char ** clean(int total, char **array);

void display(char **array, int total);
void displayAllWords(int articleTotal, char **articles, int nounTotal, char **nouns, int verbTotal, char **verbs, int prepTotal, char **preps);

#endif