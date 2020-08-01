#include <stdio.h>
#include <stdlib.h>


typedef struct {
	unsigned int roll:3;			// 3 bits assigned
	unsigned int marks:8;			// 8 bits assigned
	
	char data:3;
//	float no:3	//not supported
}class;


int main()
{
	class stud;
	
	printf("%d\n",sizeof(stud));
	
	stud.roll=16;			//overflow
	printf("%d\n",(stud.roll));
	stud.roll=7;
	printf("%d\n",(stud.roll));

	stud.marks=257;			//overflow
	printf("%d\n",(stud.marks));
	stud.marks=254;
	printf("%d\n",(stud.marks));


}
