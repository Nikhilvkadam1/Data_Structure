#include <stdio.h>
int stack[100], choice, n, top, x,m, i;

int underflow(){
 if(top==-1){
    return 1;
 }
 return 0;
}

int overflow(){
 if(top==n-1){
    return 1;
 }
 return 0;
}

void push(void) {
 if (top >= n - 1) {
 printf("\nSTACK is overflow\n");
 }else {
 printf("Enter a value to be pushed: ");
 scanf("%d", &x);
 top++;
 stack[top] = x;
 }
}

void pop() {
 if (top <= -1) {
 printf("\nStack is underflow\n");
 } else {
 printf("\nThe popped element is %d\n", stack[top]);
 top--;
 }
}

int peek(){
 if(underflow()){
    printf("Stack underflowed \n");
    return -1;
 }else{
  return stack[top];
 }
}

void display() {
 if (top >= 0) {
 printf("\nThe elements in STACK:\n");
 for (i = top; i >= 0; i--) {
 printf("%d\t", stack[i]);
 }
 } else {
 printf("\nThe STACK is empty\n");
 }
}

int main() {
     top = -1;
     printf("Enter the size of the stack (MAX=100): ");
     scanf("%d", &n);
     printf("\nSTACK OPERATIONS USING ARRAY");
     printf("\n-----------------------------");
     printf("\n1. PUSH");
     printf("\n2. POP");
     printf("\n3. DISPLAY");
     printf("\n4. peek");
     printf("\n5. EXIT");
     do {
         printf("\nEnter your choice: ");
         scanf("%d", &choice);
         switch (choice) {
             case 1:
             push();
             break;
             case 2:
             pop();
             break;
             case 3:
             display();
             break;
             case 4:
             m=peek();
             printf("%d",m);
             break;
             case 5:
             printf("\nEXIT POINT\n");
             break;

             default:
             printf("Please enter a valid choice (1/2/3/4/5)\n");
            }
         } while (choice != 5);
     return 0;
}


