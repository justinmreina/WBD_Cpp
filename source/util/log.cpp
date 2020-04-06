/************************************************************************************************************************************/
/** @file		log.c
 * 	@brief		log file use for application
 * 	@details	x
 *
 * 	@section	Opens
 *		none listed
 *
 *	@section 	Deferred Opens
 *		logs moved to archived are given a unique name and do not overwrite existing contents
 *
 * 	@section	Legal Disclaimer
 * 			2020© Year Justin Reina, All rights reserved. All contents of this source file and/or any other related source
 *			files are the explicit property of Justin Reina. Do not distribute. Do not copy.
 */
/************************************************************************************************************************************/
#include "log.h"

//Globals
FILE *logFile;
//!!!time_t timer;


/************************************************************************************************************************************/
/**	@fcn		void printMe(char *buf)
 *  @brief		write to log file
 *  @details	writes to log and to console with appropriate formats
 *
 *  @param 		[in] (char *) buf - string location to write to file
 *
 *  @assum		logFile is initialized
 */
/************************************************************************************************************************************/
void log_write(char *buf) {

	//Write to log
	fprintf(logFile, buf);
	fprintf(logFile, "\n");

	//Print to console
	puts(buf);

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void log_init(void)
 *  @brief		acquire a log file, from existing if found else generate new
 *  @details	a+ (create + append) option will allow appending which is useful in a log file
 *
 *  @section 	Opens
 *  	Print time stamp to entry line
 *  	handle failed log with notice and termination
 */
/************************************************************************************************************************************/
void log_init(void) {

	//Init
	logFile = fopen(LOGFILENAME, "a+");										/* create log file										*/
//!!!	timer = time(NULL);

	//Load Log
	log_insertHeader();
	log_info("Log file was created");

	//Safety
	if(logFile==NULL) {
		for(;;);
	}

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void log_open(void)
 *  @brief		open existing log, or create if not found
 *  @details	x
 *
 *	@section 	Opens
 *		implement routine
 *		consider moving previous log to archives
 */
/************************************************************************************************************************************/
void log_open(void) {

	for(;;);

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void log_close(void)
 *  @brief		x
 *  @details	x
 */
/************************************************************************************************************************************/
void log_close(void) {

	fclose(logFile);

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void log_info(char *str)
 *  @brief		print a string to the console
 *  @details	x
 *
 *  @param		[in]	(char *) str - string to print to console
 *
 *  @section 	Opens
 *  	print time value
 *  	handle long strings
 *
 *  @assum		str EOS terminated
 */
/************************************************************************************************************************************/
void log_info(char *str) {

	//Locals
    struct tm* tm_info;
	char buf2[200];

	//Timestamp
 //!!!   tm_info = localtime(&timer);

	//Gen
//!!!    tm_info = localtime(&timer);
    sprintf(buf2, "(%02d:%02d:%d) %s", (tm_info->tm_hour), tm_info->tm_min, (tm_info->tm_sec), str);

	//Print
	log_write(buf2);

	return;
}


/************************************************************************************************************************************/
/**	@fcn		log_insertHeader(void)
 *  @brief		insert header to log file
 *  @details	x
 *
 *  @section 	Opens
 *  	cleanup syntax & form
 *  	don't add upper line if new file
 *  	upper line never goes to console
 *  	add actual date
 *
 *  @assum		log is initialized
 */
/************************************************************************************************************************************/
void log_insertHeader(void) {

	//Locals
    struct tm* tm_info;
	char buf2[26];
	char *lines[4] = {
			"WorkByDay Activity Record",
			"Version: 1.0",
			"Author: Justin Reina",
			"Published: "};   												/* March 21st, 2020\n\n",								*/

	//empty file?
	if(util_getFileSize(logFile)!=0) {
		fprintf(logFile, "\n\n//***********************************************************************************************//\n");
	}

	for(int i=0; i<3; i++) {
		log_write(lines[i]);
	}

//[4]?!!!
	fprintf(logFile, lines[3]);												/* to log file											*/
	puts(lines[3]);															/* put to console										*/


	//Add date & EOS
//!!!    tm_info = localtime(&timer);
//@todo 	is &[0] needed?
    sprintf(&buf2[0], "%02d/%02d/%d\n", (tm_info->tm_mon+1), tm_info->tm_mday, (1900+tm_info->tm_year));
    log_write(buf2);

	return;
}


/************************************************************************************************************************************/
/**	@fcn		void log_insertSection(char *name)
 *  @brief		add a section header to file
 *  @details	x
 *
 *  @param		[in]	(char *) str - string to print to console
 *
 *  @section 	Opens
 *  	print to uppercase
 *		print variable number of asterisks by name length
 *  @assum		log is initialized
 */
/************************************************************************************************************************************/
void log_insertSection(char *name) {

	//Locals
	char *buf;
	int len;

	//Init
	len = 3 + 2 + strlen(SECTION_BUF) + strlen(name) + strlen(SECTION_BUF) + 2;
//!!!	buf = malloc(len);

	sprintf(buf, "\n\n//%s %s %s\n", SECTION_BUF, name, SECTION_BUF);
	log_write(buf);

	return;
}

