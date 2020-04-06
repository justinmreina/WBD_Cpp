/************************************************************************************************************************************/
/** @file		Linked List Example.c
 * 	@brief		example of linkedlist generation and use
 * 	@details	x
 *
 * 	@section	Opens
 * 			none listed
 */
/************************************************************************************************************************************/
#include "linkedlist.h"


//Globals
Node *head;


/************************************************************************************************************************************/
/**	@fcn		Node *createNode(char *name)
 *  @brief		x
 *  @details	x
 *
 *  @section 	Opens
 *  	none listed
 */
/************************************************************************************************************************************/
Node *createNode(char *name) {

	//Locals
	Node *n; 																/* declare a node										*/

	//Allocate
    n = (Node *) malloc(sizeof(struct node)); 				 				/* allocate memory using malloc()						*/

    //Init
    n->name = name;
    n->data = name;
    n->prev = NOT_AN_ADDRESS;
    n->next = NOT_AN_ADDRESS;												/* make next point to NULL								*/

    return n;																/* return the new node									*/
}


/************************************************************************************************************************************/
/**	@fcn		void list_init(Node **list, Node *node)
 *  @brief		x
 *  @details	x
 *
 *  @param		[in]	(Node **) list - x
 *  @param		[in]	(Node *) node - x
 */
/************************************************************************************************************************************/
void list_init(Node **list, Node *node) {

	*list = node;
	head = *list;

	node->prev = NOT_AN_ADDRESS;

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void list_reset(Node **list)
 *  @brief		x
 *  @details	x
 *
 *  @param		[in]	(Node **) list - x
 */
/************************************************************************************************************************************/
void list_reset(Node **list) {

	*list = head;

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void list_add(Node **list, Node *node)
 *  @brief		x
 *  @details	x
 *
 *  @param		[in]	(Node **) list - x
 *  @param		[in]	(Node *) node - x
 */
/************************************************************************************************************************************/
void list_add(Node **list, Node *node) {

	//Store Refs
	(*list)->next = node;															/* original points forward to new						*/
	node->prev = *list;														/* new points back to original							*/

	//node is tail
	node->next = NOT_AN_ADDRESS;

	//Update List
	*list = node;															/* update list to point to newest						*/

	return;
}


/************************************************************************************************************************************/
/**	@fcn		Node list_next(Node *list)
 *  @brief		x
 *  @details	x
 *
 *  @param		[in]	(Node *) list - x
 */
/************************************************************************************************************************************/
Node list_next(Node *list) {
	/*!!!volatile*/ Node a;
	return a;
}


/************************************************************************************************************************************/
/**	@fcn		Node list_first(Node *list)
 *  @brief		x
 *  @details	x
 *
 *  @param		[in]	(Node *) list - x
 */
/************************************************************************************************************************************/
Node list_first(Node *list) {
	/*!!!volatile*/ Node a;
	return a;
}


/************************************************************************************************************************************/
/**	@fcn		Node list_last(Node *list)
 *  @brief		x
 *  @details	x
 *
 *  @param		[in]	(Node *) list - x
 */
/************************************************************************************************************************************/
Node list_last(Node *list) {
	/*!!!volatile*/ Node a;
	return a;
}


/************************************************************************************************************************************/
/**	@fcn		void list_increment(Node **list)
 *  @brief		x
 *  @details	x
 *
 *  @param		[in]	(Node **) list - x
 */
/************************************************************************************************************************************/
void list_increment(Node **list) {

	*list = (*list)->next;

	return;
}


/************************************************************************************************************************************/
/**	@fcn		int list_getLength(Node *list)
 *  @brief		get length of list
 *  @details	x
 *
 *  @param		[in] (Node *) list - head pointer for list to evaluate
 *  @return		(int) length of list
 *
 *  @assum 		entry node is valid (*list)
 */
/************************************************************************************************************************************/
int list_getLength(Node *list) {

	//Locals
	Node *curr;
	int len;

	//Init
	len = 1;																/* assume first node is valid							*/
	curr = list;															/* move to next											*/

	//Grab next
	while(curr->next != NOT_AN_ADDRESS) {
		len++;
		curr = curr->next;
	}

	return len;
}


/************************************************************************************************************************************/
/**	@fcn		bool list_isNext(Node *node)
 *  @brief		x
 *  @details	x
 *
 *  @param		[in]	(Node *) node - x
 *
 *  @return 	(bool) is their a following node in list?
 */
/************************************************************************************************************************************/
bool list_isNext(Node *node) {

	//Locals
	bool isNext;

	//Check
	isNext = (node->next != NOT_AN_ADDRESS);

	return isNext;
}

