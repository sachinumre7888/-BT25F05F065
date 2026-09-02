#include <stdio.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push element
void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

// Pop element
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    Stack s;
    init(&s);

    int i = 0;
    while (exp[i] != '\0') {
        char ch = exp[i];

        // Ignore spaces
        if (ch == ' ') {
            i++;
            continue;
        }

        // If operand, push to stack
        if (isdigit(ch)) {
            push(&s, ch - '0');
        }
        // If operator
        else {
            int val2 = pop(&s);
            int val1 = pop(&s);

            switch (ch) {
                case '+':
                    push(&s, val1 + val2);
                    break;
                case '-':
                    push(&s, val1 - val2);
                    break;
                case '*':
                    push(&s, val1 * val2);
                    break;
                case '/':
                    push(&s, val1 / val2);
                    break;
            }
        }
        i++;
    }

    return pop(&s);
}

int main() {
    char postfix[] = "23*54*+9-";

    printf("Postfix Expression: %s\n", postfix);
    printf("Result = %d\n", evaluatePostfix(postfix));

    return 0;
}
