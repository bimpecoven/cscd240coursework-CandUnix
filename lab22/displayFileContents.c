#include "fileUtil.h"

void displayFileContents(int count, FILE * fin)
{
	printf("displayFileContents\n");
	int x, num;
	
	printf("Printing input file contents... %d lines...\n", count - 1);
	
	for(x = 0; x < count - 1; x++)
	{
		fscanf(fin, "%d", &num);
		printf("%d\n", num);
	}//end for
	
	printf("displayFileContents -- Exit.\n\n");
}//end displayFileContents
