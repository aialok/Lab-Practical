#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Stack Stack;

struct Stack
{
    int data[MAX_SIZE];
    int top;
};

Stack* createStack(){
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->top=-1;
    return stack;
};


int isEmpty(Stack* stack)
{
    return stack->top==-1;
}

int isFUll(Stack* stack)
{
    return stack->top==MAX_SIZE-1;
}

void push(Stack* stack, int data)
{
        
        if(isFUll(stack))
        {
        printf("StacksOverflow\n");
        return;
        }
        stack->top++;
        stack->data[stack->top]=data;
        printf("%d is pushed to stack\n", stack->data[stack->top]);

}

int pop(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }

    int data= stack->data[stack->top];
    stack->top-=1;
    return data;
}

int top(Stack* stack)
{
    if(stack->top==-1)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return stack->data[stack->top];

}

void displayStack(Stack* stack)
{
    for(int i=0;i<=stack->top;i++)
    {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main()
{
    Stack* stack=createStack();
    for (int i = 0; i < 8; i++)
    {
        int x;
        scanf("%d", &x);
        push(stack,x);
    }
    displayStack(stack);
   
    printf("%d is popped\n", pop(stack));
    displayStack(stack);
    
}
