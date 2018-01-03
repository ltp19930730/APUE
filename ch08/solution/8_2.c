#include "apue.h"

static void f1(), f2();

int main()
{
	f1();
	f2();
	_exit(0);
}

static void
f1()
{
	pid_t pid;

	if ((pid = vfork()) < 0)
		err_sys("vfork error");
	/* child and parent both return */
}

static void
f2()
{
	char buf[1000];
	int i;

	for (i = 0; i < sizeof(buf); i++)
		buf[i] = 0;
}

/* 
 * stack frame is wiped out when the automatic variables are modified
 * cause a core dump
 * */
