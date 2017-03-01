#include "fileUtil.h"

int countRecords(FILE * fin, int linesPerRecord)
{
	printf("countRecords\n");
	
	if(fin == NULL)
	{
		printf("Error!\nFile not found.");
		exit(-99);
	}//end if
	
	int count = 0;
	char temp[MAX];
	
	fscanf(fin, "%s", temp);
	while(!feof(fin))
	{
		fscanf(fin, "%s", temp);
		count++;
	}//end while
	
	if(count == 0)
		printf("Empty file!");	
		
	count = count / linesPerRecord;
	
	//printf("Records: %d\n", count);
	printf("countRecords -- Exit.\n\n");
	rewind(fin);
	return count;
}//end countRecords
