#include <stdio.h>
#include <stdlib.h>

#define empty -1
#define min 1

struct queue_record{
    int *qarr;
    int front;
    int rear;
    int size;
};

typedef struct queue_record queue;

queue* create(int max){
    queue *q;
    if(max < min)
        printf("error(\"Queue size is too small\")\n");
    q = (queue*)malloc(sizeof(struct queue_record));

    if(q == NULL)
        printf("factal_error(\"Memory not allocate\")");
    else{
        q->qarr = (int*)malloc(sizeof(int) * max);
        if(q->qarr == NULL)
            printf("factal_error(\"Queue not allocta\")");
        else{
            q->front = -1;
            q->rear = -1;
            q->size = max;
            printf("Queue Created Successfully !!!");
            return q;
        }
    }
}

int isempty(queue *q){
    return q->front == -1;
}

void display(queue *q){
    if(!isempty(q)){
        int i = q->front;
        printf("\nThe queue element are : ");
        while(i != q->rear){
            printf("%d ",q->qarr[i]);
            i = (i+1) % q->size;
        }
    }
    else{
        printf("\nQueue is Empty");
    }
}

int isfull(queue *q){
    return ((q->rear + 1) % q->size) == q->front;
}

void dispose(queue *q){
    if(!isempty(q)){
        free(q->qarr);
        free(q);
    }
}

void dequeue(queue *q){
    if(!isempty(q)){
        if(q->rear == q->front)
            q->rear = q->front = -1;
        else
            q->front = (q->front + 1) % q->size;
    }
    else{
        printf("Queue is full");
    }
}


void enqueue(queue *q,int val){
    if(isfull(q)){
        printf("error(\"Queue Full\")");
    }
    else{
        if(isempty(q)){
            q->front++;
        }
        q->rear = ( q->rear + 1 ) % q->size;
        q->qarr[q->rear] = val;
    }
}

void make_empty(queue *q){
    q->front = -1;
    q->rear = -1;
}

int front(queue *q){
    return q->qarr[q->front];
}

void main(){
    int num, choice;
    do{
        printf("\n1.Create\n");
        printf("2.Insert element\n");
        printf("3.Delect element\n");
        printf("4.Front of the queue\n");
        printf("5.Make queue empty\n");
        printf("6.Dispose queue\n");
        printf("7.Display\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter Maximum element of the queue : ");
                scanf("%d",&num);
                queue *q = create(num);
                break;        
            case 2:
                printf("\nEnter a number to be want to insert : ");
                scanf("%d",&num);
                enqueue(q,num);
                break;
            case 3:
                if(!isempty(q)){
                    dequeue(q);
                }
                else{
                    printf("\nQueue is empty");
                }
                break;
            case 4:
                if(isempty(q)){
                    printf("\nQueue is empty");
                }
                else{
                    num = front(q);
                    printf("\nFront element of the queue : %d",num);
                }
                break;
            case 5:
                make_empty(q);
                printf("Now queue does not have any element");
                break;
            case 6:
                dispose(q);
                printf("\nNow queue throw into a bin. GOOD BYE ):");
                break;
            case 7:
                display(q);
            }
    }while(choice != 6);
}
