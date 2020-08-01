#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#pragma pack(1)

typedef union
{
	int roll;
	char* name;
	float marks;
	char hw[20];

}__attribute__((packed)) report;


int main()
{
	report prs;
	prs.name=(char *)malloc(6*sizeof(char));
	strncpy(prs.name,"ROHAN",5);
	puts(prs.name);


	printf("%d\n",sizeof(prs));
	printf("address of roll = %lx\n",&(prs.roll));
	printf("address of name = %lx\n",&(prs.name));
	printf("address of marks = %lx\n",&(prs.marks));
	printf("address of hw = %lx\n",(prs.hw));
}
