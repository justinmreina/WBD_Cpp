#ifndef WBD_H_
#define WBD_H_


//Project Includes
#include "globals.h"
#include "util.h"
#include "node.h"

//Globals
extern void wbdPath_getAllWbdDirs(Node *wbdVals, char *loc);
extern void wbdPath_setupTest(char *dir);
extern void wbd_storeSearchLen(struct node *list);

#endif /* WBD_H_ */

