///Traverse a linked list
#include<stdio.h>
#include<stdlib.h>

struct node {   ///struct of a new node
    int data;   ///data
    struct node *next;  ///address
} *head;

void createlist(int n);  ///function to create list
void traverselist();     ///function to display list

int main()
{
    int n;
    printf("Enter the total number of nodes: ");
    scanf("%d",&n);
    createlist(n);
     int x=3;
    traverselist(x);

    return 0;
}
///create a list of n nodes
void createlist( int n)
{
    struct node *newnode, *temp;
    int data , i;
    head=(struct node *)malloc(sizeof(struct node));
    ///allocate memory for head node
    if(head==NULL)
        printf("Unable to allocatae memory!!!\n");
    else{
        ///Input data of node from the user
        printf("Enter the data of node 1: ");
        scanf("%d",&data);

        head->data=data;    ///link the data fieled with data
        head->next=NULL;    ///linked the address fieled to NULL

        temp=head;
        ///create n nodes and add to the linked list
        for(i=2; i<=n; i++)
        {
            newnode=(struct node *)malloc(sizeof(struct node));
            ///allocate memory for newnode
            if(newnode==NULL)
            {
                printf("Unable to allocate memory!!\n");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ",i);
                scanf("%d",&data);

                newnode->data=data; ///link the data fieled of newnode with data
                newnode->next=NULL; ///link the address field of newnode with NULL

                temp->next=newnode;
                temp=temp->next;

            }
        }
    }
}
///Display list
void traverselist(int x)
{
     struct node *temp;

    if(head==NULL)
        printf("List is empty!!!\n");
    else
    {
        temp=head;
        int position=1;
        while(temp!=NULL)
        {
            if(temp->data==x)
                break;
            position++;

            temp=temp->next; ///move to the next node
        }
        if(temp==NULL)
            printf("%d is not found in the list.\n", x);
        else
            printf("%d is at postion %d.\n",x, position);
    }
}
///same as searching




