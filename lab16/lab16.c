// Blake Impecoven -- CSCD240 -- Lab16 -- November, 2015.

// lab16.c -- Use with cscd240lab16.c, fileUtil(.h, .c), lab16.h

#include <stdlib.h>
#include "fileUtil.h"
#include "myUtils.h"
#include "lab16.h"


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

int fillArray(struct Stock * array, FILE * fin)
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

void printArray(struct Stock * array, int total)
{
	int x;
	
	for(x = 0; x < total; x++)
	{
		printf("%s - %s - %.2f\n", array[x].companyName, array[x].symbol, array[x].currentPrice);
	}//end for
}//end printArray

void symbolSort(struct Stock * array, int total)
{
	int start, search, min;
	struct Stock temp;
	
	for(start = 0; start < total; start++)
	{
		min = start;

		for(search = start + 1; search < total; search++)
		{
			if(strcmp(array[search].symbol, array[min].symbol) < 0)
				min = search;
		}//end for(search

		temp = array[min];
		array[min] = array[start];
		array[start] = temp;
	}//end for(start

}//end symbolSort

void companySort(struct Stock * array, int total)
{
	int start, search, min;
	struct Stock temp;
	
	for(start = 0; start < total; start++)
	{
		min = start;

		for(search = start + 1; search < total; search++)
		{
			if(strcmp(array[search].companyName, array[min].companyName) < 0)
				min = search;
		}//end for(search

		temp = array[min];
		array[min] = array[start];
		array[start] = temp;
	}//end for(start

}//end nameSort

void priceSort(int total, struct Stock * array)
{
	int start, search, min;
	struct Stock temp;

	for(start = 0; start < total; start++)
	{
		min = start;

		for(search = start + 1; search < total; search++)
		{
			if(array[search].currentPrice < array[min].currentPrice)
				min = search;
		}//end for(search

		temp = array[min];
		array[min] = array[start];
		array[start] = temp;
	}//end for(start

}//end priceSort
