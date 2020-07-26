#include <stdio.h>
#include <stdlib.h>

void fun()
{
	char *p="ROHAN";
	printf("%p\n",p);
}


int main()
{
	char *p="ROHAN";
	printf("%p\n",p);
	fun();
	return 0;
}
