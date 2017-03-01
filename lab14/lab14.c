#include "lab14.h"

char * readString()
{
  /* You may not change this code */
  char s[MAX]; // MAX is set to 100
  printf("Enter a string: ");
  fgets(s, MAX, stdin);
  strip(s);

  /* You will need to add your own code below
     And change the return value */
	char * str = (char *)calloc(strlen(s) + 1, sizeof(char));
	
	strcpy(str, s);
	
	return str;
}// end readString

char ** makeargs(char *str, int *argc)
{
	// 1. Make copy of str, will be modified by strtok
	char * temp = NULL;//(char *)calloc(strlen(str) + 1, sizeof(char));
	char * temp2 = (char *)calloc(strlen(str) + 1, sizeof(char));
	strcpy(temp2, str);

	// 2. count tokens -- strtok
	int tokens = 0;
	
	temp = strtok(temp2, " ");
	
	while(temp != NULL)
	{
		tokens += 1;
		//printf("%s\n", temp);
		temp = strtok(NULL, " ");
	}//end while
	
	// 3. make the number of rows of char*
	char **argv = (char **)calloc(tokens, sizeof(char *));
	
	strcpy(temp2, str); // refill temp2
	// 4. pull each token, dynamically allocate the memory, then you strcpy dynamically allocated memory
	int x = 0;
	
	temp = strtok(temp2, " ");
	strip(temp);
	argv[x] = (char *)calloc(strlen(temp) + 1, sizeof(char));
	strcpy(argv[x], temp);
	for(x = 1; x < tokens; x++)
	{
		temp = strtok(NULL, " ");
		strip(temp);
		argv[x] = (char *)calloc(strlen(temp) + 1, sizeof(char));
		strcpy(argv[x], temp);
	}//end for
	
	// 5. update length (argc) -- if you made str dynamically, remember to free memory
	*argc = tokens;

	cleanUp(temp2);
	temp2 = NULL;
	
	// 6. return argv
	return argv;
	
}//end makeargs

void printargs(int argc, char **argv)
{
	int x;
		
	for(x = 0; x < argc; x++)
	{
		printf("%s\n", *(argv + x));
	}//end for
}//end printargs

char ** clean(int argc, char **argv)
{
	int rows;
	
	for(rows = 0; rows < argc; rows++)
	{
		free(*(argv + rows));
	}//end for rows

	free(argv);
	argv = NULL;
	return argv;
}//end clean

char * cleanUp(char *str)
{
	free(str);
	
	return str;
}//end cleanUp

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
