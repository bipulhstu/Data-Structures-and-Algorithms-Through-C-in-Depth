#include <stdio.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
int a[MAX];
int top;

void initialize() {
 top = -1;
}

int isFull() {
    if(top == MAX-1)
        return TRUE;
    else
        return FALSE;
}

int isEmpty() {
    if(top == -1)
        return TRUE;
    else
        return FALSE;
}

void push(int x) {
    if(isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    ///else
    top = top + 1;
    a[top] = x;
}
int pop() {
    int x;
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    ///else
    x = a[top];
    top = top - 1;
    return x;
}

void display()
{
    int i;
    printf("top = %d\n", top);
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    ///else
    printf("Stack is : \n\n");
    for(i = top; i>=0; i--)
        printf(" %d\n", a[i]);
    printf("\n");
}
void insertAtBottom(int item) {
    if (isEmpty()) {
        push(item);
    } else {

        /* Store the top most element of stack in top variable and
        recursively call insertAtBottom for rest of the stack */
        int top = pop();
        insertAtBottom(item);

        /* Once the item is inserted at the bottom, push the
        top element back to stack */
        push(top);
    }
}

void reverse() {
    if (!isEmpty()) {
        /* keep on popping top element of stack in
        every recursive call till stack is empty  */
        int top = pop();
        reverse();

        /* Now, instead of inserting element back on top
        of stack, we will insert it at the bottom of stack */
        insertAtBottom(top);
    }
}

int main() {
    ///Initializing top index of stack */
    initialize();
    ///Adding elements in stack
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printf("Original Stack\n");
    display();
    reverse();
    printf("\nReversed Stack\n");
    display();
    return 0;
}
