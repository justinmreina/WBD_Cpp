#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

//Includes
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Project
#include "node.h"

//<temp>
typedef struct node Node;

//Definitions
#define NOT_AN_ADDRESS	(NULL)

//Typedefs
typedef Node* LinkedList;													/* simple wrapper to point at current spot in list		*/
																			/* @todo 	integrate to formal usage					*/
//Global Routines
extern Node *createNode(char *name);
extern void list_init(Node **list, Node *node);
extern void list_reset(Node **list);
extern void list_add(Node **list, Node *node);
extern Node list_next(Node *list);
extern Node list_first(Node *list);
extern Node list_last(Node *list);
extern void list_increment(Node **list);
extern bool list_isNext(Node *node);
extern int list_getLength(Node *list);

#endif /* LINKEDLIST_H_ */

