// Blake Impecoven -- CSCD240 -- Lab 21 -- November, 2015.

#include "lab21.h"

int menu()
{
	int choice;
	
	printf("     -- Menu --     \n");
	printf("1. Convert from Decimal to Binary\n");
	printf("2. Convert from Decimal to Octal\n");
	printf("3. Convert from Decimal to Hexadecimal\n");
	printf("4. Convert from any base to any other base\n");
	printf("5. Quit\n");
	
	printf("Your choice: ");
	scanf("%d", &choice);
	
	while(choice < 1 || choice > 5)
	{
		printf("Error!\nInvalid menu choice, value not in range. (1-5)\n");
		printf("Your choice: ");
		scanf("%d", &choice);
	}//end while
	
	return choice;
}//end menu

int readNumber(int baseVal)
{
	int num;
	
	printf("Enter a base %d value: ", baseVal);
	scanf("%d", &num);
	
	return num;
}//end readNumber

char * convert(int num, int fromBase, char *fromVals, int toBase, char *toVals)
{
	printf("Converting...\nValue: %d, from base %d to base %d.\n", num, fromBase, toBase);
	int x = 0;
	char * temp = (char *)calloc(1, sizeof(char));
	
	while(num > 0)
	{
		temp[x] = toVals[num % toBase];
		
		num = num / toBase;
		x++;
	}//end while
	
	strip(temp);
	char *finalConversion = (char *)calloc(strlen(temp + 1), sizeof(char));
	int end = strlen(temp) - 1;
	
	for(x = 0; x < strlen(temp); x++)
	{
		finalConversion[x] = temp[end];
		end--;
	}//end for
	
	free(temp);
	
	return finalConversion;	
}//end convert

void printResults(int originalValue, int fromBase, int toBase, char *converted)
{
	printf("The base %d value: %d converted to base %d is: %s\n", fromBase, originalValue, toBase, converted);
}//end printResults

int readBase(char *prompt)
{
	int base;
	
	printf("Enter a base to convert %s: ", prompt);
	scanf("%d", &base);
	
	while(base < 1 || base > 36)
	{
		printf("Error!\nBase value is out of range...(1-36)");
		printf("Enter a base to convert %s: ", prompt);
		scanf("%d", &base);
	}//end while
	
	return base;
}//end readBase

char * readBaseValues(char *prompt, int baseVal)
{
	printf("Create values for your base %d conversions...\n", baseVal);
	
	int x;
	char inputString[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};
	char * customBaseValues = (char *)calloc(1, sizeof(char));
	
	for(x = 0; x < baseVal; x++)
	{
		customBaseValues[x] = inputString[x];
	}//end for
	
	printf("Your base conversion list: %s\n", customBaseValues);
	
	return customBaseValues;
}//end readBaseValues

char * readDiffBaseNumber(int baseVal)
{
	char temp[MAX];
	
	printf("Enter a base %d number to convert from: ", baseVal);
	scanf("%s", temp);
	strip(temp);
	
	char * number = (char *)calloc(1, sizeof(char));
	strcpy(number, temp);
	
	return number;
}//end readDiffBaseNumber

char * convertDiffBase(char *diffBaseNum, int fromBase, char *fromBaseValues, int toBase, char *toBaseValues)
{
	int x, index = 0;
	char * converted = (char *)calloc(1, sizeof(char));
	
	for(x = 0; x < strlen(diffBaseNum); x++)
	{
		do{
			index++;
		}while(diffBaseNum[x] != fromBaseValues[index]);
		
		converted[x] = toBaseValues[index % toBase];
	}//end for
	
	return converted;
}//end convertDiffBase

void printDiffBaseResults(char *diffBaseNum, int fromBase, int toBase, char *converted)
{
	printf("The base %d value: %s converted to base %d is: %s\n", fromBase, diffBaseNum, toBase, converted);
}//end printDiffBaseResults