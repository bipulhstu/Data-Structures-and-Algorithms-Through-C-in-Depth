#include <stdio.h>
#include <string.h>

#define MAX 100
int a[MAX];
int top;

void initialize()
{
    top = -1;
}
int size()
{
    return top+1;
}
int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top == MAX-1)
        return 1;
    else
        return 0;
}
void push(int x)
{
    if(isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    ///else
    top = top + 1;
    a[top] = x;
}
int pop()
{
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
int main() {
    char str[100], c;
    int i, length;
    initialize();
    printf("Enter a string of parenthesis: \n");
    gets(str);
    length = strlen(str);
    /*
    # for '{' : we push '{' in stack
    # for '}' : we pop a character from stack.
                For every '}' there must be one '{' earlier.
	This will ensure that:
	** There are equal number of '{' and '}' characters in string.
    ** For every '{' there is a '}' in input string later.
    */
    for(i = 0; i < length; i++){
        if(str[i] == '{')
            push(str[i]);
        else if(str[i] == '}')
            pop();
        else {
            printf("Error : Invalid Character !! \n");
            return 0;
        }
    }

    if(isEmpty())
        printf("Valid Paranthesis Expression\n");
    else
        printf("InValid Paranthesis Expression\n");

    return 0;
}
