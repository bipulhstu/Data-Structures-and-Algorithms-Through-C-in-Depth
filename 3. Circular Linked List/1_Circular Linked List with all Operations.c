/*
File Name  : Circular Linked list with all Operations.c
Purpose    : To explain doubly linked list
Date       : 24 October 2018
Author     : Bipul Islam
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *createList(struct node *last);
void display(struct node *last);
struct node *insertInEmpty(struct node *last,int data);
struct node *insertInBeginning(struct node *last,int data);
struct node *insertAtEnd(struct node *last,int data);
struct node *insertAfter(struct node *last,int data,int item);
struct node *deleteNode(struct node *last,int data);

main( )
{
	int choice,data,item;
	struct node	*last=NULL;
	
	while(1)
	{
		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Add to empty list\n");
		printf("4.Add at beginning\n");
		printf("5.Add at end\n");
		printf("6.Add after \n");
		printf("7.Delete\n");
		printf("8.Quit\n");
		
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			last=createList(last);
			break;
		 case 2:
			display(last);
			break;
		 case 3:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=insertInEmpty(last,data);
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=insertInBeginning(last,data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			last=insertAtEnd(last,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			last=insertAfter(last,data,item);
			break;
		 case 7:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			last=deleteNode(last,data);
			break;
		 case 8:
		 	exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}/*End of main( )*/

struct node *createList(struct node *last)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	last=NULL;
	if(n==0)
		return last;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	last=insertInEmpty(last,data);
			
	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		last=insertAtEnd(last,data);	
	}
	return last;
}/*End of createList()*/

struct node *insertInEmpty(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	last=tmp;
	last->link=last;
	return last;
}/*End of insertInEmpty( )*/

struct node *insertInBeginning(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	return last;
}/*End of insertInBeginning( )*/

struct node *insertAtEnd(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	last=tmp;
	return last;
}/*End of insertAtEnd( )*/

struct node *insertAfter(struct node *last,int data,int item)
{
	struct node *tmp,*p;
	p=last->link;
	do
	{
		if(p->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			if(p==last)
				last=tmp;
			return last;
		}
		p=p->link;
	}while(p!=last->link);
	printf("%d not present in the list\n",item);
	return last;
}/*End of insertAfter()*/

struct node *deleteNode(struct node *last,int data)
{
	struct node *tmp,*p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return last;
	}
	/*Deletion of only node*/
	if(last->link==last && last->info==data)  
	{
		tmp=last;
		last=NULL;
		free(tmp);
		return last;
	}
	/*Deletion of first node*/
	if(last->link->info==data)    
	{
		tmp=last->link;
		last->link=tmp->link;
		free(tmp);
		return last;
	}
	/*Deletion in between*/
	p=last->link;
	while(p->link!=last)
	{
		if(p->link->info==data)     
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return last;
		}
		p=p->link;
	}
	/*Deletion of last node*/
	if(last->info==data)    
	{
		tmp=last;
		p->link=last->link;
		last=p;
		free(tmp);
		return last;
	}
	printf("Element %d not found\n",data);
	return last;
}/*End of deleteNode( )*/

void display(struct node *last)
{
	struct node *p;
	if(last==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=last->link;
	do 
	{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=last->link);
	printf("\n");
}/*End of display( )*/

