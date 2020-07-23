#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
	int i=0,j=0;
	int arr[][4]=
	{
		{2,4,6,9},
		{1,7,11,8},
	};

	for(i=0;i<2;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}



	return 0;
}
