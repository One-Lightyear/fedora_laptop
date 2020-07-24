#ifdef __GNUC__

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char **argv, char **envp)
{	
	if(argc!=2)
	{
		printf("Wrong number of arguements\n");
		exit(EXIT_FAILURE);
	}

	int i=atoi(argv[1]);
	int j=0;
	
	printf("The binary of i = %d is : ",i);


	for(j=((sizeof(int)*CHAR_BIT)-1);j>=0;j--)
	{
		(i&(1<<j))?printf("1"):printf("0");
	}
	printf("\n");
	return 0;
}

#endif
