#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int main() {
    char inputStr[100], c;
    int i, length;
    initialize();
    printf("Enter a string\n");
    gets(inputStr);
    length = strlen(inputStr);
    ///Push all characters of input String to Stack
    for(i = 0; i < length; i++){
        push(inputStr[i]);
    }
    ///Popping characters from stack returns the characters of input string
    ///in reverse order. We will then compare it with corresponding
	///characters of input string. If we found a mismatch the input
	///string is not a palindrome string
    for(i = 0; i < length; i++){
        if(pop() != inputStr[i]) {
            printf("Not a Palindrome String\n");
            return 0;
        }
    }

    printf("Palindrome String\n");
    return 0;
}
