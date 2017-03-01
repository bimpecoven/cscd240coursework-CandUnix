#include <stdio.h>
#include <stdlib.h>

//      --Prototype's--      //
int readInitialLength();
int * createAndFill(int length);
int menu();
void printSortedArray(int *array, int length);
int * addItem(int *num, int *array);
int readValue();
void printIfFound(int value, int *array, int length);
void cleanUp(int *array);
void sort(int *array, int length);

int main()
{
    int * array = NULL;
    int length, choice, value;

    length = readInitialLength();
    array = createAndFill(length);

    do
    {
        choice = menu();

        switch(choice)
        {
            case 1: printSortedArray(array, length);
                    break;

            case 2: array = addItem(&length, array);
                    break;

            case 3: value = readValue();
                    printIfFound(value, array, length);
        }
    }while(choice != 4);

    cleanUp(array);
    array = NULL;

    return 0;
}// end main

int readInitialLength()
{
	int length;
	printf("Enter the length of your array: ");
	fscanf(stdin, "%d", &length);

	//     --post condition checking--     //   
	while(length < 1)
	{
		printf("Invald Length! Needs to be greater than 0.\n");
		printf("Enter the length of your array: ");
		fscanf(stdin, "%d", &length);
	}//end while

	return length;
}//end readInitialLength

int * createAndFill(int length)
{
	//Create's an array that will be//
	//eventually filled within the  //
	//function and returned.        //
	int x, *temp = NULL;
	
	temp = (int *)calloc(length, sizeof(int));

	for(x = 0; x < length; x++)
	{
		printf("Enter value(%d/%d): ", (x+1), length);
		fscanf(stdin, "%d", temp + x);
	}//end for

	return temp;
}//end createAndFill

int menu()
{
	int choice;	

	printf("     --Menu--     \n");
	printf("1) Print the sorted array.\n");
	printf("2) Add new item to the array.\n");
	printf("3) Find item in the array. (readValue)\n");
	printf("4) Quit.\n");
	printf("Your choice: ");
	scanf("%d", &choice);

	while(choice < 1 || choice > 4)
	{
		printf("Invalid choice! Out of range. (1-4)\n");
		printf("Your choice: ");
		scanf("%d", &choice);
	}//end while

	return choice;
}//end menu

void printSortedArray(int *array, int length)
{
	//Sort the array.//
	sort(array, length);
	
	int x;
	for(x = 0; x < length; x++)
		//If statement for formatting reasons//
		if(x < length - 1)
			printf("%d, ", array[x]);
		else
			printf("%d\n", array[x]);
}//end printSortedArray

int * addItem(int *num, int *array)`
{
	int x, val, *temp = NULL;
	*num = (*num + 1);

	temp = (int *)calloc(*num, sizeof(int));
	
	printf("Enter a value to add to the array: ");
	scanf("%d", &val);

	for(x = 0; x < (*num) - 1; x++)
	{
		temp[x] = array[x];
	}//end for

	temp[(*num) - 1] = val;

	cleanUp(array);
	array = NULL;

	return temp;
}//end addItem

int readValue()
{
	int value;

	printf("Enter a value: ");
	scanf("%d", &value);
	
	return value;
}//end readValue

void printIfFound(int value, int *array, int length)
{
	int x, found = 0;

	for(x = 0; x < length; x++)
	{
		if(array[x] == value)
		{
			printf("Value: %d found at array index: %d.\n", array[x], x);
			x = length; //stop for loop
			found = 1;
		}//end if
	}//end for

	if(found == 0)
		printf("Error - Value not found in the array!\n");

}//end printIfFound

void cleanUp(int *array)
{
	free(array);
}//end cleanUp

void sort(int *array, int length)
{
	//Sorting algorithm - sort the array//
	//based on value from least to      //
	//greatest. Least being in index 0. //
	
	//Declare variables - these will be//
	//used as place holders            //
	int start, search, min, temp;

	//This for loop (start) will move our//
	//starting placeholder through the   //
	//array.                             //
	for(start = 0; start < length - 1; start++)
	{
		
		//Assign start to the min variable//
		//since the minimum should always //
		//be the left most in the array   //
		//when you're sorting. This keeps //
		//your algorithm in order.        //
		min = start;

		//This for loop (search) will move our//
		//searching placeholder about the     //
		//array, while looking for the new    //
		//minimum value, and then store it in //
		//the minimum variable.               //
		for(search = start + 1; search < length; search++)
		{
			if(array[search] < array[min])
				min = search;
		}//end for(search

		//Move the values around by swapping the//
		//values at index min and index start in//
		//the array.                            //
		temp = array[min];
		array[min] = array[start];
		array[start] = temp;
	}//end for(start

	//at this point we know the array has//
	//finished sorting. No return.       //
}//end sort
