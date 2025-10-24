#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* f=NULL;
struct node* r=NULL;

void enqueue(int val){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        printf("Queue is full");
    }else{
        n->data=val;
        n->next=NULL;
        if(f==NULL){
            f=r=n;
        }else{
            r->next=n;
            r=n;
        }
    }
}

int dequeue(){
    struct node* ptr=f;
    int temp=-1;
    if(f==NULL){
        printf("Queue is empty");
    }else{
        f=f->next;
        free(ptr);
        temp=ptr->data;
    }
    return temp;
}

void display(){
    struct node* temp=f;
    if(f==NULL){
        printf("Queue is empty");
    }else{
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
}

int main(){
    int val,choice;
    while(1){
        printf("Enter\n1 for enqueue\n2 for dequeue\n3 for display\n4 for EXIT\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value to be inserted: ");
                    scanf("%d",&val);
                    enqueue(val);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid Input");
        }
    }
    return 0;
}