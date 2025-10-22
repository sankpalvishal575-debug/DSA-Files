#include <stdio.h>
#include <stdlib.h>

struct cq{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct cq* q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct cq* q){
    if(q->f==q->r){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct cq* q, int val){
    if(isFull(q)){
        printf("Queue is full");
    }else{
        q->r= (q->r+1)%q->size;
        q->arr[q->r]=val;
        if(q->f==-1){
            q->f++;
        }
    }
}

int dequeue(struct cq* q){
    int temp=q->arr[q->f];
    if(isEmpty(q)){
        printf("Queue is Empty");
        return 0;
    }else{
        q->f= (q->f+1)%q->size;
        return temp;
    }
}

void display(struct cq* q){
    if(isEmpty(q)){
        printf("Queue is empty");
    }else{
        if(q->f==q->size-1){
            for(int i=q->f;i<=q->size-1;i++){
                printf("%d\t",q->arr[i]);
            }
            for(int i=0;i<=q->r;i++){
                printf("%d\t",q->arr[i]);
            }
            printf("\n");
        }else{
            for(int i=q->f;i<=q->r;i++){
                printf("%d\t",q->arr[i]);
            }
            printf("\n");
        }
    }
}

int main(){
    struct cq q;
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