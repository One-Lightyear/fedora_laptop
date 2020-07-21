#ifdef __GNUC__

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>


int main(int argc, char **argv, char **envp)
{
	char i=atoi(argv[1]);
	int j=0;
	
	printf("The binary of i = %d is : ",i);


	for(j=7;j>=0;j--)
	{
		if((i&(1<<j))==0)
			printf("0");
		else
			printf("1");
	}
	printf("\n");
	return 0;
}

#endif
