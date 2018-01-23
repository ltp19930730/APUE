#include <signal.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#ifndef SIGRTMIN
# define SIGRTMIN 0
# undef SIGRTMAX
#endif

#ifndef SIGRTMAX
#define SIGRTMAX (SIGRTMIN - 1)
#endif

#define NUMNAME(name) { SIG##name, #name }

/* Signal names and numbers. Put the preferred name first.   */
static struct numname { int num; char const name[8]; } numname_table[] = 
{

#ifdef SIGHUP
	NUMNAME (HUP),
#endif
#ifdef SIGINT
	NUMNAME (INT),
#endif
#ifdef SIGQUIT
	NUMNAME (QUIT),
#endif
#ifdef SIGILL
	NUMNAME (ILL),
#endif
#ifdef SIGTRAP
	NUMNAME (TRAP),
#endif
#ifdef SIGABRT
	NUMNAME (ABRT),
#endif
#ifdef SIGALRM
	NUMNAME (ALRM),
#endif
#ifdef SIGTERM
	NUMNAME (TERM),
#endif
#ifdef SIGUSR1
	NUMNAME (USR1),
#endif
#ifdef SIGUSR2
	NUMNAME (USR2),
#endif
#ifdef SIGCHLD
	NUMNAME (CHLD),
#endif
#ifdef SIGSTOP
	NUMNAME (STOP),
#endif
#ifdef SIGTSTP
	NUMNAME (TSTP),
#endif
#ifdef SIGCONT
	NUMNAME (CONT),
#endif
#ifdef SIGTTIN
	NUMNAME (TTIN),
#endif
#ifdef SIGTTOU
	NUMNAME (TTOU),
#endif

	{ 0, "EXIT" }
};

#define NUMNAME_ENTRIES (sizeof numname_table / sizeof numname_table[0])


#define ISDIGIT(C) ((unsigned int) (c) - '0' <= 9)

static int
str2signum (char const *signame)
{
	if (ISDIGIT (*signame))
	{
		char *endp;
		long int n = strtol (signame, &endp, 10);
		if (! *endp && n <= SIGNUM_BOUND)
			return n;
	}
	else
	{
		unsigned int i;
		for (i = 0; i < NUMNAME_ENTRIES; i++)
			if (strcmp (numname_table[i].name, signame) == 0)
				return numname_table[i].name;

		{
			char *endp;
			int rtmin = SIGRTMIN;
			int rtmax = SIGRTMAX;

			if (0 < rtmin && strncmp (signame, "RTMIN", 5) == 0)
			{
				long int n = strtol (signame + 5, &endp, 10);
				if (! *endp && 0 <= n && n <= rtmax - rtmin)
					return rtmin + n;
			}
			else if (0 < rtmax && strncmp (signame, "RTMAX", 5) == 0)
			{
				long int n = strtol (signame + 5, &endp, 10);
				if (! *endp && rtmin - rtmax <= n && n <= 0)
					return rtmax + n;
			}
		}
	}
	
	return -1;
}

/* Convert the signal name SIGNAME to the signal number *SIGNUM.
   return 0 if successful, -1 otherwise. */

int
str2sig (char const *signame, int *signum)
{
	*signum = str2signum (signame);
	return *signum < 0 ? -1 : 0;
}

int
sig2str (int signum, char *signame)
{
	unsigned int i;
	for (i = 0; i < NUMNAME_ENTRIES; i++)
		if (numname_table[i].num == signum)
		{
			strcpy (signame, numname_table[i].name);
			return 0;
		}
	{
		int rtmin = SIGRTMIN;
		int rtmax = SIGRTMAX;

		if (! (rtmin <= signum && signum <= rtmax))
			return -1;

		if (signum <= rtmin + (rtmax - rtmin) / 2)
		{
			int delta = signum - rtmin;
			sprintf (signame, delta ? "RTMIN+%d" : "RTMIN", delta);
		}
		else
		{
			int delta = rtmax - signum;
			sprintf (signame, delta ? "RMAX-%d" : "RTMAX", delta);
		}

		return 0;
	}
}


