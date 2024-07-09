#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct {
    struct node* front;
    struct node* rear;
} *Queue;

Queue createQueue() {
    Queue q = (Queue)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory allocation error for the queue.\n");
        exit(EXIT_FAILURE);
    }
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(Queue* q) {
    return (q->front == NULL);
}

void enqueue(Queue* q, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation error for a new node.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct node* temp = q->front;
    q->front = temp->next;

    // If dequeue makes the queue empty, update rear as well
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    return q->front->data;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    struct node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void dispose(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

int main() {
    Queue* q = createQueue();

    int choice, value;

    do {
        printf("\n----- Queue Implementation using Linked List -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Display\n");
        printf("5. Dispose\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a value to enqueue: ");
            scanf("%d", &value);
            enqueue(q, value);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            printf("Front of the queue: %d\n", front(q));
            break;
        case 4:
            display(q);
            break;
        case 5:
            dispose(q);
            printf("Queue disposed.\n");
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
