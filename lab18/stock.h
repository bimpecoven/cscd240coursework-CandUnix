#ifndef STOCK_H
#define STOCK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myUtils.h"

struct stock
{
    char * symbol;
    char * companyName;
    double currentPrice;
};

typedef struct stock Stock;

Stock * buildStock(char * sym, char * name, double cp);

#endif 
