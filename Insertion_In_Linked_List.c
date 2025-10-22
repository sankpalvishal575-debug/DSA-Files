#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void display(struct Node* ptr){
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertAtFirst(struct Node* head, int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node*));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

struct Node* insertAtIndex(struct Node* head, int data,int index){
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

struct Node* insertAtEnd(struct Node* head, int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node*));
    ptr->data=data;
    struct Node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->next=NULL;
    p->next=ptr;
    return head;
}

int main(){
    //Creating a Linked List
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

    //Terminating Linked List
    fifth->data=144;
    fifth->next=NULL;

    printf("Linked List before insetion:- \n");
    display(head);
    head=insertAtFirst(head,69);
    printf("\n Linked List after insetion at first:- \n");
    display(head);
    head=insertAtIndex(head,70,3);
    printf("\n Linked List after insetion at index:- \n");
    display(head);
    head=insertAtEnd(head,71);
    printf("\n Linked List after insetion at end:- \n");
    display(head);
    return 0;
}