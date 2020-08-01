#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//#pragma pack(1)

struct s1 {
  int a;        //4 bytes
  char b;       //1 byte +3 byte pad
  size_t *d;    //8 bytes
  short c;      //2 byte +6 byte pad since length of word is equal to the lenngth of the address bus i.e. 8 bytes
  char *dd;     //8 byte
};


struct s2 {
  int a;        
  char b;       //pad of 1 byte here
  short c;      
  char *dd;
  size_t *d;
};



int main()
{
	struct s1'\302'f1;
	struct s2 f2;

	printf("s1 size -> %d\n\n",sizeof(f1));
	printf("s1->int size -> %d\n",sizeof(f1.a));
	printf("s1->int->add -> %ld\n\n",&(f1.a));
	printf("s1->char size -> %d\n",sizeof(f1.b));
	printf("s1->char->add -> %ld\n\n",&(f1.b));
	printf("s1->size_t_ptr size -> %d\n",sizeof(f1.d));
	printf("s1->size_t_ptr->add -> %ld\n\n",&(f1.d));
	printf("s1->short size -> %d\n",sizeof(f1.c));
	printf("s1->short->add -> %ld\n\n",&(f1.c));
	printf("s1->char_ptr size -> %d\n",sizeof(f1.dd));
	printf("s1->char_ptr->add -> %ld\n\n",&(f1.dd));

printf("_____________________________________________________________________\n\n");

	printf("s2 size -> %d\n\n",sizeof(f2));
	printf("s2->int size -> %d\n",sizeof(f2.a));
	printf("s2->int->add -> %ld\n\n",&(f2.a));
	printf("s2->char size -> %d\n",sizeof(f2.b));
	printf("s2->char->add -> %ld\n\n",&(f2.b));
	printf("s2->short size -> %d\n",sizeof(f2.c));
	printf("s2->short->add -> %ld\n\n",&(f2.c));
	printf("s2->char_ptr size -> %d\n",sizeof(f2.dd));
	printf("s2->char_ptr->add -> %ld\n\n",&(f2.dd));
	printf("s2->size_t_ptr size -> %d\n",sizeof(f2.d));
	printf("s2->size_t_ptr->add -> %ld\n\n",&(f2.d));

}
