#include <stdio.h>
#include <stdlib.h>

//prototypes
void function1(int twod[][3], int rows, int cols);
void function2(int twod[][3], int rows, int cols); 
void function3(int twod[], int rows, int cols);
void function4(int twod[], int rows, int cols);
void function5(int * twod, int rows, int cols);
void function6(int (*twod)[3], int rows, int cols);

int main()
{
	int twod[4][3] = { {0, 1, 2}, {10, 11, 12}, {20, 21, 22}, {30, 31, 32} };
	// NOTE: a 2D array is a double pointer so you have to derefernce the name 
	// to be able to use a 1D pointer
	int *ptr = *twod;

	/* This gives us an idea of the memory map */ 
	printf("sizeof(ptr) %ld\n", sizeof(ptr)); 
	printf("sizeof(twod) %ld\n", sizeof(twod));
	printf("sizeof(twod[0]) %ld\n", sizeof(twod[0])); 
	printf("sizeof(twod[0][0]) %ld\n", sizeof(twod[0][0]));

	printf("twod %p\n", twod); 
	printf("ptr %p\n", ptr);

	printf("&twod[0] %p\n", &twod[0]); 
	printf("&twod[0][0] %p\n", &twod[0][0]); 
	printf("&twod[0][1] %p\n", &twod[0][1]); 
	printf("&twod[0][2] %p\n", &twod[0][2]);

	printf("&twod[1] %p\n", &twod[1]); 
	printf("&ptr %p\n\n\n", &ptr);
	/* end memory map */
	
	//Part two//
	printf("twod + 3 is: %p\n", twod + 3); //p
	printf("*(*(twod + 1)) is: %d\n", *(*(twod + 1))); //d
	printf("*twod + 1 is: %p\n", *twod+1); //p
	printf("*twod[2] is: %d\n", *twod[2]); //d
	printf("*(twod + 2) + 2 is: %p\n", *(twod + 2) + 2); //p
	printf("twod[1] is: %p\n", twod[1]); //p
	printf("twod[1][2] is: %d\n\n", twod[1][2]);//d
	
	printf("ptr %p\n", ptr); //p
	printf("twod [1] %p\n", twod [1]); //p
	printf("ptr[1] %d\n", ptr[1]); //d
	printf("ptr + 1 %p\n", ptr + 1); //p
	printf("*(ptr + 1) %d\n", *(ptr + 1) ); //d
	printf("twod + 1 %p\n", twod+1); //p
	printf("*twod + 1 %p\n", *twod + 1); //d
	printf("ptr[8] %d\n", ptr[8]); //d
	
	//printf("\n\nTEST LINE: %d\n\n", (*twod)[3]);
	
	function1(twod, 4, 3);
	function2(twod, 4, 3);
	function3(twod[0], 4, 3);
	function4(twod[0], 4, 3);
	function5(twod[0], 4, 3);
	function6(twod, 4, 3);
}//end main

void function1(int twod[][3], int rows, int cols)
{
	printf("Function 1 -- Start.\n");
	printf("function1\n");
	int x, y;
	
	for(x = 0; x < rows; x++)
	{
		for(y = 0; y < cols; y++)
		{
			printf("%d ", twod[x][y]);
		}//end for cols
		printf("\n");
	}//end for rows
	printf("Function 1 -- Exit.\n\n");
}//end function1

void function2(int twod[][3], int rows, int cols)
{
	printf("Function 2 -- Start.\n");
	printf("function2\n");
	int x, y;
	
	for(x = 0; x < rows; x++)
	{
		for(y = cols - 1; y >= 0; y--)
		{
			printf("%d ", twod[x][y]);
		}//end for cols
		printf("\n");
	}//end for rows	
	printf("Function 2 -- Exit.\n\n");
}//end function2

void function3(int twod[], int rows, int cols)
{
	printf("Function 3 -- Start.\n");
	printf("function3\n");
	int x, y;
	
	for(x = 0; x < rows; x++)
	{
		for(y = 0; y < cols; y++)
		{
			printf("%d ", *twod + y);
		}//end for cols
		twod += 3;
		printf("\n");
	}//end for rows
	printf("Function 3 -- Exit.\n\n");
}//end function3

void function4(int twod[], int rows, int cols)
{
	printf("Function 4 -- Start.\n");
	printf("function4\n");
	int x, y;
	
	for(x = 0; x < rows; x++)
	{
		for(y = cols - 1; y >= 0; y--)
		{
			printf("%d ", *twod + y);
		}//end for cols
		twod += 3;
		printf("\n");
	}//end for rows
	printf("Function 4 -- Exit.\n\n");
}//end function4

void function5(int * twod, int rows, int cols)
{
	printf("Function 5 -- Start.\n");
	printf("function5\n");
	int x, y;
	
	for(x = 0; x < rows; x++)
	{
		for(y = cols - 1; y >= 0; y--)
		{
			printf("%d ", *twod + y);
		}//end for cols
		twod += 3;
		printf("\n");
	}//end for
	printf("Function 5 -- Exit.\n\n");
}//end function5

void function6(int (*twod)[3], int rows, int cols)
{
	printf("Function 6 -- Start.\n");
	printf("function6\n");
	int x, y;
	
	for(x = 0; x < rows; x++)
	{
		for(y = 0; y < cols; y++)
		{
			printf("%d ", twod[x][y]);
		}//end for cols
		printf("\n");
	}//end for rows
	printf("Function 6 -- Exit.\n\n");
}//end function6































