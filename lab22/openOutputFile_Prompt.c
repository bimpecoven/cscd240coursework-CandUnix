#include "fileUtil.h"

FILE *  openOutputFile_Prompt()
{
	printf("openOutputFile_Prompt\n");
	
	char fileName[MAX];
	FILE * fout = NULL;

	printf("Please enter the file name you would like to write to: ");
	scanf("%s", fileName);
	
	fout = fopen(fileName, "w");
	
	printf("openOutputFile_Prompt -- Exit.\n\n");
	
	return fout;
}//end openOutputFile_Prompt
