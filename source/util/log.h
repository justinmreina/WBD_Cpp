#ifndef LOG_H_
#define LOG_H_

//Library Includes
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>

//Project Includes
#include "time.h"
#include "util.h"

//Definitions
#define LOGFILENAME "../wbd.log"
#define SECTION_BUF  "********************"

//Global Routines
extern void log_init(void);
extern void log_open(void);
extern void log_close(void);
extern void log_info(char *str);
extern void log_insertSection(char *name);

//Local Routines
void log_insertHeader(void);

#endif /* LOG_H_ */

