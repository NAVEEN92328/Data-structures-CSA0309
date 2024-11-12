#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
int precedence(char c) { return (c == '+' || c == '-') ? 1 : (c == '*' || c == '/') ? 2 : (c == '^') ? 3 : -1; }

void infixToPostfix(char *infix, char *postfix) {
    int i, j = 0;
    for (i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isalnum(c)) 
            postfix[j++] = c;
        else if (c == '(') 
            push(c);
        else if (c == ')') {
            while (stack[top] != '(') 
                postfix[j++] = pop();
            pop();  
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) 
                postfix[j++] = pop();
            push(c);
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

