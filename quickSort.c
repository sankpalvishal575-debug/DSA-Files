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

int partition(int* a,int low,int high){
    int pivot= a[low];
    int i=low+1;
    int j=high;
    do
    {
        while(a[i]<=pivot){
            i++;
        }
        while(a[j]>=pivot){
            j--;
        }
        if(i<j){
            swap(&a[i],&a[j]);
        }
    } while (i<=j);
    swap(&a[low],&a[j]);
    return j;
}

void quickSort(int* a,int low, int high){
    int partitionIndex; // Index of pivot after partition
    if(low<high){
        partitionIndex=partition(a,low,high);
        quickSort(a,low,partitionIndex-1); // quick sort for left subarray
        quickSort(a,partitionIndex+1,high); // quick sort for right subarray
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
    quickSort(a,0,n-1);
    printf("\nAfter Sort:-\n");
    display(a,n);
    return 0;
}