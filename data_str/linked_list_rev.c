#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#pragma pack(1)

typedef struct stud{
	int roll;
	struct stud *next;
}__attribute__((packed)) student;


void insert(student **);
void view(student *);
void reverse(student **,student *);


int main()
{
	student *head=NULL;
	for(int i=0;i<=3;i++) insert(&head);
	view(head);
	printf("After reversal: \n");
	reverse(&head,NULL);
	view(head);
	return 0;	
}


void insert(student **head)
{
	student *temp=NULL;
	temp=(student *)malloc(sizeof(student));
	printf("Enter roll: ");
	scanf("%d",&(temp->roll));
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
		printf("roll= %d\n",temp->roll);
		temp=temp->next;
	}
}



void reverse(student **head, student *prev)
{
	static student *temp;
	
	temp=*head;
	if(((*head)->next)==NULL)
	{
		(*head)->next=prev;
		return;
	}

	reverse(&((*head)->next),*head);
	(*head)->next=prev;

	if((*head)->next==NULL)
	{
		*head=temp;
	}
}
