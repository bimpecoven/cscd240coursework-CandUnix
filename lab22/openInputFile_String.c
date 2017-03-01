#include "fileUtil.h"

FILE * openInputFile_String(char *fileName)
{
	printf("openInputFile_String\n");
	FILE * fin = NULL;
	
	fin = fopen(fileName, "r");
	
	if(fin == NULL)
	{
		printf("openInputFile_String -- Exit.(if)\n\n");
		return openInputFile_Prompt();
	}//end if
	else
	{
		printf("openInputFile_String -- Exit.(else)\n\n");
		return fin;
	}//end else
	
}//end openInputFile_String
