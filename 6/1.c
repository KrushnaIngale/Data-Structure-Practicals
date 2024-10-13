#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

// Stack structure for characters (used for infix to postfix/prefix conversions)
struct Stack {
    int top;
    char items[MAX];
};

// Stack structure for integers (used for postfix evaluation)
struct IntStack {
    int top;
    int items[MAX];
};

// Function prototypes
void infixToPostfix(char *exp);
void infixToPrefix(char *exp);
int evaluatePostfix(char *exp);
int precedence(char ch);
void reverse(char *exp);
void push(struct Stack *stack, char ch);
char pop(struct Stack *stack);
int isEmpty(struct Stack *stack);
char peek(struct Stack *stack);
void pushInt(struct IntStack *stack, int value);
int popInt(struct IntStack *stack);

// Function to convert infix expression to postfix
void infixToPostfix(char *exp) {
    struct Stack stack;
    stack.top = -1;
    char output[MAX];
    int i, k = 0;

    for (i = 0; exp[i]; i++) {
        if (isalnum(exp[i])) {
            output[k++] = exp[i];
        } else if (exp[i] == '(') {
            push(&stack, exp[i]);
        } else if (exp[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(')
                output[k++] = pop(&stack);
            pop(&stack);  // Remove '('
        } else {
            while (!isEmpty(&stack) && precedence(exp[i]) <= precedence(peek(&stack)))
                output[k++] = pop(&stack);
            push(&stack, exp[i]);
        }
    }
    while (!isEmpty(&stack))
        output[k++] = pop(&stack);

    output[k] = '\0';
    printf("Postfix Expression: %s\n", output);
}

// Function to convert infix expression to prefix
void infixToPrefix(char *exp) {
    reverse(exp);  // Reverse the infix expression
    struct Stack stack;
    stack.top = -1;
    char output[MAX];
    int i, k = 0;

    for (i = 0; exp[i]; i++) {
        if (isalnum(exp[i])) {
            output[k++] = exp[i];
        } else if (exp[i] == ')') {
            push(&stack, exp[i]);
        } else if (exp[i] == '(') {
            while (!isEmpty(&stack) && peek(&stack) != ')')
                output[k++] = pop(&stack);
            pop(&stack);  // Remove ')'
        } else {
            while (!isEmpty(&stack) && precedence(exp[i]) < precedence(peek(&stack)))
                output[k++] = pop(&stack);
            push(&stack, exp[i]);
        }
    }
    while (!isEmpty(&stack))
        output[k++] = pop(&stack);

    output[k] = '\0';
    reverse(output);  // Reverse to get the final prefix expression
    printf("Prefix Expression: %s\n", output);
}

// Function to evaluate postfix expression
int evaluatePostfix(char *exp) {
    struct IntStack stack;
    stack.top = -1;
    int i = 0;

    while (exp[i] != '\0') {
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            pushInt(&stack, num);
        } else {
            int val1 = popInt(&stack);
            int val2 = popInt(&stack);
            switch (exp[i]) {
                case '+': pushInt(&stack, val2 + val1); break;
                case '-': pushInt(&stack, val2 - val1); break;
                case '*': pushInt(&stack, val2 * val1); break;
                case '/': pushInt(&stack, val2 / val1); break;
            }
            i++;
        }
    }
    return popInt(&stack);
}

// Main function with menu-driven program
int main() {
    int choice;
    char exp[MAX];

    do {
        printf("\nMenu:\n");
        printf("1. Infix to Postfix\n");
        printf("2. Infix to Prefix\n");
        printf("3. Evaluate Postfix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                fgets(exp, MAX, stdin);
                exp[strcspn(exp, "\n")] = 0;  // Remove newline character
                infixToPostfix(exp);
                break;
            case 2:
                printf("Enter infix expression: ");
                fgets(exp, MAX, stdin);
                exp[strcspn(exp, "\n")] = 0;  // Remove newline character
                infixToPrefix(exp);
                break;
            case 3:
                printf("Enter postfix expression: ");
                fgets(exp, MAX, stdin);
                exp[strcspn(exp, "\n")] = 0;  // Remove newline character
                printf("Result of Postfix Evaluation: %d\n", evaluatePostfix(exp));
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}

// Helper functions for stack operations
void push(struct Stack *stack, char ch) {
    stack->items[++stack->top] = ch;
}

char pop(struct Stack *stack) {
    return stack->items[stack->top--];
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

char peek(struct Stack *stack) {
    return stack->items[stack->top];
}

void pushInt(struct IntStack *stack, int value) {
    stack->items[++stack->top] = value;
}

int popInt(struct IntStack *stack) {
    return stack->items[stack->top--];
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return -1;
    }
}

// Function to reverse a string
void reverse(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}
