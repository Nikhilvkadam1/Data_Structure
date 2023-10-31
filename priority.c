#include <stdio.h>
#define max 5

struct Elem{
    int data;
    int p;
};

struct Elem pq [max];
int front = -1;
int rear = -1;

void insert(int n , int p){
    if(rear == max-1){
        printf("FULL");
        return;
    }
    if(front==-1){
        front=0;
    }
    pq[++rear].data = n;
    pq[rear].p = p;
    for(int i=rear ; i>0 ; i--){
        if(pq[i].p>pq[i-1].p){
           struct Elem temp = pq[i];
           pq[i] = pq[i-1];
           pq[i-1] = temp;
        }else if(pq[i].p<=pq[i-1].p){
            break;
        }
    }
}

void delete_element(){
 if(front==-1){
    printf("Underflow\n");
    return -1;
 }else{
    //int re = pq[front].data;
    printf("Deleted Element is %d \n",pq[front].data);
    if(front==rear){
        front = rear = -1;
    }else{
        front ++;
    }

 }
}

void print_queue(){
    int i;
    printf("E:Element & P:Priority\n");
 for(i=front;i<=rear;i++){
    printf("[E:%d,P:%d] \t", pq[i].data , pq[i].p);
 }
 printf("\n");
}

void main(){
 int point = 1 ;
 int n,m,p;
printf("Options \n1-Insert \n2-Delete \n3-Print \n4-Exit \n");
while(point==1){
    int op ;
    printf("Your Option: ");
    scanf("%d",&op);
    switch (op){

 case 1:
    printf("Enter number to insert: ");
    scanf("%d",&n);
    printf("Enter priority of to element: ");
    scanf("%d",&p);
    insert(n,p);
    break;

 case 2:
    delete_element();
    break;

 case 3:
    print_queue();
    break;

 case 4:
    point=0;
    break;

 default:
    printf("Not a Valid choice \n");
    break;

    }
}
}
