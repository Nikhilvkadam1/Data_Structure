#include <stdio.h>
#define Max_size 5
int queue[];
int front = -1;
int rear = -1;
int x;

void enqueue(){
    if(front == (rear+1)%Max_size){
        printf("queue is overflow");
    }else{
    printf("\nEnter Number : ");
    scanf("%d",&x);
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }else{
       rear=(rear+1)%Max_size;
        queue[rear]=x;
    }
    }
}

void dequeue(){
    if(rear==-1 && front==-1){
        printf("Stack is Underflow");

    }else if(front==rear){
        front=rear=-1;
    }
    else{
        printf("%d deleted from queue.",queue[front]);
        front=(front+1)%Max_size;
    }
}

void display(){
    int i= front;
    if(rear==-1 && front==-1){
        printf("Stack is Empty");
    }else{
        while(i != rear){
            printf("%d\t";queue[i]);
            i=(i+1)%Max_size;
        }
        printf("%d\t";queue[i]);
        printf("\n");
    }
}

void main() {
    int op,x;
     printf("Menu\n1.enqueue\n2.dequeue\n3.Display\n4.Exit");
    do{
        printf("\nChoose Option: ");
        scanf("%d",&op);
            switch(op){
                case 1:
                {
                    enqueue();
                    break;
                }
                case 2:
                {
                    dequeue();
                    break;
                }
                case 3:
                {
                    display();
                    break;
                }
                case 4:
                {
                    printf("End Point");
                    break;
                }
                default :
                {
                    printf("Invalid option");
                }
        }
    }while(op!=4);
}
