#ifdef __GNUC__

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>


void find_endianess(char* data)
{
	int n=sizeof(int);
	int i=0;

	while(i!=n)
	{
		printf("%4x",data[i]);
		printf("-->%ld\n",&data[i++]);
	}
	printf("\n");
}



int main(int argc, char **argv, char **envp)
{
	int val=0x12345678;
	find_endianess((char *)&val);
	return 0;
}


#endif
