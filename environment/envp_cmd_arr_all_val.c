/* 
 * Type 1
 *
 * In this program, we will derive all the values of the environment using the
 * command line parameter -----> envp[]
 *
 */

#ifdef __GNUC__

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


int main(int argc, char **argv, char **envp)
{
	uint32_t i=0;
	while(envp[i]!=NULL)
	{
		puts(envp[i]);
		i++;
	}
}


#endif
