#ifdef __GNUC__
#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv, char **envp)
{
	char *data,*endptr;
	printf("Enter the data to convert: ");
	data=(char*)malloc(MAX*sizeof(char));
	
	fgets(data,100,stdin);
	data[(strlen(data)-1)]='\0';
	
	int i,j;
	for(i=0;data[i]!='\0';i++)
	{
		if((data[i]>=48) && (data[i]<=57))
		{
			long val;
			char temp[MAX/2];
			j=0;
			while((data[i]>=48)&&(data[i]<=57) && data[i]!='\0')
			{
				temp[j++]=data[i++];
			}
			temp[j]='\0';
			val=atol(temp);
			printf("%ld->",val);
			for(j=63;j>=0;j--)
			{
				(val&(1<<j))?printf("1"):printf("0");
			}
			printf("\n");
		}

		if(data[i]=='\0') continue;

		printf("%c->%d->",data[i],data[i]);
		for(j=(CHAR_BIT-1);j>=0;j--)
		{
			(data[i]&(1<<j))?printf("1"):printf("0");
		}
		printf("\n");
	}
	
	
	return 0;
}

#endif
