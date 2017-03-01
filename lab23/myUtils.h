// Blake Impecoven -- myUtils.c -- October, 2015.

// Packed with useful functions such
// as: sorts, cleans, strips, etc.

#ifndef MYUTILS_H
#define MYUTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// --Prototypes

void strip(char *str);
void displayTwoD(int total, char ** array);
void sortChar(int size, char ** array);

char * cleanUp(char *str);
char * copy(char * source);

char ** clean(int total, char **array);

#endif
