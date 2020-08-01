#include <stdio.h>
#include <stdlib.h>

typedef union{
	int a;
	double b;
	char c;
}ex;

int main()
{
	ex name;
	
	name.a=10;	
	printf("%d\n",name.a);

	name.b=201991919191.66;
	printf("%lf\n",name.b);

	name.c='A';
	printf("%c\n",name.c);

	return 0;
}
