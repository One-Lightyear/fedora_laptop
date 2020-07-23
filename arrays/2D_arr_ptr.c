#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
	uint32_t i=0,j=0;
	int32_t arr[][4]=
	{
		{2,5,6,9},
		{1,7,11,8},
	};

	uint32_t size_col=((sizeof(*arr))/(sizeof(int)));
	
	uint32_t size_row=(((sizeof(arr)/(sizeof(int))))/size_col);

	for(i=0;i<size_row;i++)
	{
		for(j=0;j<size_col;j++)
		{
			printf("%d\t",(*(*(arr+i)+j)));
		}
		printf("\n");
	}

	return 0;
}
