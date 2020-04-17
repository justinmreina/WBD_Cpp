/************************************************************************************************************************************/
/** @file		util.c
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
#include "util.h"


/************************************************************************************************************************************/
/**	@fcn		void util_printDirName(char *dir)
 *  @brief		x
 *  @details	x
 *
 *	@param		[in] (File) dir - directory to print name to log
 *
 *  @section 	Opens
 *  	move me
 */
/************************************************************************************************************************************/
void util_printDirName(char *dir) {

	//Locals
	char buf[100];

	//Init
	memset(buf, '\0', sizeof(buf));

	//Load message
	sprintf(buf, "dir: %s", dir);

	//Print
	log_info(buf);

	return;
}


/************************************************************************************************************************************/
/**	@fcn		int util_getFileSize(FILE *file)
 *  @brief		x
 *  @details	x
 *
 *  @param		[in]	(FILE *) file - path to file
 *  @return		(int) file size in bytes
 */
/************************************************************************************************************************************/
int util_getFileSize(FILE *file) {

	//Locals
	int size;

	//check size
	fseek(file, 0, SEEK_END);

	//store
	size = ftell(file);

	return size;
}


/************************************************************************************************************************************/
/**	@fcn		bool util_isWorkPC(void)
 *  @brief		check if filesystem form matches the work pc
 *  @details	used as binary switch between home/work at this time (Home: "C:\Documents\" & Work: "D:\Documents\")
 *
 *  @return		(bool) is work pc?
 */
/************************************************************************************************************************************/
bool util_isWorkPC(void) {

	//Locals
	DIR *dir;																/* directory path for inspection						*/
	bool isWorkPC;															/* was found as work pc path?							*/

	//Try to open path
	dir = opendir("D:\\Documents");

	//Was found?
	isWorkPC = (dir != NULL);

	return isWorkPC;
}


/************************************************************************************************************************************/
/**	@fcn		char * util_getTestDir(void)
 *  @brief		find which directory to perform the WBD test on
 *  @details	x
 *
 *  @return		(char *) directory to perform the test
 *
 *  @section 	Opens
 *  	Confirm operation on WorkPC (not tested)
 */
/************************************************************************************************************************************/
char * util_getTestDir(void) {

	//Locals
	bool isWorkPC;
	bool isDemo;

	//Get Config
#ifdef USES_DEMO_DIR														/* simple preprocessor selection						*/
	isDemo = true;
#else
	isDemo = false;
#endif
	isWorkPC = util_isWorkPC();												/* check which form of filesystem in use				*/

	//Load (cleaner presentation for source here)
	if( isWorkPC *  isDemo) { return WORK_DEMO_PATH; }
	if( isWorkPC * !isDemo) { return WORK_TEST_PATH; }
	if(!isWorkPC *  isDemo) { return HOME_DEMO_PATH; }
	/*(!isWorkPC * !isDemo)*/ return HOME_TEST_PATH;
}

