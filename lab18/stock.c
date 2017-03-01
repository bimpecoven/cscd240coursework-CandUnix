// Blake Impecoven - CSCD240 - Lab18 - November, 2015.
// Stock.c

// --Constructor

#include <stdlib.h>
#include <string.h>

#include "stock.h"
#include "myUtils.h"

Stock * buildStock(char * symbol, char * companyName, double currentPrice)
{
	struct stock * ret;
	
	strip(symbol);
	ret->symbol = (char *)calloc(strlen(symbol) + 1, sizeof(char));
	strcpy(ret->symbol, symbol);
	
	
	strip(companyName);
	ret->companyName = (char *)calloc(strlen(companyName) + 1, sizeof(char));
	strcpy(ret->companyName, companyName);
	
	ret->currentPrice = currentPrice;
	
	return ret;
}//end buildStock