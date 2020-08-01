#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#pragma pack(1)

typedef struct stud{
	int roll;
	char *name;
	struct stud *next;
}__attribute__((packed)) student;


void insert(student **);
void view(student *);



int main()
{
	student *head=NULL;
	for(int i=0;i<=5;i++) insert(&head);
	view(head);
	return 0;	
}


void insert(student **head)
{
	student *temp=NULL;
	temp=(student *)malloc(sizeof(student));
	printf("Enter roll: ");
	scanf("%d",&(temp->roll));
	temp->name=(char *)malloc(sizeof(char)*20);
	printf("Enter the name: ");
	__fpurge(stdin);
	fgets(temp->name,20,stdin);
	temp->next=NULL;

	if(*head==NULL)
	{
		*head=temp;
		return;
	}
	
	student *iter=NULL;
	iter=*head;
	while(iter->next!=NULL)
	{
		iter=iter->next;
	}
	iter->next=temp;
}


void view(student *head)
{
	if(head==NULL)
	{
		printf("Linked list empty\n");
		return;
	}

	student *temp=head;
	while(temp!=NULL)
	{
		printf("roll= %d, name= %s",temp->roll, temp->name);
		temp=temp->next;
	}
}
