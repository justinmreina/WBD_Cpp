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

	//Load Log
	log_insertHeader();
	log_info((char *)"Log file was created");

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
	time_t rawtime;
	int hr, min, sec;
	bool isPm;
	struct tm *tm_info;
	char buf2[200];
	char *mer;

	//Grab time
	time(&rawtime);
	tm_info = localtime(&rawtime);
	hr = (tm_info->tm_hour);
	min = tm_info->tm_min;
	sec = (tm_info->tm_sec);

	//Parse time values
	isPm = (hr > 11);
	if(hr > 12) {
		hr -= 12;
	}

	mer = (isPm) ? (char *)"PM":(char *)"AM";

    //Load Date Line
    sprintf(&buf2[0], "%02d:%02d:%02d %s: %s", hr, min, sec, mer, str);

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
	time_t rawtime;
	struct tm *tm_info;
    int m, d, y;
	char buf2[26];
	const char *lines[4] = {
							"WorkByDay Activity Record",
							"Version: 1.0",
							"Author: Justin Reina",
							"Published: "};

	//empty file?
	if(util_getFileSize(logFile)!=0) {
		fprintf(logFile, "\n\n//***********************************************************************************************//\n");
	}

	for(int i=0; i<3; i++) {
		log_write((char *)lines[i]);
	}

	//Grab time
	time(&rawtime);
	tm_info = localtime(&rawtime);
    m = (tm_info->tm_mon+1);
    d = tm_info->tm_mday;
    y = (1900+tm_info->tm_year);

    //Load Date Line
    sprintf(&buf2[0], "%s: %02d/%02d/%d\n", lines[3], m, d, y);				/* load last line										*/
	fprintf(logFile, buf2);													/* to log file											*/
	puts(buf2);																/* put to console										*/

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
	buf = (char *)malloc(len);

	sprintf(buf, "\n\n//%s %s %s\n", SECTION_BUF, name, SECTION_BUF);
	log_write(buf);

	return;
}

