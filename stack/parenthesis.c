#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack_record{
    char *arr;
    int top;
    int capa;
};

typedef struct stack_record *stack;

void display(stack s){
        printf("The aray elements are :");
        for(int i = 0; i <= s->top;i++){
            printf("%c ",s->arr[i]);
        }
}

int isempty(stack s){
    return s->top == -1;
}

int isfull(stack s){
    return s->top == s->capa - 1;
}

void push(stack s, char ch){
    if(!isfull(s)){
        s->arr[++s->top] = ch;
    }
}

char popandpeek(stack s){
    if(isempty(s)){
        return '\0';
    }
    else{
        return s->arr[s->top--];
    }
}

stack create(int max){
    stack s = (stack)malloc(sizeof(struct stack_record));
    s->arr = (char*)malloc(sizeof(char) * max);
    s->top = -1;
    s->capa = max;
    return s;
}

int parentheses(char *exp){
    stack s = create(strlen(exp));

    while(*exp){
        char ch = *exp++;
        if(ch == '(' || ch == '{' || ch == '['){
            push(s, ch);
        }
        else if(ch == ')' || ch == ']' || ch == '}'){
            char temp = popandpeek(s);

            if(ch == ')' && temp != '('){
                return 0;
            }
            else if(ch == ']' && temp != '['){
                return 0;
            }
            else if(ch == '}' && temp != '{'){
                return 0;
            }
        }
    }

    if(!isempty(s)){
        return 0;
    }
    return 1;
}

#define MAX_LENGTH 100
int main(){
    char *exp = (char *)malloc(sizeof(char) * (MAX_LENGTH + 1));

    printf("Enter a Expression : ");
    scanf("%[^\n]",exp);

    int result = parentheses(exp);

    if(result){
        printf("\nThe Expression are well Balanced");
    }
    else{
        printf("\nNot a Valid Expression");
    }
    return 0;
}
