// Blake Impecoven -- CSCD240 -- Lab 13 -- October, 2015.

//      --lab13.h--      //

#ifndef LAB13_H
#define LAB13_H

#include <stdio.h>
#include <stdlib.h>

//      --PROTOTYPES--      //
int readTotal(FILE * fin);
void fillSolutionsArray(FILE * fin, int * solutions);
void fillAndromida(FILE * fin, int andromida[10][10]);
void checkSolutionAndDisplay(int runs, int * solution, int andromida[10][10], FILE * fout);

#endif