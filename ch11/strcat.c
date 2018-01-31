#include <stdio.h>
#include <stdlib.h>

typedef struct abc {
	char *a;
	char *b;
}abc;

static abc table[] = {
	{"abc", "1"
#ifdef ABC
	"test" 
#endif
	},

	{"abd",""
	"test1" }
};


int 
main(void)
{
	int i;

	for (i = 0; i < 2; i++){
		printf("%s  %s\n",table[i].a,table[i].b);
	}
	exit(0);
}

