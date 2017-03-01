// Blake Impecoven - CSCD240 - Lab18 - November, 2015.
// lab18.c

#include <stdlib.h>

#include "lab18.h"
#include "fileUtil.h"
#include "myUtils.h"
#include "linkedList.h"
#include "stock.h"

void fillList(LinkedList * myList, FILE * fin)
{
	if(fin == NULL)
		exit(-99);
		
	int tempNum;
	Node * cur = myList->head;
	char tempSymbol[MAX];
	char tempName[MAX];
	
	fscanf(fin, "%d", &tempNum);
	while(!feof(fin))
	{
		fscanf(fin, "%s\n", tempSymbol); // read in symbol
		
		fgets(tempName, MAX, fin); // read in companyName
		strip(tempName);

		fscanf(fin, "%d", &tempNum); // read in currentPrice
		
		struct stock *addStock = buildStock(tempSymbol, tempName, tempNum); // build stock
		
		cur->data = addStock;
		cur = cur->next;
	}//end while -- not at end of file
}//end fillList

void sort(LinkedList * myList, int (*compare)(const void *one, const void *two))
{
	struct node *start, *search, *min;
	struct stock *temp = NULL;
	
	for(start = myList->head; start != NULL; start = start->next)
	{
		min = start;

		for(search = start->next; search != NULL; search = search->next)
		{
			if(compare(search->data, min->data) < 0)
				min = search;
		}//end for(search
		
		temp = min->data;
		min->data = start->data;
		start->data = temp;
	}//end for(start
}//end sort

int symbolSort(const void * obj1, const void * obj2)
{
	struct stock * stock1 = (struct stock*)obj1;
	struct stock * stock2 = (struct stock*)obj2;

	return strcmp(stock1->symbol, stock2->symbol);	
}//end compareSymbols

int companySort(const void * obj1, const void * obj2)
{
	struct stock * stock1 = (struct stock*)obj1;
	struct stock * stock2 = (struct stock*)obj2;
	
	return strcmp(stock1->companyName, stock2->companyName);	
}//end compareNames

int priceSort(const void * obj1, const void * obj2)
{
	int ret;
	
	struct stock * stock1 = (struct stock*)obj1;
	struct stock * stock2 = (struct stock*)obj2;
	
	if(stock1->currentPrice < stock2->currentPrice)
		ret = -1;
	else
		ret = 1;
	
	return ret;
}//end comparePrices