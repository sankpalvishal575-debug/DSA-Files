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

void display(struct stack* sp){
    int i=sp->top;
    while(i!=-1){
        printf("%d\t",sp->arr[i]);
        i--;
    }
}

int main(){
    int val,choice,i;
    struct stack* sp =(struct stack*)malloc(sizeof(struct stack*));
    sp->top=-1;
    sp->size=10;
    sp->arr= (int*)malloc(sp->size*sizeof(int));
    while(1){
        printf("Enter\n1 for Push\n2 for Pop\n3 for peek\n4 for Display\n5 for EXIT\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value to be inserted: ");
                    scanf("%d",&val);
                    push(sp,val);
                    break;
            case 2: pop(sp);
                    break;
            case 3: printf("Enter index from the top: ");
                    scanf("%d",&i);
                    printf("Value at index from the top: %d\n",peek(sp,i));
                    break;
            case 4: display(sp);
                    break;
            case 5: exit(0);
                    break;
            default:printf("Invalid Choice\n"); 
        }
    }
    return 0;
}
