#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[5]={11,2,3,9,7};
	int temp[5],val=0;

	int sorted=1;
	for(int i=1;i<=4;i++)
	{
		for(int j=0;j<sorted;j++)
		{
			
			if(arr[i]<arr[j])
			{
				sorted++;
				for(int k=j;k<i;k++)
				{
					temp[val++]=arr[k];
				}
				
				arr[j]=arr[i];
				int temp2=j+1;

				for(int k=0;k<val;k++)
				{
					arr[temp2++]=temp[k];
				}
				val=0;
				break;
			}
		}
	}

	for(int i=0;i<5;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}
