#include "fileUtil.h"

FILE * openInputFile_Args(int argc, char *argv[])
{
	printf("openInputFile_Args\n");
	
	FILE * fin = NULL;
	
	if(argc < 2)
	{	
		printf("openInputFile_Args -- Exit.\n\n");
		return openInputFile_Prompt();
	}//end if
		
	else
	{
		fin = fopen(argv[1], "r");
		
		if(fin == NULL)
		{
			printf("openInputFile_Args -- Exit.(second if)\n");
			return openInputFile_Prompt();
		}//end if
		else
		{
			printf("openInputFile_Args -- Exit.(else)\n\n");
			return fin;
		}//end else
	}//end else
}//end openInputFile_Args
