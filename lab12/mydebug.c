#include "mydebug.h"

FILE * openFile()
{
    char fn[100];
    FILE * fin = NULL;

    printf("Please enter the filename ");
    scanf("%s",fn);
 
    fin = fopen(fn, "r");
    
    while (fin == NULL)
    {
        printf("Please enter the filename ");
        scanf("%s",fn);
 
        fin = fopen(fn, "r");
     
    }// end openFile 
    
    return fin;
    
}// end openFile

int readTotal(FILE * fin)
{
   int total;
    
   fscanf(fin, "%d", &total);
    
   return total;
   
}// end readTotal

int * fillArray(FILE * fin, int total)
{
    int x, garbage;
    int * array = (int *) calloc(total, sizeof(int));
   
    
    for(x = 0; x <= total; x++)
    {
        if(x < MAX) 
            fscanf(fin, "%d", &array[x]);  
        else
            fscanf(fin, "%d", &garbage);
    }

}// end fillArray

void sort(int total, int array[])
{
    if (total > MAX)
        total = MAX;
    
    int start, search, min;
    int temp;
    
    for(start = 0; start < total - 1; start ++)
    {
      min = start;
      for(search = start + 1; search < total; search ++)
      {
         if(array[search] < array[min])
            min = search;
      
      }// end for search
      
      temp = array[min];
      array[min] = array[start];
      array[start] = min;
    
    }// end for start

}// end sort

double calcMean(int total, int array[])
{
    if (total > MAX)
        total = MAX;
    
    int sum = 0;
    
    int x;
    for (x = 0; x < total; x++)
        sum += array[x];
    
	return (double)(sum) / total;
}// end calcMean

double calcMedian(int array[], int total)
{
    if (total > MAX)
        total = MAX;
    
    if (total % 2 == 0) 
        return (array[total/2 - 1] + array[total/2])/2.0;
    else 
        return (double)array[total/2];
        
}// end calcMedian

double calcStdDev(int array[], int total)
{
   if (total > MAX)
        total = MAX;
        
   int x;
   double sum = 0;
   double mean = calcMean(total, array);
   double devations[MAX];  // Would love to use total but I can't
         
   for (x = 0; x < total; x++) 
      devations[x] = (double)(array[x]) - mean;

        
   for (x = 0; x < total; x++)
      devations[x] = devations[x] * devations[x];

        
   for (x = 0; x < total; x++)
            sum += devations[x];

   return sqrt( sum / (total - 1));
    
}// end calcStdDev

void displayResults(double mean, double median, double stdDev)
{
    printf("Mean: %f\n", mean);

    printf("Median: %f\n", median);

    printf("Standard Deviation: %f\n", stdDev);
    
    printf("\n");
    
}// end displayResults
