#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void display(struct Node* head){
    struct Node* ptr=head->next;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
}

struct Node* deleteAtFirst(struct Node* head){
    struct Node* ptr=head->next;
    head->next=ptr->next;
    free(ptr);
    return head;
}

struct Node* deleteAtIndex(struct Node* head,int index){
    struct Node* p=head->next;
    struct Node* q=p->next;
    for(int i=1;i!=index-1;i++){
        q=q->next;
        p=p->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct Node* deleteAtEnd(struct Node* head){
    struct Node* p=head->next;
    struct Node* q=p->next;
    while(q->next!=NULL){
        q=q->next;
        p=p->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

int main(){
    struct Node* head;
    struct Node* first;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
    fifth=(struct Node*)malloc(sizeof(struct Node));

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
    fifth->next=NULL;

    int choice,i;
    while(1){
        printf("Enter\n1 for Delete at Begining\n2 for Delete at Index\n3 for Delete at End\n4 for Display\n5 for EXIT\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: deleteAtFirst(head);
                    break;
            case 2: printf("Enter index: ");
                    scanf("%d",&i);
                    deleteAtIndex(head,i);
                    break;
            case 3: deleteAtEnd(head);
                    break;
            case 4: display(head);
                    break;
            case 5: exit(0);
                    break;
            default: printf("Invalid Input\n");
        }
    }
    return 0;
}
