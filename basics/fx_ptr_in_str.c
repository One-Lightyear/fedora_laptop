#include <stdio.h>
#include <stdlib.h>

struct student
{
	int roll;
	int marks;

	void (*foo)(int x);
	
};

void callback(int x)
{
	printf("%d\n",x);
	return;
}


int main()
{
	struct student *rohan;
	rohan=(struct student *)malloc(sizeof(struct student));

	rohan->roll=2;
	rohan->marks=99;
	rohan->foo=callback;

	rohan->foo(3);

	void fun()
	{
		printf("OK\n");
	}
	fun();


	return 0;
}
