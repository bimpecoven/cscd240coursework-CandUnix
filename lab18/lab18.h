#ifndef LAB18_H
#define LAB18_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"

void fillList(LinkedList * myList, FILE * fin);
void sort(LinkedList * myList, int (*compare)(const void *one, const void *two) );
int symbolSort(const void *one, const void *two);
int companySort(const void *one, const void *two);
int priceSort(const void *one, const void *two);



#endif 
