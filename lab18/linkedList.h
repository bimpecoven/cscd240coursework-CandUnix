#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stock.h"
#include "myUtils.h"

struct node
{
    Stock * data;
    struct node * next;
};

typedef struct node Node;

struct linkedList
{
    Node * head;
    int size;
};

typedef struct linkedList LinkedList;

LinkedList * linkedList();

void addFirst(LinkedList * myList, Stock * s);
void printList(LinkedList * myList);

void cleanNodes(LinkedList *myList);


#endif // LINKEDLIST_H
