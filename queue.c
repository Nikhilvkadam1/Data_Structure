#include <stdio.h>
#define Max_size 5
int queue[];
int front = -1;
int rear = -1;
int x;
void enqueue(){
    if(rear == Max_size-1){
        printf("queue is overflow");
    }else{
    printf("\nEnter Number : ");
    scanf("%d",&x);
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }else{
        rear++;
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
        front++;
    }
}

void peak(){
     if(rear==-1 && front==-1){
        printf("Stack is Empty");
    }else{
        printf("%d is a peek number",queue[front]);
    }
}

void display(){
    if(rear==-1 && front==-1){
        printf("Stack is Empty");
    }else{
        for(int i=front;i<rear+1;i++){
            printf("%d\t",queue[i]);
        }
    }
}

void main() {
    int op,x;
     printf("Menu\n1.enqueue\n2.dequeue\n3.peak\n4.Display\n5.Exit");
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
                    peak();
                    break;
                }
                case 4:
                {
                    display();
                    break;
                }
                case 5:
                {
                    printf("End Point");
                    break;
                }
                default :
                {
                    printf("Invalid option");
                }
        }
    }while(op!=5);
}
