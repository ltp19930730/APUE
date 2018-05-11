#ifndef APUE_H_
#define APUE_H_
#include "apue.h"
#endif

#include <errno.h>

#define CS_OPEN "/tmp/opend.socket" /* server's well-know name */
#define CL_OPEN "open"
int csopen(char *, int);
