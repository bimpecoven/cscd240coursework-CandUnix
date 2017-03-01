// Blake Impecoven -- CSCD240 -- Lab 14 -- October, 2015.

// lab14.h - use with lab14.c

#ifndef LAB14_H
#define LAB14_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

// Prototypes // 
char * readString();
char ** makeargs(char *str, int *argc);

void printargs(int argc, char **argv);

char ** clean(int argc, char **argv);
char * cleanUp(char *str);
void strip(char *str);

#endif