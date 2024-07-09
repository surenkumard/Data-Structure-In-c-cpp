#include <stdio.h>
#include <stdlib.h>

#define empty -1
#define min 1

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
        printf("factal_error(\"Memory not allocate\")");
    else {
        q->qarr = (int *)malloc(sizeof(int) * max);
        if (q->qarr == NULL)
            printf("factal_error(\"Queue not allocta\")");
        else {
            q->front = -1;
            q->rear = -1;
            q->size = max;
            return q;
        }
    }
}

int isempty(queue q) {
    return q->front == -1;
}

void display(queue q) {
    if (!isempty(q)) {
        int i = q->front;
        printf("\nThe queue element are : ");
        while (i != q->rear) {
            printf("%d ", q->qarr[i]);
            i = (i + 1) % q->size;
        }
        printf("%d", q->qarr[i]); 
    } else {
        printf("\nQueue is Empty");
    }
}

int isfull(queue q) {
    return ((q->rear + 1) % q->size) == q->front;
}

void dequeue(queue q) {
    if (!isempty(q)) {
        if (q->rear == q->front)
            q->rear = q->front = -1;
        else
            q->front = (q->front + 1) % q->size;
    } else {
        printf("Queue is full");
    }
}

void enqueue(queue q, int val) {
    if (isfull(q)) {
        printf("error(\"Queue Full\")");
    } else {
        if (isempty(q)) {
            q->front++;
        }
        q->rear = (q->rear + 1) % q->size;
        q->qarr[q->rear] = val;
    }
}

int front(queue q) {
    return q->qarr[q->front];
}

void removevalue(queue q, int x) {
    int j = q->rear;
    for (int i = q->front; i % q->size != j || j < i;) {
        if (q->qarr[i] == x) {
            dequeue(q);
            j--;

        } else {
            int temp = front(q);
            dequeue(q);
            enqueue(q, temp);
            i = (i + 1) % q->size;
        }
    }
}

int main() {
    int num, val;
    printf("Enter a maximum number of element : ");
    scanf("%d", &num);

    q = create(num);

    printf("Enter a number that you want to insert :");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        printf("Enter a number : ");
        scanf("%d", &val);
        enqueue(q, val);
    }

    printf("Enter a number that you want to delete : ");
    scanf("%d", &num);

    printf("Original queue : \n");
    display(q);
    removevalue(q, num);
    printf("\nAfter deleting %d : \n", num);
    display(q);

    // Free memory
    free(q->qarr);
    free(q);

    return 0;
}
