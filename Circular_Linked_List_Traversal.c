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

    printf("Circular Linked List:- \n");
    display(head);
}