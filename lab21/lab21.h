// Blake Impecoven -- CSCD240 -- Lab 21 -- November, 2015.

#ifndef LAB21_H
#define LAB21_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myUtils.h"

#define MAX 100

// Prototypes
int menu();
int readNumber(int baseVal);
char * convert(int num, int fromBase, char *fromVals, int toBase, char *toVals);
void printResults(int originalValue, int fromBase, int toBase, char *converted);
int readBase(char *prompt);
char * readBaseValues(char *prompt, int baseVal);
char * readDiffBaseNumber(int baseVal);
char * convertDiffBase(char *diffBaseNum, int fromBase, char *fromBaseValues, int toBase, char *toBaseValues);
void printDiffBaseResults(char *diffBaseNum, int fromBase, int toBase, char *converted);

#endif