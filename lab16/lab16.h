// Blake Impecoven -- CSCD240 -- Lab16 -- November, 2015.

// lab16.h -- Use with cscd240lab16.c, fileUtil(.h, .c), lab16.c

#ifndef LAB16_H
#define LAB16_H

#include <stdlib.h>
#include "fileUtil.h"

struct Stock
{
	char symbol[10];
	char companyName[100];
	double currentPrice;
};//end struct

// -- Prototypes

int menu();
int fillArray(struct Stock * array, FILE * fin);
void printArray(struct Stock * array, int total);
void symbolSort(struct Stock * array, int total);
void companySort(struct Stock * array, int total);
void priceSort(int total, struct Stock * array);

#endif