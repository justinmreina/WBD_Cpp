/************************************************************************************************************************************/
/** @file		main.cpp
 * 	@brief		WorkByDay directory application
 * 	@details	maintain active day directory contents
 *
 * 	@author		Justin Reina, Firmware Engineer
 * 	@created	2/8/19
 * 	@last rev	4/5/20
 *
 *
 * 	@section 	Performance (pending confirm)
 * 		� Observed approximate 45 second search time
 * 		� Content located in administrator's locations (e.g. 'C:\Program Files') must be handled in supervisor mode
 *
 *	@section 	Opens
 *		� Uncomment out source for cpp conversion
 *		� re-integrate '!!!' content
 *		� correct compile warnings
 *		� get debug session working again
 *		� Debug steps work again
 *		//..
 *		� convert to c++ (for extended routines)
 *		� void wbd_storeSearchLen()
 *		� wbdPath_getSubDirs()
 *		� test routines
 *		...
 *		� Get console prints working during program operation on debug session
 *		� print path subroutine
 *		� find all wbd dirs
 *		� ../globals.h include
 *		� remove 'util\' from include (start small is messy)
 *		� make test dir a relative path
 *
 *  @section 	Deferred Opens (pending confirm)
 *  	� Extend application to all "ByDay" variants
 *  	� Confirm safe use of char* with/without EOS
 * 		� Inject empty dirs on test boot
 * 		� Remove warning: "Invalid project path: Include path not found (source)"
 *
 * 	@section	Legal Disclaimer
 * 			2020� Year Justin Reina, All rights reserved. All contents of this source file and/or any other related source
 *			files are the explicit property of Justin Reina. Do not distribute. Do not copy.
 */
/************************************************************************************************************************************/
#include <iostream>
using namespace std;

#include "globals.h"


//Dev Variables
char const *strOne   = "StringOne";
char const *strTwo   = "StringTwo";
char const *strThree = "StringThree";
char const *strFour = "StringFour";

//Local Routines
void sys_init(void);
void sys_close(void);

//Temp Locals
long timeVals[3];															/* dates found for time measurement						*/
Node *searchDirs;															/* wbd dirs found										*/
char *rootDir;
Node *firstNode, *secondNode, *thirdNode, *fourthNode;


/************************************************************************************************************************************/
/**	@fcn		int main(void)
 *  @brief		x
 *  @details	x
 *
 *  @section 	Opens
 *  	sys_init()
 *  	src_test()
 */
/************************************************************************************************************************************/
int main(void) {

	//Init
	sys_init();

	//******************************************************************************************************************************//
	//															SEARCH																//
	//******************************************************************************************************************************//
	log_info((char *)"Beginning search query for WorkByDay -");

	//Find all WBD in target
	log_insertSection((char *)"WBD DIR CHECK");
	wbdPath_getAllWbdDirs(searchDirs, rootDir);								/* store wbd directories found							*/

	//Update Dir Counts
	wbd_storeSearchLen(searchDirs);											/* @note 	this might not be needed					*/

	//******************************************************************************************************************************//
	//														   CLEAN EMPTIES														//
	//******************************************************************************************************************************//

	//Grab Start Time
	timeVals[1] = time_getClockMs();

	int searchDirs_count = list_getLength(searchDirs);

	//Clean
	for(int i=0; i<searchDirs_count; i++) {
		//cleanEmpties(searchDirs(i)										/* For each WBD, check for empties at root				*/
	}

	//******************************************************************************************************************************//
	//														    ADD TODAY														  	//
	//******************************************************************************************************************************//

	//Add today
	for(int i=0; i<searchDirs_count; i++) {
		//addToday(searchDirs(i)											/* add today if not found								*/
	}

	log_insertSection((char *)"NODES");

	Node *curr2Node = firstNode;

	for(int i=0; i<3; i++) {

		//Locals
		char resp_str[50];

		//Init
		memset(resp_str, '\0', sizeof(resp_str));

		//make
		char *name = curr2Node->name;
		sprintf(resp_str, "Hello %i: %s", (int)&curr2Node, name);

		//print
		log_info(resp_str);

		//Update search
		if(curr2Node->next!=NOT_AN_ADDRESS) {

			sprintf(resp_str, "next is: %d", (int)&curr2Node->next);

			log_info(resp_str);

			list_increment(&curr2Node);
		} else {
			log_info((char *)"next is 0x0000 and passing");
		}
	}


	//**************************************************************************************************************************//
	//															 END															//
	//**************************************************************************************************************************//

	delay_s(3);

	//Find elapsed time
	timeVals[2] = time_getClockMs();

	//Calc
	long delta_ms = timeVals[2] - timeVals[1];
	float time_s = (((float)delta_ms )/1000);

	//Exit Message
    char buffer[50];
    int WBDPath_wbdcount = 2, WBDPath_count = 100;
    sprintf(buffer, "WBDUpate complete(%d/%d).  Elapsed time: %.2fs", WBDPath_wbdcount, WBDPath_count, time_s);
    log_info(buffer);

	//Exit
	sys_close();

	return EXIT_SUCCESS;
}


/************************************************************************************************************************************/
/**	@fcn		void sys_init(void)
 *  @brief		initialize the system for operation
 *  @details	x
 *
 *	@pre	any
 *	@post	ready to perform operation
 *
 *  @section 	Opens
 *  	drop 100 pad
 */
/************************************************************************************************************************************/
void sys_init(void) {

	//Init Variables
	memset(&timeVals, 0, sizeof(timeVals));									/* clear time vals										*/
	rootDir = (char *)malloc(strlen(util_getTestDir()));					/* grab space for string								*/
	strcpy(rootDir, util_getTestDir());										/* App: SEARCH_DIR, Dev: TEST_DIR						*/

	//Load Dev LinkedList
	firstNode  = createNode((char *)strOne);
	secondNode = createNode((char *)strTwo);
	thirdNode  = createNode((char *)strThree);
	fourthNode  = createNode((char *)strFour);

	firstNode->next  = secondNode;
	secondNode->next = thirdNode;
	thirdNode->next = fourthNode;

	//wbd_directories = new ArrayList<>();
	log_init();

	//Grab Start Time
	timeVals[0] = time_getClockMs();

	//Setup
	wbdPath_setupTest((char *)util_getTestDir());

	//<temp> Setup searchDirs
	searchDirs = firstNode;

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void sys_closet(void)
 *  @brief		end operations
 *  @details	x
 *
 *	@pre	system is running
 *	@post	system is ready to complete
 *
 *  @section 	Opens
 *  	none listed
 */
/************************************************************************************************************************************/
void sys_close(void) {

	//Release mem
	free(rootDir);

	//Close log
	log_close();

	return;
}

