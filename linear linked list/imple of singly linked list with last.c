#include <stdio.h>
#include <stdlib.h>

struct noderec{
    int info;
    struct node *next;
};

typedef struct noderec *node;

node start, last, temp, new, prev;

int isempty(){
    return start == NULL;
}
void create(){
    start = last = NULL;
}

void insertbeg(int val){
    new = (struct noderec*)mallac(sizeof(struct noderec));
    new->info = val;
    new->next = start;
    start = new;

    if(last == NULL){
        last = new;
    }
}

void insertlast(int val){
    new = (struct noderec*)mallac(sizeof(struct noderec));
    new->info = val;
    new->next = NULL;

    if(isempty()){
        start = last = new;
    }
    else{
        last->next = new;
        last = new;
    }
}

void insertpos(int val, int pos){
    int i = 1;
    new = (struct noderec*)mallac(sizeof(struct noderec));
    new->info = val;
    new->next = NULL;
    
    if(isempty()){
        start = last = new;
    }
    else{
        temp = start;
        while(temp != NULL && i < pos - 1){
            temp = temp->next;
            i++;
        }

        if(temp == start){
            new->next = start;
            start = new;
        }
        else if(temp == NULL){
            last->next = new;
            last = new;
        }
        else{
            new->next = temp->next;
            temp->next = new;
        }
    }
}

void display(){
    if(isempty()){
        printf("\nlinked list is empty");
    }
    else{
        printf("\nThe linked list : ");
        temp = start;
        while(temp != NULL){
            print("%d ", temp->val);
            temp = temp->next;
        }
    }
}

void delectbeg(){
     if(isempty()){
        printf("\nlinked list is empty");
     }
     else{
        temp = start;
        if(start == last){
            start = last = NULL;
        }
        else[
            start = start->next;
        ]
        free(temp);
     }
}