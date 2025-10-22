#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct Queue* q){
    if(q->r==q->size-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct Queue* q){
    if(q->f==-1){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct Queue* q, int val){
    if(isFull(q)){
        printf("Queue is full");
    }else{
        q->r++;
        q->arr[q->r]=val;
        if(q->f==-1){
            q->f++;
        }
    }
}

int dequeue(struct Queue* q){
    int temp=q->arr[q->f];
    if(isEmpty(q)){
        printf("Queue is Empty");
        return 0;
    }else{
        q->f++;
        return temp;
    }
}

void display(struct Queue* q){
    for(int i=q->f;i<=q->r;i++){
        printf("%d\t",q->arr[i]);
    }
    printf("\n");
}

int main(){
    struct Queue q;
    q.size=100;
    q.f=-1;
    q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));
    int val,choice;
    while(1){
        printf("Enter 1 for Enqueue\n 2 for Dequeue\n 3 for display\n 4 for Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter value to be inserted: ");
                    scanf("%d",&val);
                    enqueue(&q,val);
                    break;
            case 2: dequeue(&q);
                    break;
            case 3: display(&q);
                    break;
            case 4: exit(0);
                    break;
            default:printf("Invalid Input");
        }
    }
    return 0;
}