#ifndef UTIL_H_
#define UTIL_H_

//Library Includes
#include <string.h>

//Project Includes
#include "globals.h"
#include "node.h"
#include "wbd.h"

//Global Routines
extern void util_printDirName(char *dir);
extern int util_getFileSize(FILE *file);
extern char * util_getTestDir(void);

//Definitions
#define WORK_DEMO_PATH ((char *)"D:\\Documents\\MyWorkspaces\\Eclipse\\CDT\\WBD_Cpp\\data\\TestDirs")
#define WORK_TEST_PATH ((char *)"D:\\")
#define HOME_DEMO_PATH ((char *)"C:\\Documents\\MyWorkspaces\\Eclipse\\CDT\\WBD_Cpp\\data\\TestDirs")
#define HOME_TEST_PATH ((char *)"C:\\")

#endif /* UTIL_H_ */

