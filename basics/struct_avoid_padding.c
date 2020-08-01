#include <stdio.h>
#include <stdlib.h>

//#pragma pack(1)

typedef struct 
{
	int roll;
	char *name;
	float marks;

}__attribute__((packed)) marksheet;

void construct(void) __attribute__((constructor));

void destruct(void) __attribute__((destructor));

void construct()
{
	printf("Starting the application\n");
}

void destruct()
{
	printf("Ending the application\n");
}

int main()
{
	marksheet rohan;

	printf("%d\n",sizeof(rohan));
	printf("%d\n",sizeof(rohan.roll));
	printf("%ld\n",&(rohan.roll));
	printf("%d\n",sizeof(rohan.name));
	printf("%ld\n",&(rohan.name));
	printf("%d\n",sizeof(rohan.marks));
	printf("%ld\n",&(rohan.marks));

	return 0;
}
