#include "fileUtil.h"

FILE * openOutputFile_FileName(char *fileName)
{
	printf("openOutputFile_FileName\n");
	
	FILE * fout = NULL;
	
	fout = fopen(fileName, "w");
	
	printf("openOutputFile_FileName -- Exit.\n\n");
	return fout;
}//end openOutputFile_FileName
