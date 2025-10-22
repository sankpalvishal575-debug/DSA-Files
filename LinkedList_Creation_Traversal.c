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
int main(){
    //Creating a Linked List
    struct Node* head;
    struct Node* second;
    struct Node* third;

    //Allocation of memory for nodes in heap;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    //Linking First Node to Second
    head->data=7;
    head->next=second;

    //Linking Second Node to Third
    second->data=8;
    second->next=third;

    //Terminating Linked List
    third->data=11;
    third->next=NULL;

    //Traversal in Linked List
    display(head);
    return 0;
}