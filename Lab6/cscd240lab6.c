// Blake Impecoven - cscd240 - lab6//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 25

FILE * openFile();
int readTotal(FILE * fin);
void fillArray(FILE * fin, int total, int array[]);
void sort(int total, int array[]);
double calcMean(int total, int array[]);
double calcMedian(int array[], int total);
double calcStdDev(int array[], int total);
void displayResults(double mean, double median, double stdDev);


int main(int argc, char ** argv)
{
	FILE * fin = NULL;
	int total, array[MAX];
	double mean, median, stdDev;

	if(argc < 2)
		fin = openFile();

	else
	{
		fin = fopen(argv[1], "r");
		if(fin == NULL)
			fin = openFile();
		
	}// end else

	total = readTotal(fin);
	while(!feof(fin) && total != -99)
	{
		fillArray(fin, total, array);
		sort(total, array);
	
		mean = calcMean(total, array);
		median = calcMedian(array, total);
		stdDev = calcStdDev(array, total);
		displayResults(mean, median, stdDev);
	
		total = readTotal(fin);

	}// end while

	fclose(fin);

	return 0;

}// end main

FILE * openFile()
{
	//declare file name (fin) and array//
	//to hold the files name           //
	FILE * fin; 
	char file_name[MAX];
	
	//prompt user for input//
	printf("Enter the name of the file: ");
	scanf("%s\n", file_name);

	//open the file//
	fin = fopen(file_name, "r");

	//check to see if the file is NULL//
	//or empty.                       //
	while(fin == NULL)
	{
		printf("Invalid file name, enter the name of the file: ");
		scanf("%s\n", file_name);
		fin = fopen(file_name, "r");
	}//end while

	//return the file. we know it isn't//
	//empty or NULL by this point      //
	return fin;
}// end openFile

int readTotal(FILE * fin)
{
	//declare total variable//
	int total;

	//take the next line in the file//
	//and store that in total       //
	fscanf(fin, "%d", &total);

	//return the total, will be used//
	//in later functions to tell how//
	//many lines to read.           //
	return total;
}// end readTotal

void fillArray(FILE * fin, int total, int array[])
{	
	//Stopping case! -99 casues    //
	//program to do nothing.       //
	if(total == -99)
		exit(0);

	//declared variables, x will be//
	//used as a counter.           //
	int x;
	
	//run for loop total number of//
	//times to fill the array.    //
	//after the loop is done, the //
	//array will be filled.       //
	for(x = 0; x < total - 1; x++)
	{
		fscanf(fin, "%d", &array[x]);
	}//end for
}// end fillArray

void sort(int total, int array[])
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
	for(start = 0; start < total - 1; start++)
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
		for(search = start + 1; search < total - 1; search++)
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
}// end sort

double calcMean(int total, int array[])
{
	//Declare variables.                  //
	//Variable x will be used as a counter//
	//Variable mean will store the the sum//
	//of all values in the array, and then//
	//be divided by total before being    //
	//returned.                           //
	int x;
	double mean;

	//Traverse the array and add up all the//
	//values in it. store in 'mean' var.   //
	for(x = 0; x < total - 1; x++)
	{
		mean += array[x];
	}//end for

	//Last step in calculating the mean...//
	mean = mean / total;

	return mean;
}// end calcMean

double calcMedian(int array[], int total)
{
	//Variable x will be used as a counter//
	//Variable's index1 and index2 may or //
	//may not be used, depending on array //
	//length.                             //
	int x, index1, index2;
	double median;
	
	//if statement to check if the length of//
	//the array is even or odd. if it is odd//
	//it will skip the if and go to the else//
	//statement for calculations.           //
	if(total %2 == 0)
	{
		//since the array is even in length//
		//we need to find the two middle   //
		//index's and store them in index1 //
		//and index2, add their values, and//
		//divide by two.                   //
		index1 = total / 2;
		index2 = index1 - 1;
		median = (array[index1] + array[index2]) / 2.0;
	}//end if (even)
	else
		//since the array is odd in length//
		//we only need to divide the array//
		//length by 2. that will give us  //
		//the index of the median.        //
		median = array[total / 2];

	return median;
}// end calcMedian

double calcStdDev(int array[], int total)
{
	//Variable x will be used as a counter//
	int x;
	double stdDev;

	//call the calcMean function.      //
	//SEE ABOVE FUNCTION FOR SPECIFICS.//
	double mean = calcMean(total, array);
	
	//second array for deviation calculations//
	//has to be of type: double.             //
	double deviations[MAX];

	//fill deviations array with for loop//
	for(x = 0; x < total; x++)
		deviations[x] = (array[x] - mean);

	//square deviations and keep a running//
	//total of the numbers.               //
	for(x = 0; x < total; x++)
	{
		stdDev = (deviations[x] * deviations[x]); 
	}//end for

	//we can use the sqrt function because we//
	//have included math.h                   //
	stdDev = sqrt(stdDev / (total -1.0));

	return stdDev;
}// end calcStdDev

void displayResults(double mean, double median, double stdDev)
{
	//Print out the results of the  //
	//parameters that were passed in//
	printf("The mean is: %f\n", mean);
	printf("The median is: %f\n", median);
	printf("The standard deviation is: %f\n", stdDev);
}// end displayResults
