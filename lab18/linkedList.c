// linkedList.c

#include "linkedList.h"
#include "myUtils.h"

LinkedList * linkedList()
{
	LinkedList * myList = (LinkedList *)calloc(1, sizeof(LinkedList));
	myList->head = (Node *)calloc(1, sizeof(Node)); // dummy head node
	return myList;
}//end constructor

void addFirst(LinkedList * myList, Stock * data)
{
	Node * newNode = (Node *)calloc(1, sizeof(Node));
	
	// Set values of nodes
	newNode->data = data;
	newNode->next = myList->head;
	myList->head = newNode;
	myList->size = myList->size + 1;
}//end addFirst	

int size(LinkedList * myList)
{
	return myList->size;
}//end size

void printList(LinkedList * myList)
{
	if(myList == NULL || myList->head == NULL)
		printf("The list is empty.\n");
	else
	{
		Node * cur = myList->head;
		
		while(cur != NULL)
		{
			printf("%s - %s - %.2lf\n", cur->data->companyName, cur->data->symbol, cur->data->currentPrice);

			cur = cur->next;
		}//end while
	}//end else
}//end printList

void cleanNodes(LinkedList * myList)
{
	if(myList != NULL)
	{
		myList->size = 0;
		Node * cur = myList->head;
		
		while(cur != NULL)
		{
			myList->head = cur->next;
			// in homework, free stock stuff(symbol, name, then stock struct itself)
			// write a cleanUp function in stock.c
			free(cur->data->symbol);
			free(cur->data->companyName);
			free(cur->data);
			//free(cur);
			cur = myList->head;
		}//end while
	}//end if	
}//end clean




/******* if you do dummy head free the dummy head before you free the list*/




//Build stock
/*
calloc(1, sizeof(Stock));
SS->symbol->calloc
strcpy
SS->name->calloc
strcpy
*/