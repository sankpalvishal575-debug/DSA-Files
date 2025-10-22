#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int* arr;
};

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

void push(struct stack* ptr,int val){
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

int main(){
    struct stack* sp =(struct stack*)malloc(sizeof(struct stack*));
    sp->top=-1;
    sp->size=10;
    sp->arr= (int*)malloc(sp->size*sizeof(int));
    printf("Testing functions:-\n");
    printf("%d\n",isFull(sp));
    printf("%d\n",isEmpty(sp));
    for(int i=1;i<=sp->size;i++){
        push(sp,i);
    }
    printf("After push:-\n");
    printf("%d\n",isFull(sp));
    printf("%d\n",isEmpty(sp));
    for(int i=1;i<=5;i++){
        pop(sp);
    }
    printf("After pop:-\n");
    printf("%d\n",isFull(sp));
    printf("%d\n",isEmpty(sp));
    printf("Testing peek opreation:-\n");
    for(int i=sp->top+1;i>=1;i--){
        printf("%d\t",peek(sp,i));
    }
    return 0;
}