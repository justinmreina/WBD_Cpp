/************************************************************************************************************************************/
/** @file		wbd.c
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
#include "wbd.h"

//<temp> variables
static int listLength;

//<temp> routines
FILE * wbdPath_getSubDirs(FILE *dir);
void wbd_storeSearchLen(struct node *list);


/************************************************************************************************************************************/
/**	@fcn		void wbdPath_getAllWbdDirs(Node *wbdVals, char *loc)
 *  @brief		Find all wbd dirs on path
 *  @details	x
 *
 *  @param		[in]	(struct node *) wbdVals - Location to store found wbd results
 *  @param		[in]	(char *) loc - Location to search
 *
 *  @assum	enough space in searchDirs for result
 *
 *  @section 	Opens
 *  	Generalize search query (e.g. support for PrintByDay and others)
 */
/************************************************************************************************************************************/
void wbdPath_getAllWbdDirs(struct node *wbdVals, char *loc) {
//
//	//Locals
//<<<<<<< HEAD
//	char buf[100];
//	DIR *d;
//	struct dirent *dir;
//
//	//Grab
//	d = opendir(loc);
//=======
//	bool thereIsANext;
//	struct node *curr;
//>>>>>>> refs/heads/search_work
//
//<<<<<<< HEAD
//	//Expand dir listing
//	if(d) {
//		//Check Subdirs
//		while((dir = readdir(d)) != NULL) {
//=======
//	//Init
//	FILE *dir = fopen(loc, "w");
//>>>>>>> refs/heads/search_work
//
//<<<<<<< HEAD
//			if(dir->d_type == DT_DIR) {
//				//check within (recurse?)
//=======
//	//<temp>
//	fclose(dir);
//
//	//check at loc
//	//get subdirs at loc
////	FILE *subdirs = wbdPath_getSubDirs(dir);
//
//	//check subdirs
//	//repeat
//
//	//...
//
//	curr = wbdVals;															/* grab the head node									*/
//	thereIsANext = (curr->next!=NOT_AN_ADDRESS);
//>>>>>>> refs/heads/search_work
//
//				//Check Self
//				sprintf(buf, "Check: %s", dir->d_name);
//				log_info(buf);
//			}
//		}
//
//		//Close
//		closedir(d);
//	}


	//Search each subdir -> += result
	//Search dir -> += result
	//Return result

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void wbdPath_setupTest(char *dir)
 *  @brief		setup directories for test operation
 *  @details	check if valid dir and ready for use
 *
 *	@param		[in] (File) dir - directory to setup
 *
 *  @section 	Opens
 *  	Complete routine
 *  	Inject a handful of empty directories with valid syntax
 */
/************************************************************************************************************************************/
void wbdPath_setupTest(char *dir) {

	//Locals
	bool match;																/* strings match										*/

	//Check
	match = (strcmp(dir, util_getTestDir()) == 0);

	//Print to log(dev)
	util_printDirName(dir);

	//Abort if not matching
	if(!match) {
		log_info((char *)"directory input was not found, aborting.");
		abort();															/* only setup for test on TEST_DIR case					*/
	}

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void wbd_storeSearchLen(struct node *list)
 *  @brief		store the length of list
 *  @details	x
 *
 *  @param		[in]	(struct node *) list - list for length evaluation
 *
 *  @note 	this might not be needed
 *
 *  @section 	Opens
 *  	working
 */
/************************************************************************************************************************************/
void wbd_storeSearchLen(struct node *list) {

	//Locals
	int len;

	//Grab length
	len = list_getLength(list);

	//<temp?> store static copy
	listLength = len;

	return;
}


/************************************************************************************************************************************/
/**	@fcn		FILE * wbdPath_getSubDirs(FILE *dir)
 *  @brief		x
 *  @details	x
 *
 *  @param		[in]	(FILE *) dir - x
 *
 *  @return 	(FILE *) x
 */
/************************************************************************************************************************************/
FILE * wbdPath_getSubDirs(FILE *dir) {

	FILE *file = dir;

	return file;
}

