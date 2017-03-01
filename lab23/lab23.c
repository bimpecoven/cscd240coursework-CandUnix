// Blake Impecoven - CSCD240 - December, 2015.

#include "lab23.h"

int menu()
{
	int choice;
	
	printf("1) Enter a new string\n");
	printf("2) Parse the string\n");
	printf("3) Read existing output file\n");
	printf("4) Quit\n");
	printf("Your choice: ");
	scanf("%d", &choice);
	
	while(choice < 1 || choice > 4)
	{
		printf("Error!\nChoice outside of range(1-4)\nYour choice: ");
		scanf("%d", &choice);
	}//end while

	return choice;
}//end menu

char * readString(char * theString)
{
	printf("Enter a string: ");
	fflush(stdin);
	fgets(theString, 650, stdin);
	strip(theString);
	
	while(strlen(theString) < 1)
	{
		printf("Enter a string: ");
		fgets(theString, 650, stdin);
		strip(theString);
	}//end while
	
	char * returnString = (char *)calloc(strlen(theString) + 1, sizeof(char));
	strcpy(returnString, theString);	

	return returnString;

}//end readString

char ** parseString(char * theString, int * total)
{
	char * temp = (char *)calloc(strlen(theString) + 1, sizeof(char));
	strcpy(temp, theString);
	char * temp2 = NULL;
	char * bkpt;
	
	int tokens = 0;
	temp2 = strtok_r(temp, " ,.", &bkpt);
	
	while(temp2 != NULL)
	{
		tokens++;
		temp2 = strtok_r(NULL, " ,.", &bkpt);
	}//end while
	
	char ** parsed = (char **)calloc(tokens, sizeof(char *));
	strcpy(temp, theString);
	
	int x = 0;
	
	temp2 = strtok_r(temp, " ,.", &bkpt);
	strip(temp2);
	parsed[x] = (char *)calloc(strlen(temp2) + 1, sizeof(char));
	strcpy(parsed[x], temp2);
	for(x = 1; x < tokens; x++)
	{
		temp2 = strtok_r(NULL, " ,.", &bkpt);
		strip(temp2);
		parsed[x] = (char *)calloc(strlen(temp2) + 1, sizeof(char));
		strcpy(parsed[x], temp2);
	}//end for
	
	*total = tokens;
	
	cleanUp(temp);
	temp = NULL;
	
	return parsed;
}//end parseString

void writeTheString(char ** parsedString, int total)
{
	int res, fd, x, size;
	
	fd = open("out.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);
	
	for(x = 0; x < total; x++)
	{
		size = strlen(*(parsedString + x));
		res = write(fd, &size, sizeof(int));
		res = write(fd, *(parsedString + x), size);
	}//end for
	
	close(fd);
	
}//end writeTheString

void readTheString()
{
	char temp[650];
	char output[650];
	memset(output, 0, sizeof(output));
	int res, fd, length;
	
	printf("Enter a string: ");
	fflush(stdout);
	//write(1, "Enter a string", sizeof(char*));
	res = read(0, temp, sizeof(char*));
	strip(temp);
	
	fd = open(temp, O_RDONLY, 0777);
	
	if(fd == -1) // opening the file has failed.
	{
		menu();
	}//end if
	
	else // opening the file was a success.
	{
		res = read(fd, &length, sizeof(int));
		res = read(fd, output, length);
		while(res != 0)
		{
			printf("%s - %d\n", output, length);
			memset(output, 0, sizeof(output));
			res = read(fd, &length, sizeof(int));
			res = read(fd, output, length);
		}//end while
		
		close(fd);
	}//end else
	
}//end readTheString
