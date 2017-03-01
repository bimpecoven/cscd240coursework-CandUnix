// Blake Impecoven - CSCD240 - Generic Linked List - November, 2015.

#include "listUtils.h"

//Constructor
LinkedList * linkedList()
{
	return (LinkedList *)calloc(1, sizeof(LinkedList));
}//end constructor



void addLast(LinkedList * myList, Node * newNode)
{
	if(newNode == NULL)
	{
		printf("Error!\nCannot add Empty Node to the list.\n");
		exit(-99);
	}	
	
	if(myList->head->next == NULL) // is the list empty?
		addFirst(myList, newNode);

	Node * cur = myList->head;

	while(cur->next != NULL)
	{
		cur = cur->next;
	}//end while

	cur->next = newNode;
	newNode->next = NULL;
	myList->size = myList->size + 1;
}//end addLast

void addFirst(LinkedList * myList, Node * newNode)
{
	newNode->next = myList->head;
	myList->head = newNode;
	myList->size = myList->size + 1;
}//end addFirst

void removeItem(LinkedList * myList, Node * deleteMe, void (*removeData)(void *), int (*compare)(const void *first, const void *second))
{
	Node * cur = myList->head;
	Node * prev = NULL;

	if(compare(&cur->data, &deleteMe->data) == 0) // check if its the first item
	{
		myList->head = cur->next;
		removeData(&cur->data);
		myList->size = myList->size - 1;
	}//end if
	
	else
	{
		while(compare(&cur->data, &deleteMe->data) != 0 && cur->next != NULL)
		{	
			prev = cur;
			cur = cur->next;
		}//end while

		if(cur == NULL)
		{
			printf("Item not in list!\n");
			exit(-99);
		}//end if

		else
		{
			if(compare(&cur->data, &deleteMe->data) == 0)
			{
				prev->next = cur->next;
				removeData(&cur->data);	
				myList->size = myList->size - 1;
			}//end if
		}//end else
	}//end else
	free(deleteMe->data);
	free(deleteMe);
}//end removeItem

void clearList(LinkedList * myList, void (*removeData)(void *))
{
	Node * cur = myList->head;
	
	while(cur != NULL)
	{
		myList->head = cur->next;
		removeData(&cur->data);
		cur = myList->head;
	}//end while
	myList->size = 0;
	free(myList->head);
	free(cur);
}//end clearList

void printList(const LinkedList * myList, void (*convertData)(void *))
{
	if(myList->size < 1)
		printf("Empty List\n");

	Node * cur = myList->head;
	int x;
	
	for(x = 0; x < myList->size; x++)
	{
		convertData(&cur->data);
		cur = cur->next;
	}//end for
	printf("\n");
}//end printList
