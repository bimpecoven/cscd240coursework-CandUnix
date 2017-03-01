// Blake Impecoven - CSCD240 - Generic Linked List - November, 2015.

// Constructor
LinkedList * linkedList()
{
	LinkedList * myList = (LinkedList *)calloc(1, sizeof(LinkedList));
	myList->head = (Node *)calloc(1, sizeof(Node)); // dummy head node
	return myList;
}//end constructor



void addLast(LinkedList * myList, Node * newNode)
{
	Node * cur = myList->head;
	
	while(cur != NULL)
	{
		cur = cur->next;
	}//end while
	
	cur = newNode;
	myList->size = myList->size + 1;
}//end addLast

void addFirst(LinkedList * myList, Node * newNode)
{
	//newNode->next = myList->head;
	myList->head = newNode;
	myList->size = myList->size + 1;
}//end addFirst

void removeItem(LinkedList * myList, Node * deleteMe, void (*removeData)(void *), int (*compare)(const void *first, const void *second))
{
	Node * cur = myList->head;
	Node * prev = cur;
	
	while(compare(cur->data->word, deleteMe->data->word) != 0 && cur != NULL)
	{
		cur = cur->next;
	}//end while
	
	removeData(deleteMe);
}//end removeItem

void clearList(LinkedList * myList, void (*removeData)(void *))
{
	Node * cur = myList->head;
	
	while(cur != NULL)
	{
		removeData(cur->data);
		cur = cur->next;
	}//end while
	
	free(cur);
}//end clearList

void printList(const LinkedList * myList, void (*convertData)(void *))
{
	Node * cur = myList->head;
	
	while(cur != NULL)
	{
		convertData(cur->data);
		cur = cur->next;
	}//end while
}//end printList