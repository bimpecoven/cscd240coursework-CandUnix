// Blake Impecoven -- CSCD240 -- Lab 15 -- October, 2015.

#include "lab15.h"
#include "fileUtil.h"
#include "myUtils.h"

int readTotal(FILE * fin)
{
	if(fin == NULL) // Pre condition checking
	{
		printf("Error!\nFile is NULL.\n");
		exit(-99);
	}//end if
	
	int total;
	
	fscanf(fin, "%d", &total);
	
	return total;
}//end readTotal

char ** createAndFillArray(FILE * fin, int total)
{
	if(fin == NULL) // Pre condition checking
	{
		printf("Error!\nFile is NULL.\n");
		exit(-99);
	}//end if
	
	int x;
	char temp[MAX];
	char ** array = (char**)calloc(total, sizeof(char*));
	
	for(x = 0; x < total; x++)
	{
		fscanf(fin, "%s", temp);
		strip(temp);
		*(array + x) = (char*)calloc(strlen(temp) + 1, sizeof(char));
		strcpy(*(array + x), temp);
		//*(array + x) = temp;
	}//end for
	
	return array;
}//end createAndFillArray

int menu()
{
	int choice;
	
	printf("\n\n -- Menu -- \n");
	printf("1) Generate a sentence\n");
	printf("2) Display all words\n");
	printf("3) Add a word\n");
	printf("4) Display all words sorted\n");
	printf("5) Exit the program\n");
	printf("Make a selection: ");
	scanf("%d", &choice);
	
	while(choice < 1 || choice > 5)
	{
		printf("Error!\nMenu choice not in range. (1-5)\n");
		scanf("%d", &choice);
	}//end while
	
	printf("\n");
	return choice;
}//end menu

char ** generateSentence(int articleTotal, char **articles, int nounTotal, char **nouns, int verbTotal, char **verbs, int prepTotal, char **preps)
{
	srand(time(NULL));
	
	// assign random numbers for each type. the values will target an index, that word will be chosen.
	int artiRand = (rand() % articleTotal), nounRand = (rand() % nounTotal), verbRand = (rand() % verbTotal), prepRand = (rand() % prepTotal);
	char **randomSentence = (char**)calloc(4, sizeof(char*));
	
	// nouns
	*(randomSentence) = (char*)calloc(strlen(*(nouns + nounRand)) + 1, sizeof(char));
	strcpy(*(randomSentence), *(nouns + nounRand));
	
	// verbs
	*(randomSentence + 1) = (char*)calloc(strlen(*(verbs + verbRand)) + 1, sizeof(char));
	strcpy(*(randomSentence + 1), *(verbs + verbRand));
	
	// preps
	*(randomSentence + 2) = (char*)calloc(strlen(*(preps + prepRand)) + 1, sizeof(char));
	strcpy(*(randomSentence + 2), *(preps + prepRand));

	// articles
	*(randomSentence + 3) = (char*)calloc(strlen(*(articles + artiRand)) + 1, sizeof(char));
	strcpy(*(randomSentence + 3), *(articles + artiRand));

	// randomize noun again
	nounRand = rand() % nounTotal;
	// second noun
	*(randomSentence + 4) = (char*)calloc(strlen(*(nouns + nounRand)) + 1, sizeof(char));
	strcpy(*(randomSentence + 4), *(nouns + nounRand));
	
	return randomSentence;
}//end generateSentence

void display(char **array, int total)
{
	int x;
	
	for(x = 0; x < total; x++)
	{
		printf("%s ", *(array + x));
	}//end for
}//end display

void displayAllWords(int articleTotal, char **articles, int nounTotal, char **nouns, int verbTotal, char **verbs, int prepTotal, char **preps)
{
	// function lives in myUtils.c
	printf("\nArticles:\n");
	displayTwoD(articleTotal, articles);
	printf("\nNouns:\n");
	displayTwoD(nounTotal, nouns);
	printf("\nVerbs:\n");
	displayTwoD(verbTotal, verbs);
	printf("\nPrepositions:\n");
	displayTwoD(prepTotal, preps);
}//end displayAllWords

int readType()
{
	int type;
	
	printf("Add a word to: \n");
	printf("1) Articles\n");
	printf("2) Nouns\n");
	printf("3) Verbs\n");
	printf("4) Prepositions\n");
	
	scanf("%d", &type);
	
	while(type < 1 || type > 4)
	{
		printf("Error!\nChoice not in range. (1-4)\n");
		scanf("%d", &type);
	}//end while
	
	return type;
}//end readType

int addWord(char ***array, int total)
{
	char temp[MAX];
	if(fgets(temp, MAX, stdin) == NULL)
		printf("ERROR");
	
	printf("What word would you like to add: \n");
	fgets(temp, MAX, stdin);
	strip(temp);

	char * word = (char *)calloc(strlen(temp) + 1, sizeof(char *));
	strcpy(word, temp);
	
	char ** newArray = (char **)calloc(total + 1, sizeof(char *));
	int x;
	
	for(x = 0; x < total; x++)
	{
		*(newArray + x) = (char *)calloc(strlen(*(*(array) + x)) + 1, sizeof(char));
		strcpy(*(newArray + x), *(*(array) + x));
	}//end for
	
	total += 1;

	*(newArray + x) = (char *)calloc(strlen(word) + 1, sizeof(char));
	strcpy(*(newArray + total - 1), word);

	*array = newArray;
	cleanUp(word);
	word = NULL;

	//cleanUp(temp);
		
	clean(total - 1, newArray);
	newArray = NULL;
	
	return total;
}//end addWord 

char ** allWordsSorted(int articleTotal, char **articles, int nounTotal, char **nouns, int verbTotal, char **verbs, int prepTotal, char **preps)
{
	int total = articleTotal + nounTotal + verbTotal + prepTotal;
	int count, x, runningTotal;
	char ** sorted = (char **)calloc(total, sizeof(char *));
	
	for(count = 0; count < articleTotal; count++)
	{	
		*(sorted + count) = (char *)calloc(sizeof(*(articles + count) + 1), sizeof(char));
		strcpy(*(sorted + count), *(articles + count));
	}//end for articles
	
	runningTotal = articleTotal + nounTotal;

	x = 0;
	for(count = count; count < runningTotal; count++)
	{
		*(sorted + count) = (char *)calloc(sizeof(*(nouns + x) + 1), sizeof(char));
		strcpy(*(sorted + count), *(nouns + x));
		x++;
	}//end for nouns

	runningTotal += verbTotal;
	
	x = 0;
	for(count = count; count < runningTotal; count++)
	{
		*(sorted + count) = (char *)calloc(sizeof(*(verbs + x) + 1), sizeof(char));
		strcpy(*(sorted + count), *(verbs + x));
		x++;
	}// end for verbs

	runningTotal += prepTotal;
	
	x = 0;
	for(count = count; count < runningTotal; count++)
	{
		*(sorted + count) = (char *)calloc(sizeof(*(preps + x) + 1), sizeof(char));
		strcpy(*(sorted + count), *(preps + x));
		x++;
	}// end for preps

	sortChar(runningTotal, sorted);

	return sorted;
}//end allWordsSorted

