#include <stdio.h>
#include <stdlib.h>

struct Node{
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

struct Node* insertAtFirst(struct Node* head,int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node*));
    ptr->data=data;
    struct Node* p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

struct Node* insertAtIndex(struct Node* head,int data,int index){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node*));
    ptr->data=data;
    struct Node* p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

struct Node* insertAtEnd(struct Node* head,int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node*));
    ptr->data=data;
    struct Node* p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    return head;
}

int main(){
    //Creating a Circular Linked List
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;

    //Allocation of memory for nodes in heap;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
    fifth=(struct Node*)malloc(sizeof(struct Node));

    //Linking First Node to Second
    head->data=7;
    head->next=second;

    //Linking Second Node to Third
    second->data=8;
    second->next=third;

    //Linking Third node to Fourth
    third->data=11;
    third->next=fourth;
    
    //Linking Fourth node to Fifth
    fourth->data=121;
    fourth->next=fifth;

    //Creating Circular Linked List
    fifth->data=144;
    fifth->next=head;

    printf("Circular Linked List before insertion:- \n");
    display(head);
    head=insertAtEnd(head,80);
    printf("\nCircular Linked List after insertion:- \n");
    display(head);
    return 0;
}