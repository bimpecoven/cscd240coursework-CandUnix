#include "mydebug.h"

int main(int argc, char ** argv)
{
	FILE * fin = NULL;
	int total, *array = NULL;
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
		array = fillArray(fin, total);
		sort(total, array);
	
		mean = calcMean(total, array);
		median = calcMedian(array, total);
		stdDev = calcStdDev(array, total);
		displayResults(mean, median, stdDev);
	
		total = readTotal(fin);

		free(array);

	}// end while

	fclose(fin);

	return 0;

}// end main

