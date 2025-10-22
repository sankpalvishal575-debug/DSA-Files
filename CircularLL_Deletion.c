#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void display(struct Node* head){
    struct Node* ptr=head;
    do{
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

struct Node* deleteAtFirst(struct Node* head){
    struct Node* ptr=head;
    struct Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    head=head->next;
    temp->next=head;
    free(ptr);
    return head;
}

struct Node* deleteAtIndex(struct Node* head,int index){
    struct Node* p=head;
    struct Node* q=head;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    for(int i=0;i<index;i++){
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct Node* deleteAtEnd(struct Node* head){
    struct Node* p=head;
    struct Node* q=head;
    int l=0;
    while(q->next!=head){
        q=q->next;
        l++;
    }
    for(int i=0;i<l-1;i++){
        p=p->next;
    }
    p->next=head;
    free(q);
    return head;
}

int main(){
    //Creating a Linked List
    struct Node* head;
    struct Node* first;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;

    //Allocation of memory for nodes in heap;
    head=(struct Node*)malloc(sizeof(struct Node));
    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
    fifth=(struct Node*)malloc(sizeof(struct Node));

    head->data=6;
    head->next=first;

    first->data=7;
    first->next=second;

    second->data=8;
    second->next=third;

    third->data=11;
    third->next=fourth;
    
    fourth->data=121;
    fourth->next=fifth;

    fifth->data=144;
    fifth->next=head;

    printf("Linked List before deletion:- \n");
    display(head);
    head=deleteAtFirst(head);
    printf("\nLinked List after deletion at begining:- \n");
    display(head);
    head=deleteAtIndex(head,3);
    printf("\nLinked List after deletion:- \n");
    display(head);
    head=deleteAtEnd(head);
    printf("\nLinked List after deletion:- \n");
    display(head);
    return 0;
}