#include <stdio.h>
#include <stdlib.h>


int rotn(int *arr,int init, int end)
{
        for(int i=end;i>=(init+1);i--)
        {
                arr[i]=arr[i-1];
        }
}



void prin (int *arr)
{
	for(int i=0;i<5;i++)
	{
		printf("%d\n",arr[i]);
	}
}


int main()
{
	int arr[5]={11,17,1,9,2};
	int temp[5],val=0;

	int sorted=1;
	for(int i=1;i<=4;i++)
	{
		for(int j=0;j<sorted;j++)
		{
			
			if(arr[i]<arr[j])
			{
				sorted++;
				int temp=arr[i];

				rotn(arr,j,i);
				
				arr[j]=temp;
				
				break;
			}
		}
	}
	
	prin(arr);

	return 0;
}
