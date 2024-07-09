#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


typedef struct {
    struct node* top;
} Stack;

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Memory allocation error for the stack.\n");
        exit(EXIT_FAILURE);
    }
    s->top = NULL;
    return s;
}

int isEmpty(Stack* s) {
    return (s->top == NULL);
}

void push(Stack* s, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation error for a new node.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }

    struct node* temp = s->top;
    s->top = temp->next;
    free(temp);
}

int top(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return s->top->data;
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    struct node* current = s->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void dispose(Stack* s) {
    while (!isEmpty(s)) {
        pop(s);
    }
    free(s);
}

int main() {
    Stack* s = createStack();

    int choice, value;

    do {
        printf("\n----- Stack Implementation using Linked List -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Display\n");
        printf("5. Dispose\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a value to push: ");
            scanf("%d", &value);
            push(s, value);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            printf("Top of the stack: %d\n", top(s));
            break;
        case 4:
            display(s);
            break;
        case 5:
            dispose(s);
            printf("Stack disposed.\n");
            break;
        case 0:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
