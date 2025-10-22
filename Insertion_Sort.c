#include <stdio.h>

void display(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}

void swap(int* a,int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void insertionSort(int* a,int n){
    //loop for each step
    for(int i=1;i<=n-1;i++){
        //loop for each step
        int key=a[i];
        int j=i-1;
        while((a[j]>key)&&(j>=0)){
            swap(&a[j+1],&a[j]);
            j--;
        }
    }
}

int main(){
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Before Sort:-\n");
    display(a,n);
    insertionSort(a,n);
    printf("\nAfter Sort:-\n");
    display(a,n);
    return 0;
}