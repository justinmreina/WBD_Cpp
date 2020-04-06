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

