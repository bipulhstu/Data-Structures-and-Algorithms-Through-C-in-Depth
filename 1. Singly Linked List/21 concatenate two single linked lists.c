/*To show concatenation in single linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};
struct node *createList(struct node *);
struct node *concatenate( struct node *start1,struct node *start2);
struct node *insertInBeginning(struct node *start, int data);
struct node *insertAtEnd(struct node *start,int data);
void display(struct node *start);

main()
{
	struct node *start1=NULL,*start2=NULL;
	start1=createList(start1);
	start2=createList(start2);
	printf("First list is  : ");
	display(start1);
	printf("Second list is  : ");
	display(start2);
    start1=concatenate(start1, start2);
	printf("Concatenated list is  : ");
	display(start1);
}/*End of main()*/

struct node *concatenate( struct node *start1,struct node *start2)
{
	struct node *ptr;
	if(start1==NULL)
	{
		start1=start2;
		return start1;
	}
	if(start2==NULL)   
		return start1;
	ptr=start1;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	ptr->link=start2;	
	return start1;
}
struct node *createList(struct node *start)
{
	int i,n,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return start;

	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start=insertInBeginning(start,data);

	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=insertAtEnd(start,data);	
	}
	return start;
}/*End of createList()*/

void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	while(p!=NULL)
	{
		printf("%d ", p->info);
		p=p->link;
	}
	printf("\n");
}/*End of display() */

struct node *insertInBeginning(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}/*End of insertInBeginning()*/

struct node *insertAtEnd(struct node *start, int data)
{
	struct node *p,*tmp;
	tmp= (struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return start;
}/*End of insertAtEnd()*/
