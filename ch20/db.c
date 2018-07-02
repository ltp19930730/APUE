#include "apue.h"
#include "apue_db.h"
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/uio.h>

/* 
 * Internal index file constants.
 * These are used to construct records in the 
 * index file and data file.
 */
#define IDXLEN_SZ     4   /* index record length (ACII chars) */
#define SEP         ':'   /* separator char in index record */
#define SPACE       ' '   /* space character */
#define NEWLINE     '\n'  /* newline character */

/* 
 * The following definitions are for hash chains and free
 * list char in the index file.
 */
#define PTR_SZ        7    /* size of ptr field in hash chain */
#define PTR_MAX 9999999    /* max file offset = 10**PTR_SZ - 1 */
#define NHASH_DEF   137    /* default hash table size */
#define FREE_OFF      0    /* free list offset in index file */
#define HASH_OFF PTR_SZ    /* hash table offset in index file */

typedef unsigned long DBHASH; /* hash value */
typedef unsigned long COUNT;  /* unsigned counter */

/*
 * Library's private representation of the database.
 */
typedef struct {
    int idxfd;    /* fd for index file */
    int datfd;    /* fd for the data file */
    char *idxbuf; /* malloc'ed buffer for index record */
    char *datbuf; /* malloc'ed buffer for data record */
    char *name;   /* name db was opened under */
    off_t idxoff; /* offset in index file of index record */
                  /* key is at (idxoff + PTR_SZ + IDXLEN_SZ) */
    size_t idxlen;/* length of index record */
                  /* excludes IDXLEN_SZ bytes at front of record */
                  /* include newline at end of index record */
