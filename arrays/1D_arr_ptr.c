#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
	int arr[]={2,4,6,9};
	int size=(sizeof(arr)/sizeof(int));

	for(int i=0;i<size;i++)
	{
		printf("%d\n",*(arr+i));
	}



	return 0;
}
