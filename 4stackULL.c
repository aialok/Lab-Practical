#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct Stack Stack;
struct node
{
    int data;
    struct node *next;
};

struct Stack{
    node*top;
};


node* createNode(int data)
{
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;

}

Stack* createStack()
{
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->top=NULL;
    return stack;
    
}

void push(Stack** stack, int data)
{
       node* newNode=createNode(data);
       newNode->next=(*stack)->top; 
      ( *stack)->top=newNode;

}

int top(Stack* stack)
{
    return stack->top->data;
}

int pop(Stack **stack)
{
        if((*stack)->top==NULL)
        {
            printf("Stack Underflow\n");
            
        }
        else
        {
            int data=(*stack)->top->data;
            node* temp=(*stack)->top;
            (*stack)->top=temp->next;
            free(temp);
            return data;
        
        }
}

void displayStack(Stack* stack)
{
    node* curr= stack->top;
    while(curr!=NULL)
    {
        printf("%d ", curr->data );
        curr=curr->next;
    }
    printf("\n");

}

int main()
{
    Stack* stack = createStack();
    int choice, data;

    while (1)
    {
        printf("\nChoose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the data to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                printf("Popped element: %d\n", pop(&stack));
                break;
            case 3:
                printf("Top element: %d\n", top(stack));
                break;
            case 4:
                printf("Stack elements: ");
                displayStack(stack);
                break;
            case 5:
                free(stack);
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    

}




