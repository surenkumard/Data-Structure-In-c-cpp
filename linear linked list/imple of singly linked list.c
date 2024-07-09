#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *link;
}*node;


node head, temp, new, prev;
void create(){
    head = NULL;
}

void insertbeg(int val, node head){
    new = (node)malloc(sizeof(struct NODE));
    new->data = val;
    new->link = head;
    head = new;
    new = NULL;
}

void insertend(int val, node head){
    new = (node)malloc(sizeof(struct NODE));
    new->data = val;
    new->link = NULL;

    if(head == NULL){
        head = new;
        return;
    }

    temp = head;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = new;
}

void insertmid(int val,int pos, node head){
    new = (node)malloc(sizeof(struct NODE));
    new->data = val;
    new->link = NULL;

    int i = 1;
    temp = head;
    prev = temp;

   while(temp != NULL && i < pos-1){
        prev = temp;
        temp = temp->link;
        i++;
    }

    if(temp == head){
        new->link = head;
        head = new;
    }
    else if(temp != NULL){
        new->link = temp->link;
        temp->link = new;
    }
    else{
        // printf("\nThe position overflow");
        prev->link = new;
    }
}
void display(node head){
    printf("\nTHE LINKED LIST IS : ");
    temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
}

void deletebyval(node head, int val){
    temp = head;
    prev = NULL;
    while(temp != NULL && temp->data != val){
        prev = temp;
        temp = temp->link;
    }
    if(temp == NULL){
        printf("\nValue not found");
    }
    else if(prev == NULL){
        head = head->link;
    }
    else{
        prev->link = temp->link;
    }
    free(temp);
    prev = NULL;
}

int search(node head, int val){
    temp = head;
    int i = 1;
    while(temp != NULL){
        if(temp->data == val){
            return i;
        }
        temp = temp->link;
        i++;
    }
    return -1;
}

void dispose(node head){
    temp = head;
    while(head != NULL){
        head = head->link;
        free(temp);
        temp = head;
    }
    free(temp);
}

int main() {
    int choice, val, pos, result;

    do {
        printf("\n\n----- Linked List Operations Menu -----\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Display the linked list\n");
        printf("5. Delete by value\n");
        printf("6. Search for a value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", val);
                insertbeg(val, head);
                break;

            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", val);
                insertend(val, head);
                break;

            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", val);
                printf("Enter the position to insert at: ");
                scanf("%d", pos);
                insertmid(val, pos, head);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Enter the value to delete: ");
                scanf("%d", val);
                deletebyval(val, head);
                break;

            case 6:
                printf("Enter the value to search: ");
                scanf("%d", val);
                result = search(head, val);
                if (result != -1) {
                    printf("Value found at position %d\n", result);
                } else {
                    printf("Value not found\n");
                }
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }

    } while (choice != 7);

    // Clean up memory
    dispose(head);

    return 0;
}
