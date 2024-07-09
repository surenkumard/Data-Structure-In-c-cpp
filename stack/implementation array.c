#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1
#define MIN_SIZE 2

struct stack_record {
    int *arr;
    int top;
    int capa;
};

typedef struct stack_record *stack;

stack create(int max) {
    stack s;
    if (max < MIN_SIZE) {
        printf("Array size too small\n");
        return NULL;
    } else {
        s = (stack)malloc(sizeof(struct stack_record));
        if (s == NULL) {
            printf("Memory Allocation Error\n");
            return NULL;
        } else {
            s->arr = (int *)malloc(sizeof(int) * max);
            if (s->arr == NULL) {
                printf("Memory Allocation Error\n");
                free(s);
                return NULL;
            } else {
                s->top = EMPTY;
                s->capa = max;
                return s;
            }
        }
    }
}

void dispose(stack s) {
    if (s != NULL) {
        free(s->arr);
        free(s);
        s = NULL;
    }
}

void display(stack s) {
    printf("The array elements are: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int isempty(stack s) {
    return (s->top == EMPTY);
}

int isfull(stack s) {
    return (s->top == s->capa - 1);
}

void push(stack s) {
    if (!isfull(s)) {
        int num;
        printf("Enter the number: ");
        scanf("%d", &num);
        s->arr[++s->top] = num;
    } else {
        printf("Stack overflow\n");
    }
}

void pop(stack s) {
    if (isempty(s)) {
        printf("Stack is empty\n");
    } else {
        s->top--;
    }
}

int peek(stack s) {
    if (isempty(s)) {
        printf("Stack is empty\n");
        return 0;
    } else {
        return s->arr[s->top];
    }
}

int popandpeek(stack s) {
    if (isempty(s)) {
        printf("Stack is empty\n");
        return 0;
    } else {
        return s->arr[s->top--];
    }
}

int main() {
    int ch, max, val, num;
    printf("Enter the max element in the stack: ");
    scanf("%d", &max);
    stack s = create(max);

    if (s == NULL) {
        printf("factal error");
        return 1; // Indicate failure
    }

    do {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Pop and Peek");
        printf("\n6. Dispose\n");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push(s);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                val = peek(s);
                if (val != 0) {
                    printf("Top of the element is = %d\n", val);
                }
                break;
            case 4:
                display(s);
                break;
            case 5:
                num = popandpeek(s);
                if (num != 0) {
                    printf("The removed element from the stack is %d\n", num);
                }
                break;
            case 6:
                dispose(s);
                break;
        }
    } while (ch != 6);

    return 0; // Indicate success
}
