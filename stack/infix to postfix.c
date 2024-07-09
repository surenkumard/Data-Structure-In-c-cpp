#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack_record {
    char *arr;
    int top;
    int capa;
};

typedef struct stack_record *stack;

stack create(int max) {
    stack s;
        s = (stack)malloc(sizeof(struct stack_record));
        s->arr = (char *)malloc(sizeof(int) * max);
        s->top = -1;
        s->capa = max;
        return s;
}

int isempty(stack s) {
    return (s->top == -1);
}

int isfull(stack s) {
    return (s->top == s->capa - 1);
}

void push(stack s, char val) {
    if (!isfull(s)) {
        s->arr[++s->top] = val;
    } else {
        printf("Stack overflow\n");
    }
}

char popandpeek(stack s) {
    if (isempty(s)) {
        printf("Stack is empty\n");
        return 0;
    } else {
        return s->arr[s->top--];
    }
}

char peek(stack s) {
    if (isempty(s)) {
        printf("Stack is empty\n");
        return 0;
    } else {
        return s->arr[s->top];
    }
}

int priority(char ch){
    if(ch == '*' || ch == '/'){
        return 2;
    }
    else if(ch == '^'){
        return 3;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
}

char* infixtopostfix(char* infix){

    char *postfix = (char*)malloc(sizeof(char) * strlen(infix));
    int j = 0;

    infix[strlen(infix)] = ')';

    stack aux = create(strlen(infix));
    push(aux, '(');

    for(int i = 0; i < strlen(infix); i++){
        char ch = infix[i];

        if(ch == '('){
            push(aux, ch);
        }
        else if(ch == ')'){
            while(peek(aux) != '('){
                postfix[j++] = popandpeek(aux);
            }
            popandpeek(aux);
        }
        else if(isdigit(ch) || isalpha(ch)){
            postfix[j++] = ch;
        }
        else{
            while(priority(ch) <= priority(peek(aux)) && peek(aux) != '('){
                postfix[j++] = popandpeek(aux);
            }
            push(aux, ch);
        }
    }
    postfix[j] = '\0';
    return postfix;
}

void main(){
    char str[100];
    printf("Enter a infix expression :");
    scanf("%[^\n]", str);

    char *post = infixtopostfix(str);

    printf("postfix expression %s", post);
}