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

struct Node* deleteAtFirst(struct Node* head){
    struct Node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct Node* deleteAtIndex(struct Node* head,int index){
    struct Node* p=head;
    struct Node* q=head->next;
    for(int i=0;i<index-1;i++){
        q=q->next;
        p=p->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct Node* deleteAtEnd(struct Node* head){
    struct Node* p=head;
    struct Node* q=head->next;
    while(q->next!=NULL){
        q=q->next;
        p=p->next;
    }
    p->next=NULL;
    free(q);
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

    printf("Linked List before deletion:- \n");
    display(head);
    head=deleteAtIndex(head,3);
    printf("\nLinked List after deletion:- \n");
    display(head);
    return 0;
}