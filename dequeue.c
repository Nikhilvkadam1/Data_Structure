#include <stdio.h>
#define Max_size 5
int deque[];
int front = -1;
int rear = -1;
int x;
void enqueuefront(){
    if((front == 0 && rear == Max_size-1) || (front==rear +1 )){
        printf("queue is overflow");
    }else{
    printf("\nEnter Number : ");
    scanf("%d",&x);
    if(front==-1 && rear==-1){
        front=rear=0;
        deque[front]=x;
    }else if(front == 0){
       front = Max_size-1;
       deque[front]=x;
    }else{
        front--;
        deque[front]=x;
      }
    }
}
void enqueuerear(){
    if((front == 0 && rear == Max_size-1) || (front==rear +1 )){
        printf("queue is overflow");
    }else{
    printf("\nEnter Number : ");
    scanf("%d",&x);
    if(front==-1 && rear==-1){
        front=rear=0;
        deque[front]=x;
    }else if(rear == Max_size-1){
       rear =0;
       deque[rear]=x;
    }else{
        rear--;
        deque[rear]=x;
      }
    }
}
void dequeuefront(){
    if(rear==-1 && front==-1){
        printf("Stack is Underflow");

    }else if(front==rear){
        front=rear=-1;
    }
    else if(front == Max_size-1){
        printf("%d deleted from deque.",deque[front]);
        front = 0;
    }else{
        printf("%d deleted from deque.",deque[front]);
        front++;
    }
}
void dequeuerear(){
    if(rear==-1 && front==-1){
        printf("Stack is Underflow");

    }else if(front==rear){
        front=rear=-1;
    }
    else if(rear == 0){
        printf("%d deleted from deque.",deque[front]);
        rear = Max_size-1;
    }else{
        printf("%d deleted from deque.",deque[front]);
        rear++;
    }
}
void display(){
    int i= front;
    while(i != rear){
            printf("%d\t",deque[i]);
            i=(i+1)%Max_size;
        }
        printf("%d\t",deque[i]);
        printf("\n");
}
void main() {
    int op,x;
     printf("Menu\n1.enqueuefront\n2.enqueuerear\n3.dequeuefront\n4.dequeuefrontrear\n5.Display\n6.End");
    do{
        printf("\nChoose Option: ");
        scanf("%d",&op);
            switch(op){
                case 1:
                {
                    enqueuefront();
                    break;
                }
                case 2:
                {
                    enqueuerear();
                    break;
                }
                case 3:
                {
                    dequeuefront();
                    break;
                }
                case 4:
                {
                    dequeuerear();
                    break;
                }
                case 5:
                {
                    display();
                    break;
                }
                case 6:
                {
                    printf("End Point");
                    break;
                }
                default :
                {
                    printf("Invalid option");
                }
        }
    }while(op!=6);
}
