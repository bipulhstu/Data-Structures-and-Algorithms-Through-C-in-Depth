/** Deletion in a single linked list
       1. Deletion of the first node
       2. Deletion of the only node
       3. Deletion between the list
       4. Deletion at the end
NB: all codes are here
**/
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
struct node *deleteNode(struct node *start, int x);

int main()
{
   struct node *start=NULL;
   int choice, data, x, k;
   start=createList(start);
   displayList(start);            ///display lsit
   printf("Enter a element to be deleted: ");
   scanf("%d",&x);

   ///call function to delete node
   start=deleteNode(start, x);
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
struct node *deleteNode(struct node *start, int x)
{
    struct node *temp, *p;
    if(start==NULL)
    {
        printf("List is empty.\n");
        return start;
    }
    ///Deletion of first node
    if(start->info==x)
    {
        temp=start;
        start=start->link;
        free(temp);

        return start;
    }
    ///Deletion in between or at the end
    p=start;
    while(p->link!=NULL)
    {
        if(p->link->info==x)
            break;
        p=p->link;
    }
    if(p->link==NULL)
        printf("Element %d is not in the list!!\n", x);
    else
    {
        temp=p->link;
        p->link=temp->link;
        free(temp);

        return start;
    }

};

