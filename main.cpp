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
 * 		• Observed approximate 45 second search time
 * 		• Content located in administrator's locations (e.g. 'C:\Program Files') must be handled in supervisor mode
 *
 *	@section 	Opens
 *		• Uncomment out source for cpp conversion
 *		• re-integrate '!!!' content
 *		• correct compile warnings
 *		//..
 *		• convert to c++ (for extended routines)
 *		• void wbd_storeSearchLen()
 *		• wbdPath_getSubDirs()
 *		• test routines
 *		...
 *		• Get console prints working during program operation on debug session
 *		• print path subroutine
 *		• find all wbd dirs
 *		• ../globals.h include
 *		• remove 'util\' from include (start small is messy)
 *		• make test dir a relative path
 *
 *  @section 	Deferred Opens (pending confirm)
 *  	• Extend application to all "ByDay" variants
 *  	• Confirm safe use of char* with/without EOS
 * 		• Inject empty dirs on test boot
 *
 * 	@section	Legal Disclaimer
 * 			2020© Year Justin Reina, All rights reserved. All contents of this source file and/or any other related source
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

	cout << "Hello World!!" << endl; 										/* prints !!!Hello World!!!								*/

	//******************************************************************************************************************************//
	//															SEARCH																//
	//******************************************************************************************************************************//
	log_info("Beginning search query for WorkByDay -");

//	//Find all WBD in target
//	log_insertSection("WBD DIR CHECK");
//	wbdPath_getAllWbdDirs(searchDirs, rootDir);								/* store wbd directories found							*/
//
//	//Update Dir Counts
//	wbd_storeSearchLen(searchDirs);											/* @note 	this might not be needed					*/


//	//******************************************************************************************************************************//
//	//														   CLEAN EMPTIES														//
//	//******************************************************************************************************************************//
//
//	//Grab Start Time
//	timeVals[1] = time_getClockMs();
//
//	//Clean
////	for(String dir : searchDirs) {
////		WBDPath.cleanEmpties(new File(dir));								/* For each WBD, check for empties at root				*/
////	}
//
//
//	//******************************************************************************************************************************//
//	//														    ADD TODAY														  	//
//	//******************************************************************************************************************************//
//
//	//Add today
////	for(String dir : searchDirs) {
////		WBDPath.addToday(new File(dir)); 									/* add today if not found								*/
////	}
//
////	struct node *currNode = searchDirs;
//
//	log_insertSection("NODES");
//
//	Node *curr2Node = firstNode;
//
//	for(int i=0; i<3; i++) {
//
//		//Locals
//		char resp_str[50];
//
//		//Init
//		memset(resp_str, '\0', sizeof(resp_str));
//
//		//make
//		char *name = curr2Node->name;
//		sprintf(resp_str, "Hello %i: %s", (int)&curr2Node, name);
//
//		//print
//		log_info(resp_str);
//
//		//Update search
//		if(curr2Node->next!=NOT_AN_ADDRESS) {
//
//			sprintf(resp_str, "next is: %d", (int)&curr2Node->next);
//
//			log_info(resp_str);
//
//			list_increment(&curr2Node);
//		} else {
//			log_info("next is 0x0000 and passing");
//		}
//	}
//
//
//	//**************************************************************************************************************************//
//	//															 END															//
//	//**************************************************************************************************************************//
//
//	delay_s(3);
//
//	//Find elapsed time
//	timeVals[2] = time_getClockMs();
//
//	//Calc
//	long delta_ms = timeVals[2] - timeVals[1];
//	float time_s = (((float)delta_ms )/1000);
//
//	//Exit Message
//    char buffer[50];
//    int WBDPath_wbdcount = 2, WBDPath_count = 100;
//    sprintf(buffer, "WBDUpate complete(%d/%d).  Elapsed time: %fs", WBDPath_wbdcount, WBDPath_count, time_s);
//    log_info(buffer);
//
//	log_close();
//
//	return EXIT_SUCCESS;
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
 *  	none listed
 */
/************************************************************************************************************************************/
void sys_init(void) {
//
//	memset(&timeVals, 0, sizeof(timeVals));									/* clear time vals										*/
//	rootDir = malloc(sizeof(TEST_DIR));										/* grab space for string								*/
//	strcpy(rootDir, TEST_DIR);												/* App: SEARCH_DIR, Dev: TEST_DIR						*/
//
//	//Load Dev LinkedList
//
//	firstNode  = createNode(strOne);
//	secondNode = createNode(strTwo);
//	thirdNode  = createNode(strThree);
//	fourthNode  = createNode(strFour);
//
//	firstNode->next  = secondNode;
//	secondNode->next = thirdNode;
//	thirdNode->next = fourthNode;
//
//	//wbd_directories = new ArrayList<>();
//	log_init();
//
//	//Grab Start Time
//	timeVals[0] = time_getClockMs();
//
//	//Setup
//	wbdPath_setupTest(TEST_DIR);
//
//	//<temp> Setup searchDirs
//	searchDirs = firstNode;

	return;
}

