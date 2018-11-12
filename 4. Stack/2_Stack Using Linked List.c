///Purpose: To implement stack using linked list
///Author : Bipul Islam, EEE, HSTU-5200
#include<stdio.h>
#include<stdlib.h>
struct node {
	int info;
	struct node *link;
};
struct node *top;

void initialize();
int isEmpty();
int size();
int peek();
void push(int x);
int pop();
void display();

main()
{
    int choice, x;
    initialize();
    while(1)
    {
        printf("1. Push an element on the top.\n");
        printf("2. Pop an element from the top.\n");
        printf("3. Display the top element.\n");
        printf("4. Display all stack elements.\n");
        printf("5. Display size of the stack.\n");
        printf("6. Quit.\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if(choice == 6)
            break;
        switch(choice)
        {
        case 1:
            printf("Enter the element to be pushed : ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            x = pop();
            printf("Popped element is : %d\n",x);
            break;
        case 3:
            printf("Element at the top is : %d\n", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Size of stack = %d\n", size());
            break;
        default:
            printf("Wrong Choice!!\n");
            break;
        }
        printf("\n");
    }
}
void initialize()
{
    top = NULL;
}
int size()
{
    int s = 0;
    struct node *p = top;
    while(p! = NULL){
    	p = p->link;
    	s++;
    }
    return s;
}
void push(int x)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
    	printf("No Memory: Stack Overflow!!\n");
    	retrun;
    }
    ///else
    temp->info = x;
    temp->link = top;
    top = temp;
}
int pop()
{
    struct node *temp;
    int x;
    if(isEmpty()){
    	printf("Stack Underflow!!!\n");
    	exit(1);
    }
    //else
    temp = top;
    x = top->info;
    top = top->link;
    free(temp);
    return x;
}
int peek()  ///returns the top value
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    ///else
    return top->info;
}
int isEmpty()
{
    if(top == NULL)
        return 1;
    else
        return 0;
}

int getStackSize(struct node* top){
    ///input validation
    if(top == NULL){
        pritnf("Error : Invalid stack pointer !!!\n");
        return;
    }
    //else
    int cnt = 0;
    while(top != NULL){
        top = top->link;
        cnt++;
    }
    return cnt;
}

void display()
{
    struct node *p;
    p = top;

    if(isEmpty()){
    	printf("Stack is empty\n");
    	return;
    }
    //else
    printf("Stack is:\n\n");
    while(p!=NULL){
    	printf("%d\n", p->info);
    	p = p->link;
    }
    printf("\n");
}
