#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100
struct Stack {
 int top;
 char items[MAX_SIZE];
};

void initialize(struct Stack *s) {
 s->top = -1;
}

bool isEmpty(struct Stack *s) {
 return s->top == -1;
}

bool isFull(struct Stack *s) {
 return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, char c) {
 if (!isFull(s)) {
 s->items[++(s->top)] = c;
 } else {
 printf("Stack is full\n");
 }
}

char pop(struct Stack *s) {
 if (!isEmpty(s)) {
 return s->items[(s->top)--];
 } else {
 printf("Stack is empty\n");
 return '\0';
 }
}

bool isBalanced(const char *expression) {
 struct Stack stack;
 initialize(&stack);

 for (int i = 0; expression[i] != '\0'; i++) {

 if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {

        push(&stack, expression[i]);

    } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
     {

    if (isEmpty(&stack)) {

            return false;
    }
 char top = pop(&stack);

 if ((expression[i] == ')' && top != '(') || (expression[i] == ']' && top != '[') || (expression[i] == '}' && top != '{')) {

    return false;
    }
  }
 }
 return isEmpty(&stack);
}

int main() {
 char expression[MAX_SIZE];
 printf("Enter an expression: ");
 scanf("%s", expression);

 if (isBalanced(expression)) {
 printf("Parentheses are balanced.\n");
 } else {
 printf("Parentheses are not balanced.\n");
 }

 return 0;
}
