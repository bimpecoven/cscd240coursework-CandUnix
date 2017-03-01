/* @filename linked_list.c
 * 
 * @author Blake Impecoven
 * @date March, 2016
 * @brief Generic linked list implementation,
 *		  should be used with a helper file.
 * 		  INCLUDES DUMMY HEAD NODE
**/

#include "linked_list.h"

// Constructor
linked_list * linked_list()
{
	linked_list * myList = (linked_list *)calloc(1, sizeof(linked_list));
	myList->head = (Node *)calloc(1, sizeof(Node)); // dummy head node
	return myList;
}//end constructor



void addLast(linked_list * myList, Node * newNode)
{
	Node * cur = myList->head;
	
	while(cur != NULL)
	{
		cur = cur->next;
	}//end while
	
	cur = newNode;
	myList->size = myList->size + 1;
}//end addLast

void addFirst(linked_list * myList, Node * newNode)
{
	myList->head = newNode;
	myList->size = myList->size + 1;
}//end addFirst

void removeItem(linked_list * myList, Node * deleteMe, void (*removeData)(void *), int (*compare)(const void *first, const void *second))
{
	Node * cur = myList->head;
	Node * prev = cur;
	
	while(compare(cur->data->word, deleteMe->data->word) != 0 && cur != NULL)
	{
		cur = cur->next;
	}//end while
	
	removeData(deleteMe);
}//end removeItem

void clearList(linked_list * myList, void (*removeData)(void *))
{
	Node * cur = myList->head;
	
	while(cur != NULL)
	{
		removeData(cur->data);
		cur = cur->next;
	}//end while
	
	free(cur);
}//end clearList

void printList(const linked_list * myList, void (*convertData)(void *))
{
	Node * cur = myList->head;
	
	while(cur != NULL)
	{
		convertData(cur->data);
		cur = cur->next;
	}//end while
}//end printList