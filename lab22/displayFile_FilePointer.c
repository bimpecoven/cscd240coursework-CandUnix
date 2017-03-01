#include "fileUtil.h"

void displayFile_FilePointer(FILE * fin)
{
	printf("displayFile_FilePointer\n");
	int num;
	
	printf("Printing input file contents... unknown number of lines...\n");
	
	while(!feof(fin))
	{
		fscanf(fin, "%d", &num);
		printf("%d\n", num);
	}//end while	
	
	printf("displayFile_FilePointer -- Exit.\n\n");
}//end displayFile_FilePointer
