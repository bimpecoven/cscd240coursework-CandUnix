// Blake Impecoven -- CSCD240 -- Lab17 -- November, 2015.

// lab17.c -- Use with cscd240lab17.c, fileUtil(.h, .c), lab17.h

#include <stdlib.h>
#include "fileUtil.h"
#include "myUtils.h"
#include "lab17.h"

int menu()
{
	int choice;
	
	printf("1) Print the array sorted by symbol\n");
	printf("2) Print the array sorted by company name\n");
	printf("3) Print the array sorted by current price\n");
	printf("4) Quit\n");
	printf("Your choice: ");

	scanf("%d", &choice);
	
	while(choice < 1 || choice > 4)
	{
		printf("Error!\nInvalid selection, please pick a number in range.(1-4): ");
		scanf("%d", &choice);
	}//end while
	printf("\n");
	
	return choice;
}//end menu	

int fillArray(struct stock * array, FILE * fin)
{
	int size = 0, num;
	char read[MAX];
	
	fscanf(fin, "%d", &num);
	while(!feof(fin))
	{
		fscanf(fin, "%s\n", array[size].symbol); // read in symbol
		
		fgets(read, MAX, fin); // read in companyName
		strip(read);
		strncpy(array[size].companyName, read, strlen(read) + 1);
		
		fscanf(fin, "%lf", &array[size].currentPrice); //read in currentPrice
		size++;
	}//end while
	
	return size;
}//end fillArray

void printArray(struct stock * array, int total)
{
	int x;
	
	for(x = 0; x < total; x++)
	{
		printf("%s - %s - %.2f\n", array[x].companyName, array[x].symbol, array[x].currentPrice);
	}//end for
}//end printArray

int compareSymbols(const void * obj1, const void * obj2)
{
	struct stock * stock1 = (struct stock*)obj1;
	struct stock * stock2 = (struct stock*)obj2;

	return strcmp(stock1->symbol, stock2->symbol);	
}//end compareSymbols

int compareNames(const void * obj1, const void * obj2)
{
	struct stock * stock1 = (struct stock*)obj1;
	struct stock * stock2 = (struct stock*)obj2;
	
	return strcmp(stock1->companyName, stock2->companyName);	
}//end compareNames

int comparePrices(const void * obj1, const void * obj2)
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
