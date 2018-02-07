#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define THRNUM		4

static pthread_mutex_t mut_num = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond_num = PTHREAD_COND_INITIALIZER;
static int num = 0;

static int next(int a)
{
	if (a+1 == THRNUM)
		return 0;
	return a+1;
}

static void *thr_func(void *p)
{
	int n = (int) p;
	int ch = n + 'a';

	while(1)
	{
		pthread_mutex_lock(&mut_num);
		while(num != n)
		{
			pthread_cond_wait(&cond_num, &mut_num);
		}
		write(1, &ch, 1);
		num = next(num);

		if (n == (THRNUM - 1)){
			printf("\n");
			sleep(1);
		}
		pthread_cond_broadcast(&cond_num);
		pthread_mutex_unlock(&mut_num);
	}
	pthread_exit(NULL);
}

int main()
{
	int i,err;
	pthread_t tid[THRNUM];

	for(i = 0; i < THRNUM; i++)
	{
		err = pthread_create(tid+i, NULL, thr_func, (void *)i);
		if (err)
		{
			fprintf(stderr,"pthread_create():%s\n", strerror(err));
			exit(1);
		}
	}

	alarm(5);

	for (i = 0; i < THRNUM; i++)
		pthread_join(tid[i], NULL);

	exit(0);
}
