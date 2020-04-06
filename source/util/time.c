/************************************************************************************************************************************/
/** @file		time.c
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
#include "time.h"


/************************************************************************************************************************************/
/**	@fcn		void time_getTime(Time *loc)
 *  @brief		get current time value
 *  @details	x
 *
 *  @param		[in]	(Time *) loc - location to store value
 */
/************************************************************************************************************************************/
void time_getTime(Time *loc) {

	//Locals
	time_t t;
	Time tm;

	//Grab time value
	t = time(NULL);
	tm = *localtime(&t);

	//Copy contents
	memcpy(&loc, &tm, sizeof(Time));

	return;
}


/************************************************************************************************************************************/
/**	@fcn		long time_getClock(void)
 *  @brief		get current clock value in ticks
 *  @details	x
 *
 *  @return 	(long) clock value in seconds
 */
/************************************************************************************************************************************/
long time_getClock(void) {
	return clock();
}


/************************************************************************************************************************************/
/**	@fcn		long time_getClockMs(void)
 *  @brief		x
 *  @details	x
 */
/************************************************************************************************************************************/
long time_getClockMs(void) {

	//Locals
	long c;
	long ms;

	//Crab time
	c = clock();

	//Calc ms
	ms = ((double)(c) / CLOCKS_PER_SEC) * 1000 ;

	return ms;
}


/************************************************************************************************************************************/
/**	@fcn		void print_time(void)
 *  @brief		print example time to console
 *  @details	x
 */
/************************************************************************************************************************************/
void print_time(void) {

	//Locals
	Time tm;

	//Grab time
	time_getTime(&tm);

	printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	return;
}



//@todo 	header
void delay_s(int time_s) {

	//Converting time into milli_seconds
	int milli_seconds = 1000 * time_s;

	//Storing start time
	clock_t start_time = clock();

	//looping till required time is not achieved
	while (clock() < start_time + milli_seconds) {};

	return;
}
