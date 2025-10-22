#include <stdio.h>
void insert(int arr[], int size,int n,int index);
int main(){
    int arr[100];
    int size,n,index;
    printf("Enter size: ");
    scanf("%d", &size);
    printf("Enter array elements: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter Number and index which is to be inserted: ");
    scanf("%d %d",&n,&index);
    printf("Array before insertion: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    insert(arr,size,n,index);
    printf("Array after insertion: ");
    for(int i=0;i<=size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
void insert(int arr[], int size,int n,int index){
    if (size>=100){
        printf("Insertion not possible");
    }else{
        for(int i=size-1;i>=index;i--){
            arr[i+1]=arr[i];
        }
        arr[index]=n;
    }
    
}