#ifndef TIME_H_
#define TIME_H_

//Library Includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>

//Definitions
#define Time struct tm														/* cleaner name for use									*/

//Globals
extern void time_getTime(Time *loc);
extern void print_time(void);
extern long time_getClock(void);
extern long time_getClockMs(void);
extern void delay_s(int time_s);

#endif /* TIME_H_ */

