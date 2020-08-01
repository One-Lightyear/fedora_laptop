#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct node{
	struct node *left;
	int roll;
//	char *name;
	struct node *right;
}__attribute__((packed)) student;



void insert(student **);
void in_order_traversal(student *);
void pre_order_traversal(student *);
void post_order_traversal(student *);



int main()
{
	student *head=NULL;
	for(int i=1;i<=6;i++) insert(&head);
	in_order_traversal(head);
	printf("\n");
	pre_order_traversal(head);
	printf("\n");
	post_order_traversal(head);
	printf("\n");
}



void insert(student **head)
{
	student *temp=NULL;
	temp=(student *)malloc(sizeof(student));

	printf("Enter roll: ");
	scanf("%d",&(temp->roll));

/*	temp->name=(char *)malloc(sizeof(char)*20);
	printf("Enter the name: ");
	__fpurge(stdin);
	fgets(temp->name,20,stdin);
*/

	temp->left=NULL;
	temp->right=NULL;

	if(*head==NULL)
	{
		*head=temp;
		return;
	}
	
	student *iter=NULL, *temp2=NULL;
	iter=*head;

	while(iter!=NULL)
	{
		temp2=iter;

		if((iter->roll)==(temp->roll))
		{
			printf("Roll already exists\n");
			return;
		}

		if((iter->roll)<(temp->roll))
			iter=iter->right;
		else
			iter=iter->left;
	}

	if((temp2->roll)<(temp->roll))
	{
		temp2->right=temp;
	}
	else
		temp2->left=temp;

}


void in_order_traversal(student *head)
{
	if(head==NULL)
	{
		return;
	}

	in_order_traversal(head->left);
	printf("%d\t",head->roll);
	in_order_traversal(head->right);
}



void pre_order_traversal(student *head)
{
	if(head==NULL)
	{
		return;
	}

	printf("%d\t",head->roll);
	pre_order_traversal(head->left);
	pre_order_traversal(head->right);
}


void post_order_traversal(student *head)
{
	if(head==NULL)
	{
		return;
	}

	post_order_traversal(head->left);
	post_order_traversal(head->right);
	printf("%d\t",head->roll);
}
