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

void bubbleSort(int* a,int n){
    int isSorted;
    for(int i=0;i<n-1;i++){
        isSorted=1;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                isSorted=0;
            }
        }
        if(isSorted==1){
            return;
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
    bubbleSort(a,n);
    printf("\nAfter Sort:-\n");
    display(a,n);
    return 0;
}