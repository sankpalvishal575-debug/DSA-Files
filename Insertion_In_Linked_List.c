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
    printf("\n");
}

struct Node* insertAtFirst(struct Node* head, int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node*));
    ptr->next=head->next;
    head->next=ptr;
    ptr->data=data;
    return head;
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
    struct Node* head;
    head->next=NULL;
    int val[3],choice,i;
    while(1){
        printf("Enter\n1 for Insert at Begining\n2 for Insert at Index\n3 for Insert at End\n4 for Display\n5 for EXIT\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter value to be inserted: ");
                    scanf("%d",&val[0]);
                    insertAtFirst(head,val[0]);
                    break;
            case 2: printf("Enter value to be inserted: ");
                    scanf("%d",&val[1]);
                    printf("Enter index: ");
                    scanf("%d",&i);
                    insertAtIndex(head,val[1],i);
                    break;
            case 3: printf("Enter value to be inserted: ");
                    scanf("%d",&val[2]);
                    insertAtEnd(head,val[2]);
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
