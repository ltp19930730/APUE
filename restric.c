#include <stdio.h>

int foo(int *a, int *b)
{
	*a = 5;
	*b = 6;
	return *a + *b;
}

int rfoo(int *__restrict a, int *__restrict b)
{
	*a = 5;
	*b = 6;
	return *a + *b;
}

int main()
{
	int i = 0;
	int *a = &i;
	int *b = &i;
	printf("without restrict: %d\n", foo(a,b));
	printf("with restrict: %d\n", rfoo(a,b));
	return 0;
}
