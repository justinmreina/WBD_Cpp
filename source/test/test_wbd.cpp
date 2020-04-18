/************************************************************************************************************************************/
/** @file		test_wbd.c
 * 	@brief		x
 * 	@details	x
 *
 *
 * 	@notes		x
 *
 * 	@section	Opens
 * 			none listed
 *
 * 	@section	Legal Disclaimer
 * 			2020© Year Justin Reina, All rights reserved. All contents of this source file and/or any other related source
 *			files are the explicit property of Justin Reina. Do not distribute. Do not copy.
 */
/************************************************************************************************************************************/
#include "test_wbd.h"


/************************************************************************************************************************************/
/**	@fcn		bool test_wbd_storeSearchLen(void)
 *  @brief		test wbd_storeSearchLen() routine
 *  @details	x
 *
 *  @return 	(bool) test results
 *
 *  @section 	Opens
 *  	none listed
 */
/************************************************************************************************************************************/
bool test_wbd_storeSearchLen(void) {

	//Locals
	struct node theList[5];
	struct node abc;

	//Load
	abc.name = (char *)"justin";
	abc.next = (Node *) &abc;
	abc.prev = (Node *) &abc;
	abc.data = abc.name;


	//Store
	theList[0] = abc;
	theList[1] = {.data = abc.name, .name = abc.name, .prev = &abc, .next = &abc};

	wbd_storeSearchLen(theList);

	return true;
}

