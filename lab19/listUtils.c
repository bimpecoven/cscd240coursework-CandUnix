// Blake Impecoven - CSCD240 - Lab19 - November, 2015.

#include "listUtils.h"

Node * buildNode(FILE * in, void *(*buildData)(FILE * in) )
{
	Node * newNode = (Node *)buildData(in);
	return newNode;
}//end buildNode

void sort(LinkedList * myList, int (*compare)(const void *, const void *))
{
	Node *start, *search, *min;
	Words *temp = NULL;//(Words *)calloc(1, sizeof(Words));
	
	for(start = myList->head; start != NULL; start = start->next)
	{
		min = start;

		for(search = start->next; search != NULL; search = search->next)
		{

			if(compare(&search->data, &min->data) < 0)
				min = search;
		}//end for(search
		
		temp = min->data;
		min->data = start->data;
		start->data = temp;
	}//end for(start
}//end sort

void buildList(LinkedList * myList, FILE * fin, int total, void * (*buildData)(FILE * in))
{
	if(fin == NULL)
	{
		printf("Error!\nFile does not exist.\n");
		exit(-99);
	}//end if

	if(total == 0)
	{
		printf("Error!\nFile is empty.\n");
		exit(-99);
	}//end if

	int x;
	
	for(x = 0; x < total; x++)
	{
		Node * newNode = buildData(fin);
		addFirst(myList, newNode);
	}//end for

}//end buildList
