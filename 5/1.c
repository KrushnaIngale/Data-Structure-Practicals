#include <stdio.h>
#include <stdlib.h>
#define max 10

int stack1[max], top = -1;  // Global top
void push();
void pop();
void display();  // Function to display the stack

int main() {
    int choice;
    char ch;

    do {
        printf("1 for push, 2 for pop, 3 to display stack :\n");
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
            default:
                printf("Invalid input\n");
        }

        printf("Enter y to continue, any other key to stop: ");
        scanf(" %c", &ch);  // Space before %c to consume newline
    } while (ch == 'y' || ch == 'Y');

    display();

    return 0;
}

void push() {
    int num;
    if (top == max - 1) {
        printf("Stack overflow\n");
    } else {
        printf("Enter number you want to push: ");
        scanf("%d", &num);
        top++;
        stack1[top] = num;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        int y = stack1[top];
        top--;
        printf("Popped: %d\n", y);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: \n");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack1[i]);
        }
        printf("\n");
    }
}
