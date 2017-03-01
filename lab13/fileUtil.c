// Blake Impecoven -- October, 2015.

//UPDATED: October 19th, 2015.

//-------------------------//
//      --File Util--      //
//-------------------------//
//Contains functions that  //
//read file names, open    //
//files(input and output)  //
//and has a count records  //
//function.                //
//-------------------------//

#include "fileUtil.h"

int countRecords(FILE * fin, int linesPerRecord)
{
	printf("countRecords\n");
	
	if(fin == NULL)
	{
		printf("Error!\nFile not found.");
		exit(-99);
	}//end if
	
	int count, num;
	
	while(!feof(fin))
	{
		fscanf(fin, "%d", &num);
		count++;
	}//end while
	
	if(count == 0)
		printf("Empty file!");	
		
	count = count / linesPerRecord;
	
	printf("Records: %d\n", count);
	printf("countRecords -- Exit.\n\n");
	
	return count;
}//end countRecords



//--Open File Functions(input/output)
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

FILE * openOutputFile_FileName(char *fileName)
{
	printf("openOutputFile_FileName\n");
	
	FILE * fout = NULL;
	
	fout = fopen(fileName, "w");
	
	printf("openOutputFile_FileName -- Exit.\n\n");
	return fout;
}//end openOutputFile_FileName



//--Display functions - Print or writing to output file
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



void readFileName(char *fileName)
{
	printf("readFileName\n");
	
	printf("Please enter a file name: ");
	scanf("%s", fileName);
	
	printf("readFileName -- Exit.\n\n");
}//end readFileName

void readFileName_type(char * fileName, char * fileType)
{
	printf("Please enter the %s file name: ", fileType);
	scanf("%s", fileName);
}//end readFileName_type



//--Prompt functions - prompt the user
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

