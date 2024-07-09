#include <stdio.h>
#include <stdlib.h>

typedef struct node_rec{
    struct node_rec *lptr;
    int data;
    struct node_rec *rptr;
}*node;

node temp, new, prev;
typedef node header;
header h;

void create(){
    h->data = h->lptr = head->rptr = NULL;
}
void insertbeg(int val){
    new = (node)malloc(sizeof(struct node_rec));
    new->data = val;
    new->rptr = h->rptr;
    new->lptr = h;

    h->rptr = new;
    if(new->rptr != NULL){
        new->rptr->lptr = new;
    }
}

void insertend(int val){
    new = (node)malloc(sizeof(struct node_rec));
    new->data = val;
    new->rptr = NULL;

    temp = h;
    while(temp->rptr != NULL){
        temp = temp->rptr;
    }

    new->lptr = temp;
    temp->rptr = new;
}

void insertmid(int pos, int val){
    new = (node*)malloc(sizeof(struct node_rec));
    new->data = val;
    int i = 1;
    temp = h;

    while(temp->rptr != NULL && i < pos){
        temp = temp->rptr;
        i++;
    }
    new->rptr = temp->rptr;
    new->lptr = temp;
    temp->rptr = new;

    if(new->rptr != NULL){
        new->rptr->lptr = new;
    }
}

void deletebyval(int val){
    temp = h->rptr;
    prev = h;
    while(temp != NULL && temp->data != val){
        prev = temp;
        temp = temp->rptr;
    }
    if(temp == NULL){
        printf("\nValue not found");
    }
    else{
        prev->rptr = temp->rptr;
        if(temp->rptr != NULL){
            temp->rptr->lptr = new;
        }
        free(temp);
    }
}

void displayList() {
    temp = h->rptr;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->rptr;
    }
    printf("NULL\n");
}

void search(int val) {
    int pos = 1;
    temp = h->rptr;
    while (temp != NULL && temp->data != val) {
        temp = temp->rptr;
        pos++;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list\n", val);
    } else {
        printf("Value %d found at position %d\n", val, pos);
    }
}

int main() {
    create();

    int choice, val, pos;

    do {
        printf("\n----- Doubly Linked List Menu -----\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete by value\n");
        printf("5. Display List\n");
        printf("6. Search\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &val);
                insertbeg(val);
                break;

            case 2:
                printf("Enter value to insert at the end: ");
                scanf("%d", &val);
                insertend(val);
                break;

            case 3:
                printf("Enter position and value to insert at a specific position: ");
                scanf("%d %d", &pos, &val);
                insertmid(pos, val);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deletebyval(val);
                break;

            case 5:
                displayList();
                break;

            case 6:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(val);
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 0);

    return 0;
}