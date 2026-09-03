#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }

    s->arr[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }

    return s->arr[s->top--];
}

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
            if (b == 0) {
                printf("Division by zero\n");
                exit(1);
            }
            return a % b;

        default:
            printf("Invalid operator\n");
            exit(1);
    }
}

int evaluatePostfix(char exp[]) {
    Stack s;
    initStack(&s);

    for (int i = 0; exp[i] != '\0'; i++) {

        char ch = exp[i];

        // Ignore spaces
        if (ch == ' ') {
            continue;
        }

        // If digit, push it
        if (isdigit(ch)) {
            push(&s, ch - '0');
        }

        // If operator
        else {
            int b = pop(&s);
            int a = pop(&s);

            int result = calculate(a, b, ch);

            push(&s, result);
        }
    }

    return pop(&s);
}

int main() {
    char postfix[MAX];

    printf("Enter postfix expression: ");
    scanf("%99[^\n]", postfix);

    int result = evaluatePostfix(postfix);

    printf("Postfix Expression: %s\n", postfix);
    printf("Result = %d\n", result);

    return 0;
}
