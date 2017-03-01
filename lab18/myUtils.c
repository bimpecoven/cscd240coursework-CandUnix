#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myUtils.h"

void strip(char *str)
{
	int x = 0;
	
	while(str[x] != '\0')
	{
		if(str[x] == '\r')
			str[x] = '\0';
		else if(str[x] == '\n')
			str[x] = '\0';
		x++;
	}//end while
}//end strip

int menu()
{
	int choice;
	
	printf("1) symbolsort\n");
	printf("2) namesort\n");
	printf("3) pricesort\n");
	printf("4) Exit\n");
	printf("Your choice: ");
	scanf("%d", &choice);
	
	while(choice < 1 || choice > 4)
	{
		printf("Error!\nInvalid menu choice, not in range(1-4)\nYour choice: ");
		scanf("%d", &choice);
	}//end while
	
	return choice;
}//end menu