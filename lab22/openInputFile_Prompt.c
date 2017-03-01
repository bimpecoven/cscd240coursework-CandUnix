#include "fileUtil.h"

FILE * openInputFile_Prompt()
{
	printf("openInputFile_Prompt\n");

	char fileName[MAX];
	FILE * fin = NULL;
	
	printf("Please enter the name of the file you desire to open: ");
	scanf("%s", fileName);
	fin = fopen(fileName, "r");
	
	if(fin == NULL) //recursive stopping case.
	{
		printf("Error!\nFile does not exist.");
		fin = openInputFile_Prompt();
	}//end if	
	
	printf("openInputFile_Prompt -- Exit.\n\n");
	
	return fin;
		
}//end openInputFile_Prompt
