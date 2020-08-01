#include <stdio.h>
#include <stdlib.h>


unsigned long int fact(int no)
{
	if(no==1)
		return no;
	no*=fact(no-1);
}




int main()
{
	int no=1;
	printf("Enter the number: ");
	scanf("%d",&no);
	printf("%lu\n", fact(no));
}
