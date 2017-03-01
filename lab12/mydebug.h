#ifndef MYDEBUG_H
#define MYDEBUG_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 25

FILE * openFile();
int readTotal(FILE * fin);
int * fillArray(FILE * fin, int total);
void sort(int total, int array[]);
double calcMean(int total, int array[]);
double calcMedian(int array[], int total);
double calcStdDev(int array[], int total);
void displayResults(double mean, double median, double stdDev);

#endif
