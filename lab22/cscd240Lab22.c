#include "myUtils.h"
#include "fileUtil.h"
#include "listUtils.h"
#include "linkedList.h"
#include "students.h"

int main()
{

   int total, choice;
	FILE * fin = NULL;
	LinkedList * myList = linkedList();

	fin = openInputFile_Prompt();
	total = countRecords(fin, 2);
   buildList(myList, fin, total, buildStudent);
   fclose(fin);

   do
   {
      choice = menu();

      switch(choice)
      {
            case 1: printList(myList, printStudent);
                    break;

            case 2: addFirst(myList, buildNode(stdin, buildStudent_Prompt));
                    break;

            case 3: addLast(myList, buildNode(stdin, buildStudent_Prompt));
                    break;

            case 4: sort(myList, compareTwoStudents);
                    break;

            case 5: removeItem(myList, buildNode(stdin, buildStudent_Prompt), cleanStudent, compareTwoStudents);
                    break;
      }// end switch

   }while(choice != 6);

   clearList(myList, cleanStudent);
   free(myList);
   myList = NULL;

   return 0;

}// end main

