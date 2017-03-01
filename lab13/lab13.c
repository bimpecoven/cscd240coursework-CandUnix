// Blake Impecoven -- CSCD240 -- Lab 13 -- October, 2015.

// Lab 13
// Use with lab13.h and fileUtil's

#include "lab13.h"
#include "fileUtil.h"

int readTotal(FILE * fin)
{
	int total;
	
	fscanf(fin, "%d", &total);
	
	return total;
}//end readTotal

void fillSolutionsArray(FILE * fin, int * solutions)
{
	//Precondition
	if(fin == NULL)
		exit(-99);
		
	int x, length;
	length = 16;
	
	for(x = 0; x < length; x++)
		fscanf(fin, "%d", &solutions[x]);
		
}//end fillSolutionsArray

/* -- Will work if i can copy point andromida to new bordered 2D --
void fillAndromida(FILE * fin, int ** andromida)
{
	//Copy of the andromida but with //
	//borders for easier calculations//
	//and less if statements.        //
	int bordered[12][12];
	int rows, cols;
	
	for(rows = 0; rows < 11; rows++)
	{
		for(cols = 0; cols < 11; cols++)
		{
			if(rows == 0 || cols == 0) //top and left border
				bordered[rows][cols] = 0;
			else if(rows == 11 || cols == 0)
				bordered[rows][cols] = 0;
			else
				fscanf(fin, "%d", bordered[rows][cols]);
		}//end for cols
	}//end for rows
	
	//we need to repoint andromida to//
	//our new bordered 2D array.     //
	andromida = bordered;
	for(cols = 0; cols < 11; cols++)
		*andromida[cols] = *bordered[cols]
}//end fillAndromida
*/

void fillAndromida(FILE * fin, int andromida[10][10])
{
	int rows, cols;
	
	for(rows = 0; rows < 10; rows++)
	{
		for(cols = 0; cols < 10; cols++)
		{
			fscanf(fin, "%d", &andromida[rows][cols]);
		}//end for cols
	}//end for rows
}//end fillAndromida


/* -- First attempt at the function. Seg faults everywhere. --
void checkSolutionAndDisplay(int runs, int * solution, int twoD[10][10], FILE * fout)
{
	int cols, rows, index;
	
	for(rows = 0; rows < 9; rows++)
	{
		for(cols = 0; cols < 9; cols++)
		{
			if(rows >= 1 && cols >= 1 && rows <= 8 && cols <= 8) //no border issues, calc normally
			{
				index = twoD[rows][cols] + twoD[rows - 1][cols] + twoD[rows + 1][cols] + twoD[rows][cols - 1] + twoD[rows][cols + 1];
			}//end if
			 
			else if(rows == 0) // along left side
			{
				if(cols == 0) // top left corner
				{
					index = twoD[rows][cols] + twoD[rows + 1][cols] + twoD[rows][cols + 1];
				}//end if
				
				else
				{
					index = twoD[rows][cols] + twoD[rows + 1][cols] + twoD[rows][cols + 1] + twoD[rows][cols - 1];
				}//end else
			}//end if rows == 0
			
			if(cols == 0) // along top side
			{
				if(rows == 0) // top left corner
				{
					index = twoD[rows][cols] + twoD[rows + 1][cols] + twoD[rows][cols + 1];
				}//end if
				
				else
				{
					index = twoD[rows][cols] + twoD[rows + 1][cols] + twoD[rows][cols + 1] + twoD[rows - 1][cols];
				}//end else
			}//end if cols == 0
			
			else if(rows == 9) // along bottom side
			{
				if(cols == 9) // bottom right corner
				{
					index = twoD[rows][cols] + twoD[rows - 1][cols] + twoD[rows][cols - 1];
				}//end if
				
				else
				{
					index = twoD[rows][cols] + twoD[rows - 1][cols] + twoD[rows][cols - 1] + twoD[rows][cols + 1];
				}//end else
			}//end if rows == 9
			
			else if(cols == 9) // along right side
			{
				if(rows == 9) // bottom right corner
				{
					index = twoD[rows][cols] + twoD[rows - 1][cols] + twoD[rows][cols - 1];
				}//end if
				
				else
				{
					index = twoD[rows][cols] + twoD[rows - 1][cols] + twoD[rows][cols - 1] + twoD[rows + 1][cols];
				}//end else
			}//end if cols == 9
			
			// Update value in twoD //
			twoD[rows][cols] = twoD[rows][cols] + solution[index];		
		}//end for cols
	}//end for rows

	for(rows = 0; rows < 9; rows++)
	{
		for(cols = 0; cols < 9; cols++)
		{
			if(twoD[rows][cols] == 0)
				printf(".");
			else if(twoD[rows][cols] == 1)
				printf("!");
			else if(twoD[rows][cols] == 2)
				printf("X");
			else // if 3
				printf("#");
		}//end for cols
		
		printf("\n"); // formatting print //
	}//end for
}//end checkSolutionAndDisplay
*/




