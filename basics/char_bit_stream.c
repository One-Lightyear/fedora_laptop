#ifdef __GNUC__
#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
	char *data;
	printf("Enter the data to convert: ");
	data=(char*)malloc(MAX*sizeof(char));
	
	fgets(data,100,stdin);
	data[(strlen(data)-1)]='\0';
	
	int i,j;
	for(i=0;data[i]!='\0';i++)
	{
		for(j=(CHAR_BIT-1);j>=0;j--)
		{
			(data[i]&(1<<j))?printf("1"):printf("0");
		}
	}
	
	
	return 0;
}

#endif
