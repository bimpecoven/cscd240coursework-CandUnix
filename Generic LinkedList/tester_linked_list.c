// Tester file for linked_list data structure

#include <linked_list.h>

int main()
{
	linked_list * my_list = linked_list();
	Node add_node = NULL;
	int x;
	
	for(x = 0; x < 5; x++)
	{
		add_node.data = rand() % x;
		addLast(my_list, add_node);
	}//end for
	
	printList(my_list);
	
	return 0;
	
}//end main