#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct node
{   
    int data[MAX_SIZE];
    int front;
    int rear;

};

typedef struct node node;

node* queue()
{
    node* queue=(node*)malloc(sizeof(node));
    queue->front=-1;
    queue->rear=-1;
    return queue;

}

int isFull(node* queue)
{
    return queue->rear==MAX_SIZE-1;
}

int isEmpty(node* queue)
{
    return queue->rear==-1;
}


void push(node**queue, int data)
{   
    if(isFull(*queue))
    {
        printf("Queue is full\n");
        return;
    }
    (*queue)->front=0;
    (*queue)->rear+=1;
   int item= (*queue)->data[(*queue)->rear]=data;
   printf("Pushed %d \n", item);



}

int pop(node**queue)
{
   if( isEmpty(*queue))
    {
        printf("Queue is underflow...Insert element in it\n");

        return -1;
    }
    int data=(*queue)->data[(*queue)->front];
    (*queue)->front++;;

    if((*queue)->rear==(*queue)->front)
    {
        (*queue)->front=-1;
        (*queue)->rear=-1;
    }
    printf("Popped %d \n", data);
    return data;

}


void displayQueue(node* queue)
{
    for(int i=queue->front;i<=queue->rear;i++)
    {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

int main()
{
    node* q=queue();
    push(&q, 10);
    push(&q, 20);
    push(&q, 1002);
    displayQueue(q);
    pop(&q);
    displayQueue(q);
   
    
 

}





