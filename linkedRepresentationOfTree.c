#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void preorder(struct node* root){
    struct node* temp=root;
    if(temp!=NULL){
        printf("%d\t",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct node* root){
    struct node* temp=root;
    if(temp!=NULL){
        postorder(temp->left);
        postorder(temp->right);
        printf("%d\t",temp->data);
    }
}

void inorder(struct node* root){
    struct node* temp=root;
    if(temp!=NULL){
        inorder(temp->left);
        printf("%d\t",temp->data);
        inorder(temp->right);
    }
}

int isBST(struct node* root){
    struct node* prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }else{
        return 1;
    }
}

int search(struct node* root,int key){
    if(root==NULL){
        return 0;
    }
    if(root->data==key){
        return root->data;
    }else if(root->data>key){
        return search(root->left,key);
    }else if(root->data<key){
        return search(root->right,key);
    }else{
        return -1;
    }
}

void insert(struct node* root,int key){
    struct node* prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            return;
        }else if(key<root->data){
            root=root->left;
        }else{
            root=root->right;
        }
    }
    struct node* new=createNode(key);
    if(key<prev->data){
        prev->left=new;
    }else{
        prev->right=new;
    }
}

int main(){
    //Creating Nodes
    struct node* p=createNode(9);
    struct node* p1=createNode(4);
    struct node* p2=createNode(11);
    struct node* p3=createNode(2);
    struct node* p4=createNode(7);
    struct node* p5=createNode(5);
    struct node* p6=createNode(8);
    struct node* p7=createNode(15);
    struct node* p8=createNode(14);

    //Linking them
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p4->left=p5;
    p4->right=p6;
    p2->right=p7;
    p7->left=p8;
    
    //Printing the inorder,preorder and postorder sequence
    printf("Inorder Sequence before insertion:-\n");
    inorder(p);
    for(int i=-1;i<=1;i++){
        insert(p,i);
    }
    printf("\nInorder Sequence after insertion:-\n");
    inorder(p);
    return 0;
}