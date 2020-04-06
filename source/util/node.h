//@todo 	find a way to integrate or eliminate this file
//@details 	was used to get code working
#ifndef NODE_H_
#define NODE_H_

//Project Includes
#include "linkedlist.h"

//Typedefs
typedef struct node Node;

//Structures
struct node {																/* Dev Nodes											*/
	void *data;																/* data of node?										*/
    char *name;																/* identifier of node									*/
    Node* prev;																/* node pre												*/
    Node* next;																/* node post											*/
};

#endif /* NODE_H_ */

