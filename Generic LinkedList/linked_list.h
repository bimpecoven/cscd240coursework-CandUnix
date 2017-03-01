/* @filename linked_list.h
 * 
 * @author Blake Impecoven
 * @date March, 2016
 * @brief Generic linked list implementation,
 *		  should be used with a helper file.
 * 		  INLCUDES DUMMY HEAD NODE
**/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include <data_type.h>

struct node
{
    void * data;
    struct node * next;
};
typedef struct node Node;

struct linked_list
{
    Node * head;
    Node * start;
    int size;
};
typedef struct linked_list linked_list;

linked_list * linked_list();

void addLast(linked_list * myList, Node * newNode);
void addFirst(linked_list * myList, Node * newNode);
void removeItem(linked_list * myList, Node * deleteMe, void (*removeData)(void *), int (*compare)(const void *first, const void *second));
void clearList(linked_list * myList, void (*removeData)(void *));
void printList(const linked_list * myList, void (*convertData)(void *));

#endif
