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
        printf("%d ",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct node* root){
    struct node* temp=root;
    if(temp!=NULL){
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->data);
    }
}

void inorder(struct node* root){
    struct node* temp=root;
    if(temp!=NULL){
        inorder(temp->left);
        printf("%d ",temp->data);
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

struct node* insertNode(struct node* root,int val){
    struct node* new=createNode(val);
    struct node* temp=root;
    if(temp==NULL){
        return new;
    }else{
        struct node* prev=NULL;
        while(temp!=NULL){
            prev=temp;
            if(val==temp->data){
                return NULL;
            }else if(val<temp->data){
                temp=temp->left;
            }else{
                temp=temp->right;
            }
        }
        if(val<prev->data){
            prev->left=new;
        }else{
            prev->right=new;
        }
        return root;
    }
}

struct node* inorderPredecessor(struct node* root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct node* deleteNode(struct node* root, int val) {
    struct node* iPre;
    if (root == NULL)
        return NULL;

    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        iPre = inorderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}


int main(){
    int choice,value;
    struct node* root=NULL;
    while(1){
        printf("Enter\n1 for Insertion\n2 for Deletion\n3 for Inorder\n4 for Preorder\n5 for Postorder\n6 for Search\n7 for EXIT\n");
        scanf("%d",&choice);
        switch(choice){
        case 1: printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
        case 2: printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
        case 3: printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
        case 4: printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
        case 5: printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
        case 6: printf("Enter element to be searched: ");
                scanf("%d",&value);
                printf("Element Found: %d\n",search(root,value));
                break;
        case 7: exit(0);
                break;
        default:printf("Invalid Input");
                break;
        }
    }
    return 0;
}