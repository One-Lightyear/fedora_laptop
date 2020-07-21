#pragma redefine_extname oldname newname

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>

char unused_var __attribute__((unused));	//characterise unused variable & wont throw warning


void construct (void) __attribute__ ((constructor));	//executes before main
void destruct (void) __attribute__ ((destructor));	//executes after main

int main()
{
	printf("main execution\n");

	printf("%d",__GNUC_MINOR__);



#ifdef __GNUC__ 
	printf("GCC____________\n");
#endif

	return 0;
}

void destruct (void)
{
	printf ("destructor execution\n");
}


void construct (void)
{
	printf("constructor execution\n");
}
