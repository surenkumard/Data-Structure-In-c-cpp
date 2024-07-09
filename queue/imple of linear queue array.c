#include <stdio.h>
#include <stdlib.h>

#define empty -1
#define min 5

struct queue_record {
    int *qarr;
    int front;
    int rear;
    int size;
};

typedef struct queue_record *queue;
queue q;

queue create(int max) {
    queue q;
    if (max < min)
        printf("error(\"Queue size is too small\")\n");
    q = (queue)malloc(sizeof(struct queue_record));

    if (q == NULL)
        printf("fatal_error(\"Memory not allocated\")");
    else {
        q->qarr = (int *)malloc(sizeof(int) * max);
        if (q->qarr == NULL)
            printf("fatal_error(\"Queue not allocated\")");
        else {
            q->front = -1;
            q->rear = -1;
            q->size = max;
            printf("Queue Created Successfully !!!");
            return q;
        }
    }
}

int isempty() {
    return q->rear == -1;
}

void display() {
    if (!isempty()) {
        int i = 0;
        printf("\nThe queue elements are: ");
        while ((q->front + i) <= q->rear) {
            printf("%d ", q->qarr[q->front + i]);
            i++;
        }
    } else {
        printf("\nQueue is Empty");
    }
}

int isfull() {
    return q->rear == q->size - 1;
}

void dispose() {
    if (!isempty()) {
        free(q->qarr);
        free(q);
    }
}

void dequeue() {
    if (q->rear != q->front)
        q->front++;
    else {
        q->rear = q->front = -1;
    }
}

void enqueue(int val) {
    if (isfull()) {
        printf("error(\"Queue Full\")");
    } else {
        if (isempty()) {
            q->front++;
        }
        q->qarr[++q->rear] = val;
    }
}

void make_empty() {
    q->front = -1;
    q->rear = -1;
}

int front() {
    return q->qarr[q->front];
}

int main() {
    int num, choice;
    printf("\nEnter capacity of the queue: ");
    scanf("%d", &num);
    q = create(num);
    do {
        printf("\n2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. Front of the queue\n");
        printf("5. Make queue empty\n");
        printf("6. Dispose queue\n");
        printf("7. Display\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 2:
            printf("\nEnter a number to be inserted: ");
            scanf("%d", &num);
            enqueue(num);
            break;
        case 3:
            if (!isempty()) {
                dequeue();
            } else {
                printf("\nQueue is empty");
            }
            break;
        case 4:
            if (isempty()) {
                printf("\nQueue is empty");
            } else {
                num = front();
                printf("\nFront element of the queue: %d", num);
            }
            break;
        case 5:
            make_empty();
            printf("Now queue does not have any element");
            break;
        case 6:
            dispose();
            printf("\nNow queue is disposed");
            break;
        case 7:
            display();
        }
    } while (choice != 6);

    return 0;
}
