#include <stdio.h>
#include <stdlib.h>

typedef struct node_rec{
    int data;
    struct node_rec *next;
}*node;

node temp, prev, new;
typedef node header;
header h;

void create(){
    h = (struct node_rec*)malloc(sizeof(struct node_rec));
    h->next = h;
}

int isempty(){
    return h->next == h;
}

void insertbeg(int val){
    new = (struct node_rec*)malloc(sizeof(struct node_rec));
    new->data = val;
    new->next = h->next;
    h->next = new;
}

void insertend(int val){
    new = (node)malloc(sizeof(struct node_rec));
    new->data = val;
    new->next = h;
    
    temp = h->next;
    while(temp->next != h){
        temp = temp->next;
    }
    temp->next = new;
}

void insertmid(int pos, int val){
    new = (node)malloc(sizeof(struct node_rec));
    new->data = val;
    new->next = NULL;

    int i = 1;
    temp = h->next;

    while(temp->next != h && i < pos - 1){
        temp = temp->next;
        i++;
    }

    new->next = temp->next;
    temp->next = new;
}

int search(int val){
    int i = 1;
    temp = h->next;
    while(temp->next != h){
        if(temp->data == val){
            return i;
        }
        temp = temp->next;
        i++;
    }
    return -1;
}

void delect(int val){
    temp = h->next;
    prev = h;

    while(temp != h && temp->data != val){
        prev = temp;
        temp = temp->next;
    }

    if(temp == h){
        printf("\nElement not Found");
    }
    else{
        prev->next = temp->next;
        free(temp);
    }
}

void display(){
    if (isempty()) {
        printf("\nList is empty.");
        return;
    }

    printf("\nList elements: ");
    temp = h->next;
    while (temp != h) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, val, pos;
    create();

    do {
        printf("\n\n***** Linked List Menu *****");
        printf("\n1. Insert at the beginning");
        printf("\n2. Insert at the end");
        printf("\n3. Insert at a specific position");
        printf("\n4. Search for an element");
        printf("\n5. Delete an element");
        printf("\n6. Display the list");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to be inserted: ");
                scanf("%d", &val);
                insertbeg(val);
                break;
            case 2:
                printf("\nEnter the value to be inserted: ");
                scanf("%d", &val);
                insertend(val);
                break;
            case 3:
                printf("\nEnter the position to insert: ");
                scanf("%d", &pos);
                printf("\nEnter the value to be inserted: ");
                scanf("%d", &val);
                insertmid(pos, val);
                break;
            case 4:
                printf("\nEnter the value to search: ");
                scanf("%d", &val);
                pos = search(val);
                if (pos != -1)
                    printf("\nElement found at position %d", pos);
                else
                    printf("\nElement not found");
                break;
            case 5:
                printf("\nEnter the value to be deleted: ");
                scanf("%d", &val);
                delect(val);
                break;
            case 6:
                display();
                break;
            case 7:
                printf("\nExiting the program.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid option.");
        }
    } while (choice != 7);

    return 0;
}
