#include <stdio.h>

/// checking if the intersecting element already exist 
int intersect[5];
int size=0;
void fun_intersect(int no)
{
  intersect[size]=no;
  size++;
}

///
int printIntersection(int arr1[],int arr2[],int arr1_size,int arr2_size)
{
  int i=0,j=0;
  for (i=0;i<arr1_size;i++)
  {
    for (j=0;j<=arr2_size;j++)
    {
        if(arr1[i]==arr2[j])
        {
          fun_intersect(arr1[i]);
	  break;
        }
    }
  }

  printf("Intersection elements: \n");
  for(i=0;i<size;i++)
  {
    printf("%d\n",intersect[i]);
  }

}

int main(void)
{
	int arr1[] = {1, 2, 2, 4, 5, 6};
	int arr2[] = {2, 2, 3, 5, 7};

  	printIntersection(arr1,arr2,6,5);
}
