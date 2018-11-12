#inlcude<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};

void displaylist(struct node *start) ///displayList() function
{
    struct node *p;
    if(start==NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("List is : ");
    p = start;

    while(p!=NULL)
    {
        printf("%d ", p->info);
        p = p->link;
    }
    printf("\n");
} ///End of displaylist()

void countNodes(struct node *start)   ///countNodes() function
{
    int n=0;
    struct node *p=start;
    while(p!=NULL)
    {
        n++;
        p=p->link;
    }
    printf("Number of nodes in list: %d\n", n);
} ///End of countNodes()

void search(struct node *start, int x)   ///search() function
{
    struct node *p
    int position =1;
    p=start;
    while(p!=NULL)
    {
        if(p->info == x)
            break;
        else
            position++;

        p=p->link;
    }
    if(p==NULL)
        printf("%d is not found in list.\n",x);
    else
        printf("%d is found at position %d\n", x, position);
} ///End of search()
