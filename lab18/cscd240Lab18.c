#include "lab18.h"
#include "myUtils.h"
#include "fileUtil.h"
#include "linkedList.h"

int main()
{
    FILE * fin = NULL;
    int choice;
    LinkedList * myList = linkedList();

    fin = openInputFile_Prompt();

    fillList(myList, fin);
    printList(myList);

    fclose(fin);
    fin = NULL;

    do
    {
		  choice = menu();
        switch(choice)
        {
			case 1:	sort(myList, symbolSort);
					   printList(myList);
					   break;

			case 2:  sort(myList, companySort);
					   printList(myList);

					   break;

			case 3: sort(myList, priceSort);
					  printList(myList);
					  break;

               
			case 4: printf("all done\n");

		}// end switch


	}while(choice != 4);

	cleanNodes(myList);
	free(myList);
	myList = NULL;

   return 0;

}// end main
