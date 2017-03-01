// Blake Impecoven -- myUtils.c -- October, 2015.

// Packed with useful functions such
// as: sorts, cleans, strips, etc.

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

char ** clean(int total, char **array)
{
	int x;
	
	for(x = 0; x < total; x++)
	{
		free(*(array + x));
		//*(array + x) = NULL;
	}//end for rows

	free(array);

	array = NULL;
	
	return array;
}//end clean

char * cleanUp(char *str)
{
	free(str);
	
	return str;
}//end cleanUp

char * copy(char * source)
{
	
	return NULL;
}//end copy

void displayTwoD(int total, char ** array)
{
	int x;
	
	for(x = 0; x < total; x++)
	{
		printf("%s\n", *(array + x));
	}//end for
}//end displayTwoD


void sortChar(int total, char ** array)
{
	int start, search, min;
	char *temp = NULL;
	
	for(start = 0; start < total - 1; start++)
	{
		min = start;

		for(search = start + 1; search < total - 1; search++)
		{
			if(strcmp(*(array + search), *(array + min)) < 0)
				min = search;
/*			
			if(array[search] < array[min])
				min = search;
*/
		}//end for(search

		temp = (char *)calloc(strlen(*(array + min)) + 1, sizeof(char));
		strcpy(temp, *(array + min));
		strcpy(*(array + min), *(array + start));
		strcpy(*(array + start), temp);
	}//end for(start
	cleanUp(temp);
	temp = NULL;
}//end sortChar

