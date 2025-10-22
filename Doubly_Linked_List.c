#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

void display(struct Node* head){
    struct Node* ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}

void reverse(struct Node* head){
    struct Node* ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->prev;
    }
}

int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
    fifth=(struct Node*)malloc(sizeof(struct Node));

    head->data=7;
    head->prev=NULL;
    head->next=second;

    second->data=8;
    second->prev=head;
    second->next=third;

    third->data=11;
    third->prev=second;
    third->next=fourth;
    
    fourth->data=121;
    fourth->prev=third;
    fourth->next=fifth;

    fifth->data=144;
    fifth->prev=fourth;
    fifth->next=NULL;

    printf("Doubly Linked List from head:-\n");
    display(head);
    printf("\nDoubly Linked List from fifth:-\n");
    reverse(fifth);
    return 0;
}