// Blake Impecoven - CSCD240 - Lab19 - November, 2015.

#include "words.h"

void printWord(void * passedIn)
{
	struct words * theWord = (struct words*)passedIn;
	int length = strlen(theWord->word);
	printf("%s - %d, ", theWord->word, length);
}//end printWord

void * buildWord(FILE * fin)
{
	if(fin == NULL)
	{
		printf("Error!\nFile pointer is NULL.\n");
		exit(-99);
	}//end if

	Words * newWord = (Words *)calloc(1, sizeof(Words));
	char temp[MAX];	

	fscanf(fin, "%s", temp);
	strip(temp);
	newWord->word = (char *)calloc(strlen(temp) + 1, sizeof(char));
	strcpy(newWord->word, temp);

	int length = strlen(temp);	

	newWord->length = length;
	
	return (void *)newWord;
}//end buildWord

void * buildWord_Prompt(FILE * in)
{
	if(in == NULL)
	{
		printf("Error!\nFile pointer is NULL.\n");
		exit(-99);
	}//end if

	Words * newWord = (Words *)calloc(1, sizeof(Words));
	char temp[MAX];

	printf("Enter a word: ");
	fscanf(in, "%s", temp);
	strip(temp);
	newWord->word = (char *)calloc(strlen(temp) + 1, sizeof(char));
	strcpy(newWord->word, temp);
	
	newWord->length = strlen(temp);
	
	return (void *)newWord;
}//end buildWord_Prompt

int compareTwoWords(const void * obj1, const void * obj2)
{
	Words * firstWord = (Words*)obj1;
	Words * secondWord = (Words*)obj2;
	
	return strcmp(firstWord->word, secondWord->word);
}//end compareTwoWords

void cleanWord(void * passedIn)
{
	Words * theWord = (Words*)passedIn;
	
	free(theWord->word);
	theWord->length = 0;
	free(theWord);
}//end cleanWord
