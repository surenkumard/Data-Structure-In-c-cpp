#include <Stdio.h>
#include <stdlib.h>

#define min 10
#define mindata -1

struct heap_struct{
    int *elements;
    int size;
    int capacity;
}
typedef struct heap_struct *priorityQueue;

priorityQueue initialize(int max){
    priorityQueue H;
    if (max < min){
        printf("Size is too small");
    }
    else{
        H = (priorityQueue*)malloc(sizeof(struct heap_struct));
        if (H == NULL){
            printf("factal Error");
        }
        else{
            H->elements = (int*)malloc(sizeof(int) * (max + 1));
            if(H->elements == NULL){
                printf("Factal Error");
            }
            else{
                H->elements[0] = mindata;
                H->size = 0;
                H->capacity = max;
                return H;
            }
        }
    }
    return NULL;
}

int isfull(priorityQueue H){
    return H->size == H->capacity;
}

int isempty(priorityQueue H){
    return H->size == 0;
}

void insert(priorityQueue H, int X){
    int i;
    if(isfull(H)){
        printf("Queue is full");
    }
    else{
        for(i = ++H->size; H->elements[i/2] > X; i = i/2){
            H->elements[i] = H->elements[i/2];
        }
        H->elements[i] = X;
    }
}

int main(){
    priorityQueue firstqueue = initialize(15);
    insert(firstqueue, 5);
    insert(firstqueue, 3);
}