void checkSolutionAndDisplay(int runs, int * solution, int twoD[10][10], FILE * fout)
{
	int bordered[12][12];
	int bordered2[12][12];
	int rows, cols, index, x;
	
	// Fill the new array with 0's, assures //
	// that we dont hit empty values        //
	for(rows = 0; rows < 12; rows++)
	{
		for(cols = 0; cols < 12; cols++)
		{
			bordered[rows][cols] = 0;
			bordered2[rows][cols] = 0;
		}//end for cols
	}//end for rows
	
	
	// Now to copy the array to the bordered array //
	for(rows = 1; rows < 11; rows++)
	{
		for(cols = 1; cols < 11; cols++)
		{
			bordered[rows][cols] = twoD[rows - 1][cols - 1];
			bordered2[rows][cols] = twoD[rows - 1][cols - 1];
		}//end for cols
	}//end for rows
	
	
	for(x = 0; x <= runs; x++) // Number of Generations
	{
	
		// Display Results //
		printf("Generation: %d\n", x);
		fprintf(fout, "Generation: %d\n", x);
		
		for(rows = 1; rows < 11; rows++)
		{
			for(cols = 1; cols < 11; cols++)
			{
				if(bordered2[rows][cols] == 0)
				{
					printf(".");
					fprintf(fout, ".");
				}
				else if(bordered2[rows][cols] == 1)
				{
					printf("!");
					fprintf(fout, "!");
				}
				else if(bordered2[rows][cols] == 2)
				{
					printf("X");
					fprintf(fout, "X");
				}
				else if(bordered2[rows][cols] == 3)
				{
					printf("#");
					fprintf(fout, "#");
				}
			}//end for cols
		
			printf("\n"); // formatting print //
			fprintf(fout, "\n");
		}//end for
	
		
		// Finally traversal for calculations and  //
		// printing the results. We will constrain //
		// traversal from 1 - 11 so we avoid the   //
		// border of 0's.                          //
		for(rows = 1; rows < 11; rows++)
		{
			for(cols = 1; cols < 11; cols++)
			{
				index = bordered[rows][cols] + bordered[rows - 1][cols] + bordered[rows + 1][cols] + bordered[rows][cols - 1] + bordered[rows][cols + 1];
				
				if(bordered[rows][cols] + solution[index] > 3)
					bordered2[rows][cols] = 3;
				else if(bordered[rows][cols] + solution[index] < 0)
					bordered2[rows][cols] = 0;
				else
					bordered2[rows][cols] = bordered[rows][cols] + solution[index];
			}//end for cols
		}//end for rows
		
		for(rows = 0; rows < 12; rows++)
		{
			for(cols = 0; cols < 12; cols++)
			{
				bordered[rows][cols] = bordered2[rows][cols];
			}
		}//end for
		printf("\n");
		fprintf(fout, "\n");
	}//end for generations
}//end checkSolutionAndDisplay
