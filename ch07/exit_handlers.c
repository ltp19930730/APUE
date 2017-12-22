#include "apue.h"

static void my_exit(void);
static int i = 0;

int main()
{
 /* no limits any more for max register handler */
    for (; i < 100; i++){
        if (atexit(my_exit) != 0){
            err_sys("can't register msy_exit in %d anymore.",i);
        }
    }

	printf("main is done \n");
    return 0;
}

static void my_exit()
{
    printf("%d exit handler\n",i);
	i--;
}
