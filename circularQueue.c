#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front=-1;
int rear=-1;

int isFull()
{
    return front==(rear+1)%MAX_SIZE;
}

int isEmpty(){
    return  (front ==-1 && rear==-1);
}

void enqueue(int value)
{
    if(isFull())
    {
          printf("Queue is full. Enqueue operation cannot be performed.\n");
    }
    else if(isEmpty())
    {
        front=rear=0;
        queue[rear]=value;
    }
    else
    {
        rear=(rear+1)%MAX_SIZE;
        queue[rear]=value;

    }
}


void dequeue(){
    int item=0;
    if(isEmpty())
    {
         printf("Queue is empty. Dequeue operation cannot be performed.\n");
    }
    else if(rear==front)
    {
        item =queue[front];
        front=rear=-1;
    }
    else
    {
        item=queue[front];
        front=(front+1)%MAX_SIZE;

    }

}

void print()
{
    for (int i =front; i < rear; i++)
    {
       printf("%d ",queue[i] );
    }
    
    printf("\n");
}

int main()
{
    for(int i=0;i<5;i++)
    {
        enqueue(i);
    }
    dequeue();
     dequeue();
    print();
}