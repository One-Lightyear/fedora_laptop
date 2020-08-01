#include <stdio.h>

static void foo()	//not accessible from 1_main.c being static
{
	printf("HELLO\n");
}
