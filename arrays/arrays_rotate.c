#include <stdio.h>
#include <stdlib.h>


int recn(int *arr,int init, int end)
{
	int temp=arr[end];
	for(int i=end;i>=(init+1);i--)
	{
		arr[i]=arr[i-1];
	}
	arr[init]=temp;
}




int main()
{
	int arr[5]={1,2,3,4,5};
	
	int i;
	

	recn(arr,1,3);
	recn(arr,1,3);


	for(int i=0;i<=4;i++)
	{
		printf("%d ",arr[i]);
	}

	printf("\n");
	
	return 0;
}
