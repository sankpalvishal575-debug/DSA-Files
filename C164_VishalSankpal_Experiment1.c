#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left, *right;
};
typedef struct node Node;

Node * createnode(int x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

Node * insert(Node *root,int value)
{
    if(root == NULL){
        return createnode(value);
    }
    if(value < root->data){
        root->left = insert(root->left,value);
    }
    else if(value > root->data){
        root->right = insert(root->right,value);
    }
    return root;
}

void inorder(Node *root){
    if(root != NULL)
   {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(Node *root){
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root){
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

Node *min(Node *node){
    Node *current = node;
    while(current != NULL && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node *deletenode(Node *root,int value){
    if(root == NULL){
        return root;
    }
    if(value < root->data){
        root->left = deletenode(root->left,value);
    }
    else if(value > root->data){
        root->right = deletenode(root->right,value);
    }
    else {
        if(root->left == NULL)
       {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = min(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right,temp->data);
    }
    return root;
}

void main() 
{
    Node* root = NULL;
    int choice, value;
    printf("Binary Search Tree Operations\n");
    while (1) 
   {
        printf("1. Insert\n2. Delete\n3. Display Inorder\n4. Display Preorder\n5. Display Postorder\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
       {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deletenode(root, value);
            break;
        case 3:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
} 
