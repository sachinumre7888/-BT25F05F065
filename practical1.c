#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;


// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}


// Check whether stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}


// Check whether stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}


// Push an element into stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }

    s->top++;
    s->arr[s->top] = value;
}


// Pop an element from stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }

    return s->arr[s->top--];
}


// Perform arithmetic operation
int calculate(int a, int b, char operator) {

    switch (operator) {

        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            if (b == 0) {
                printf("Division by zero\n");
                exit(1);
            }
            return a / b;

        case '%':
            return a % b;

        default:
            printf("Invalid operator\n");
            exit(1);
    }
}


// Evaluate postfix expression
int evaluatePostfix(char postfix[]) {

    Stack s;

    // Initialize stack
    initStack(&s);

    // Read expression from left to right
    for (int i = 0; postfix[i] != '\0'; i++) {

        // Ignore spaces
        if (postfix[i] == ' ')
            continue;


        // If character is a digit
        if (isdigit(postfix[i])) {

            int value = postfix[i] - '0';

            push(&s, value);
        }


        // Otherwise, it is an operator
        else {

            int b = pop(&s);
            int a = pop(&s);

            int result = calculate(a, b, postfix[i]);

            push(&s, result);
        }
    }

    // Final answer
    return pop(&s);
}


int main() {

    char postfix[MAX];

    printf("Enter postfix expression: ");

    scanf("%99[^\n]", postfix);

    int result = evaluatePostfix(postfix);

    printf("Result = %d\n", result);

    return 0;
}
