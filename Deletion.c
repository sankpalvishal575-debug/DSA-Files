#include <stdio.h>
void delete(int arr[],int size,int index);
int main(){
    int arr[100];
    int size,index;
    printf("Enter size: ");
    scanf("%d", &size);
    printf("Enter array elements: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter index to be deleted: ");
    scanf("%d",&index);
    printf("Array before deletion: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    delete(arr,size,index);
    printf("Array after deletion: ");
    for(int i=0;i<size-1;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
void delete(int arr[],int size,int index){
    for(int i=index;i<=size-1;i++){
        arr[i]=arr[i+1];
    }
}