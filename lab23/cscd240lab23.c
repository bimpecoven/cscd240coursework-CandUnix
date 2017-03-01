#include "lab23.h"

const int MAXSTRING = 655;

int main()
{
    int choice, total;
    char theString[MAXSTRING];
    char ** parsedString = NULL;

    readString(theString);

    do
    {
        choice = menu();

        switch(choice)
        {

            case 1:  readString(theString);
                     break;

            case 2:  parsedString = parseString(theString, &total);
		               writeTheString(parsedString, total);
		               break;

	         case 3: readTheString();


        }// end switch

     }while(choice != 4);

    return 0;

}// end main

