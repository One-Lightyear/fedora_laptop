/*
 *
 * In C, functions are global by default & can be accessed from any file
 * Unlike global functions in C, access to static functions is restricted to the file where they are declared. 
 * Therefore, when we want to restrict access to functions, we make them static. 
 * Another reason for making functions static can be reuse of the same function name in other files.
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>

static void foo();	//Not accessible from foo being static

int main()
{
	foo();
	return 0;
}
