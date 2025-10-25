#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct Queue* q){
    if(q->f==-1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct Queue* q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }else{
        return 0;
    }
}

void enququeFront(struct Queue* q,int val){
    if(isFull(q)){
        printf("Queue is full");
    }
    if(q->f==-1){
        q->f=q->r=0;
    }else if(q->f==0){
        q->f=q->size-1;
    }else{
        q->f--;
    }
    q->arr[q->f]=val;
}

void enququeRear(struct Queue* q,int val){
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

int deququeFront(struct Queue* q){
    int temp=q->arr[q->f];
    if(isEmpty(q)){
        printf("Queue is Empty");
        return 0;
    }else{
        q->f= (q->f+1)%q->size;
        return temp;
    }
}

int deququeRear(struct Queue* q){
    int temp=q->arr[q->r];
    if(isEmpty(q)){
        printf("Queue is empty");
        return 0;
    }else{
        if(q->f==q->r){
            q->f=q->r=-1;
        }else if(q->r==0){
            q->r=q->size-1;
        }else{
            q->r--;
        }
        return temp;
    }
}

void display(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty");
    }else{
        if(q->f>q->r){
            for(int i=q->f;i<=q->size-1;i++){
                printf("%d\t",q->arr[i]);
            }
            for(int i=0;i<=q->r;i++){
                printf("%d\t",q->arr[i]);
            }
        }else{
            for(int i=q->f;i<=q->r;i++){
                printf("%d\t",q->arr[i]);
            }
        }
    }
    printf("\n");
}

int main(){
    struct Queue q;
    q.f=-1;
    q.r=-1;
    q.size=100;
    q.arr=(int*)malloc(q.size*sizeof(int));
    int val,choice;
    while(1){
        printf("Enter\n1 for Enqueue Front\n2 for Enqueue Rear\n3 for Dequeue Front\n4 for Dequeue Rear\n5 for display\n6 for EXIT\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter value to be inserted: ");
                    scanf("%d",&val);
                    enququeFront(&q,val);
                    break;
            case 2: printf("Enter value to be inserted: ");
                    scanf("%d",&val);
                    enququeRear(&q,val);
                    break;
            case 3: deququeFront(&q);
                    break;
            case 4: deququeRear(&q);
                    break;
            case 5: display(&q);
                    break;
            case 6: exit(0);
                    break;
            default:printf("Invalid Input");
        }
    }
    return 0;
}