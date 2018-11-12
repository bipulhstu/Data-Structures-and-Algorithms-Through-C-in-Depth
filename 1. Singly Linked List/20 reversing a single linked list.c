#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *link;

};
struct node *createList(struct node *start);
void displayList(struct node *start);
struct node *insertInBeginning(struct node *start, int data);
void insertAtEnd(struct node *start, int data);
struct node *reverseList(struct node *start);

int main()
{
   struct node *start=NULL;
   int choice, data, x, k;
   start=createList(start);
   displayList(start);            ///display lsit

   ///call function to reverse list
   start=reverseList(start);
   printf("Reverse ");
   displayList(start);

}
struct node *createList(struct node *start)
{
    int i, n, data;
    printf("Enter the no of nodes: ");
    scanf("%d",&n);
    if(n==0)
        return start;

    printf("Enter the first elemlent to be inserted: ");
    scanf("%d",&data);
    start=insertInBeginning(start, data);
    for(i=2; i<=n; i++)
    {
        printf("Enter the next element to be inserted: ");
        scanf("%d",&data);
        insertAtEnd(start, data);
    }
    return start;
};
struct node *insertInBeginning(struct node *start, int data)
{
    struct node *temp;
    temp=(struct node * )malloc(sizeof(struct node));

    temp->info=data;
    temp->link=start;
    start=temp;

    return start;
};
void insertAtEnd(struct node *start, int data)
{
    struct node *temp, *p;
    temp=(struct node * )malloc(sizeof(struct node));

    temp->info=data;

    p=start;

    while(p->link!=NULL)
    {
        p=p->link;
    }
    p->link=temp;
    temp->link=NULL;
}
void displayList(struct node *start)
{
    struct node *p;
    if(start==NULL)
    {
        printf("List is empty!!!\n");
        return;
    }
    printf("List is : ");
    ///Code for traverse list
    ///Traverse list means visiting each nodes exactly ones
    p=start;
    while(p!=NULL)
    {
        printf("%d ", p->info);
        p=p->link;
    }
    printf("\n");
}
struct node *reverseList(struct node *start)
{
    struct node *prev, *ptr, *next;
    prev=NULL;
    ptr=start;
    while(ptr!=NULL)
    {
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;

    return start;
};
