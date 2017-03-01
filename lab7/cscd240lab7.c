#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define TOTAL 10

//      --Prototypes--      //
void readName(char name[]);
int readTotals(char type[]);
void fillArray(char type[], int array[], int total);
double calcAvg(int array[], int total);
void displayAverage(char type[], double average);
double calcWeighted(double labAvg, double hwAvg, double quizAvg, double examAvg);
double calcGrade(double weightedAvg);
void display(double weightedAvg, double grade);

const double LABP = .2, HWP = .3, QUIZP = .11, EXAMP = .39;

int main()
{
    char name[MAX];
    int hwTotal, quizTotal, labsTotal, examsTotal;
    int hw[TOTAL], quizzes[TOTAL], labs[TOTAL], exams[TOTAL];
    double labAvg, hwAvg, quizAvg, examAvg, weightedAvg, finalGrade;

    readName(name);

    labsTotal = readTotals("Labs");
    fillArray("Labs", labs, labsTotal);
    labAvg = calcAvg(labs, labsTotal);
    displayAverage("Lab", labAvg);

    hwTotal = readTotals("Homeworks");
    fillArray("Homeworks", hw, hwTotal);
    hwAvg = calcAvg(hw, hwTotal);
    displayAverage("Homework", hwAvg);

    quizTotal = readTotals("Quizzes");
    fillArray("Quizzes", quizzes, quizTotal);
    quizAvg = calcAvg(quizzes, quizTotal);
    displayAverage("Quiz", quizAvg);

    examsTotal = readTotals("Exams");
    fillArray("Exams", exams, examsTotal);
    examAvg = calcAvg(exams, examsTotal);
    displayAverage("Exam", examAvg);

    weightedAvg = calcWeighted(labAvg, hwAvg, quizAvg, examAvg);
    finalGrade = calcGrade(weightedAvg);

    display(weightedAvg, finalGrade);

    return 0;
    
}// end main

void readName(char name[])
{
	printf("Please enter your name: ");
	fgets(name, MAX, stdin);
	
	printf("Student Name: %s\n", name);
}//end readName

int readTotals(char type[])
{
	//declare a variable for the total//
	//to be returned to main          //
	int total;

	printf("Enter in the number of %s: ", type);
	fscanf(stdin, "%d", &total);

	//Have to check to see that the total//
	//will fit into the arrays, that are //
	//sized at 10. We also have to make  //
	//sure we get at least one number as //
	//well.                              //
	while(total > TOTAL)
	{
		printf("Invalid total! Total not in range. (1-10)\n");
		printf("Enter in the number of %s: ", type);
		fscanf(stdin, "%d", &total);
	}//end while
	
	//We know that by this line the total//
	//is an int between 1 and 10. Safe to//
	//return.			     //
	return total;
}//end labsTotal

void fillArray(char type[], int array[], int total)
{	
	//x will act as a counter//
	int x;

	//for loop will execute 'total'//
	//number of times. (reads all  //
	//test scores.)                //
	for(x = 0; x < total; x++)
	{
		printf("Please enter your %s score(%d/%d): ", type, (x + 1), total);
		fscanf(stdin, "%d", &array[x]);
/*	  *COMMENTED OUT - CAUSED TOO MANY LOGIC ERRORS*
	I was trying to condition check... but c broke me.

		//while loop - ensures the score//
		//is within the range. not      //
		//possible to score higher than //
		//100, or less than 0 points.   //
		while(array[x] > MAX || array[x] < 0)
		{
			printf("Invalid score! Score not in range. (0-100)");
			printf("Please enter your %s score(%d/%d): ", type, x, total);
			fscanf(stdin, "%d", &array[x]);
		}//end while
*/
	}//end for

}//end fillArray

double calcAvg(int array[], int total)
{
	//      --declare variables--      //
	//x will act as a counter, average //
	//will be returned after it is     //
	//calculated.                      //
	int x;
	double average;

	//calculations for average wil start//
	//inside the for loop, and end out- //
	//side the loop.                    //
	for(x = 0; x < total; x++)
		average += array[x];

	average = average / total;

	//all calculations are finished//
	//average is accurate and ready//
	//for return.                  //
	return average;
}//end calcAverage

void displayAverage(char type[], double average)
{
	printf("%s average: %.01f\n", type, average);
}//end displayAverage

double calcWeighted(double labAvg, double hwAvg, double quizAvg, double examAvg)
{
	//      --declare variables--      //
	//weightedAvg will be returned,    //
	//calulated by using the arguments //
	//passed in with its corresponding //
	//constants.                       //
	double weightedAvg;

	//calculate averages by category//
	labAvg *= LABP;

	hwAvg *= HWP;
	
	quizAvg *= QUIZP;
	
	examAvg *= EXAMP;

	//add the averages together to form//
	//the weighted average.            //
	weightedAvg = (labAvg + hwAvg + quizAvg + examAvg);
}//end calcWeighted

double calcGrade(double weightedAvg)
{
	//      --Declare variables--      //
	//grade will be returned after GPA //
	//is calculated with the given     //
	//formula.                         //
	double grade;

	grade = 4.2 - (( 100 - weightedAvg) / 12);

	return grade;
}//end calcGrade

void display(double weightedAvg, double grade)
{
	printf("Your weighted percentage is: %.1f\n", weightedAvg);
	printf("Your final grade is: %.1f\n", grade);
}//end display
