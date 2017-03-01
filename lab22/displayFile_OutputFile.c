#include "fileUtil.h"

void displayFile_OutputFile(FILE * fin, FILE * fout)
{
	printf("displayFile_OutputFile\n");
	int num;
		
	printf("Writing to file...\n");	
	
	while(!feof(fin))
	{
		fscanf(fin, "%d", &num);
		printf("%d\n", num);
		fprintf(fout, "%d\n", num);
	}//end while
	
	printf("displayFile_OutputFile -- Exit.\n\n");
}//end displayFile_OutputFile
