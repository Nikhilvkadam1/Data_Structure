#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100
struct Stack {
 int top;
 char items[MAX_SIZE];
};
int isEmpty(struct Stack *s) {
 return s->top == -1;
}
void push(struct Stack *s, char c) {
 if (s->top == MAX_SIZE - 1) {
 printf("Stack overflow\n");
 } else {
 s->items[++(s->top)] = c;
 }
}
char pop(struct Stack *s) {
 if (isEmpty(s)) {
 printf("Stack underflow\n");
 return '\0';
 } else {
 return s->items[(s->top)--];
 }
}
int precedence(char op) {
 if (op == '+' || op == '-') {
 return 1;
 }
 if (op == '*' || op == '/') {
 return 2;
 }
 return 0;
}
void infixToPostfix(char infix[], char postfix[]) {
 struct Stack stack;
 stack.top = -1;

 int i = 0, j = 0;

 while (infix[i] != '\0') {
 if (isalnum(infix[i])) {
 postfix[j++] = infix[i];
 } else if (infix[i] == '(') {
 push(&stack, '(');
 } else if (infix[i] == ')') {
 while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
 postfix[j++] = pop(&stack);
 }
 pop(&stack); // Pop the '('
 } else {
 while (!isEmpty(&stack) && precedence(infix[i]) <=
precedence(stack.items[stack.top])) {
 postfix[j++] = pop(&stack);
 }
 push(&stack, infix[i]);
 }
 i++;
 }
 while (!isEmpty(&stack)) {
 postfix[j++] = pop(&stack);
 }
 postfix[j] = '\0';
}
int main() {
 char infix[MAX_SIZE];
 char postfix[MAX_SIZE];
 printf("Enter an infix expression: ");
 scanf("%s", infix);
 infixToPostfix(infix, postfix);
 printf("Postfix expression: %s\n");
 return 0;
}
