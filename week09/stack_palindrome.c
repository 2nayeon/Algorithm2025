#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 10

char stack[MAX_STACK_SIZE];
int top = -1;
void push(char data);
char pop();

int main()
{
    char word[10], schar, ochar;
    int i, p = 1, slen;

    printf("Enter word...");
    scanf("%s", word);

    slen = strlen(word);

    for (i = 0; i < slen; i++)
        push(word[i]);
    for (i = 0; i < slen; i++) {
        schar = pop();
        ochar = word[i];
        if (schar != ochar) {
            printf("False\n");
            p = 0;
            break;
        }
    }
    if (p == 1)
        printf("True\n");
}


void push(char item)
{

    if (top >= MAX_STACK_SIZE - 1)
        printf("Stack is overflow !!!\n");
    else {
        top++;
        stack[top] = item;
    }
}

char pop()
{
    if (top == -1)
        printf("Stack is empty!!!");
    else return stack[top--];
}