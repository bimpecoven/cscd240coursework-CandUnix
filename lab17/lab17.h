// Blake Impecoven -- CSCD240 -- Lab17 -- November, 2015.

// lab17.h -- Use with cscd240lab17.c, fileUtil(.h, .c), lab17.c

#ifndef LAB17_H
#define LAB17_H

#include <stdlib.h>
#include "fileUtil.h"

struct stock
{
	char symbol[10];
	char companyName[100];
	double currentPrice;
};//end struct

typedef struct stock stock;

// -- Prototypes

int menu();
int fillArray(struct stock * array, FILE * fin);
int compareSymbols(const void * obj1, const void * obj2);
int compareNames(const void * obj1, const void * obj2);
int comparePrices(const void * obj1, const void * obj2);

void printArray(struct stock * array, int total);

#endif