// Blake Impecoven - CSCD240 - December, 2015.

#ifndef LAB23_H
#define LAB23_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "myUtils.h"

// Prototypes //
int menu();
char * readString(char * theString);
char ** parseString(char * theString, int * total);
void writeTheString(char ** parsedString, int total);
void readTheString();

#endif