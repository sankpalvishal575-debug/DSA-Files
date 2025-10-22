#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char* arr;
};

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int isEmpty(struct stack* ptr){
    if(ptr->top==-1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct stack* ptr){
    if(ptr->top==(ptr->size)-1){
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack* ptr,char val){
    if(isFull(ptr)==1){
        printf("Stack is full");
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)==1){
        printf("Stack is Empty");
        return -1;
    }else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack* sp,int i){
    int index=sp->top-i+1;
    if(index<0){
        printf("Invalid Index");
        return -1;
    }else{
        return sp->arr[index];
    }
}

int prec(char ch){
    if(ch=='*' || ch=='/'){
        return 3;
    }else if(ch=='+' || ch=='-'){
        return 2;
    }else{
        return 0;
    }
}

int isOperator(char ch){
    if(ch=='/' || ch=='*' || ch=='+' || ch=='-'){
        return 1;
    }else{
        return 0;
    }
}

char* infixConversion(char* infix){
    struct stack* sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    char* postfix=(char*)malloc(100*sizeof(char));
    int i=0; //Track infix expression
    int j=0; //track postfix operations
    while(infix[i]!='\0'){
        if(isOperator(infix[i])!=1){
            postfix[j]=infix[i];
            i++;
            j++;
        }else{
            if(prec(infix[i])>prec(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(isEmpty(sp)!=1){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char* infix="x-y/z-k*d";
    printf("Postfix Expression: %s",infixConversion(infix));
    return 0;
}