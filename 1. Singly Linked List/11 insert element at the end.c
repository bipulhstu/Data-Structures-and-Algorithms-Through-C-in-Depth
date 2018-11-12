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


int main()
{
   struct node *start=NULL;
   int choice, data, x, k;
   start=createList(start);
   displayList(start);            ///display lsit
   printf("Enter a element to insert in before the list or in an empty list: ");
   scanf("%d",&data);
   ///call function to insert data in beginning or in an empty list`
   start=insertInBeginning(start, data);
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


