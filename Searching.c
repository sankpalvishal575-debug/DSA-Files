#include <stdio.h>
#include <stdlib.h>

int linearSearch(int* arr,int n,int search){
    for(int i=0;i<n;i++){
        if(arr[i]==search){
            return 1;
            break;
        }
    }
    return -1;
}

int binarySearch(int* arr, int low, int high, int search){
    while(low<=high){
        int mid = (low + high) / 2;
        if(arr[mid] == search){
            return 1;
        }
        else if(arr[mid] > search){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int fibonacciSearch(int* arr,int n,int search){
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }
    int offset = -1;
    while (fib > 1) {
        int i = (offset + fib2 < n - 1) ? offset + fib2 : n - 1;
        if (arr[i] < search) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (arr[i] > search) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            return 1;
        }
    }
    if (fib1 && offset + 1 < n && arr[offset + 1] == search){
        return 1;
    }
    return -1;
}

int main(){
    int n,search;
    printf("Enter size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to be searched: ");
    scanf("%d",&search);

    if(linearSearch(arr,n,search)){
        printf("%d element present in array using linear search\n",search);
    }else{
        printf("Element not found\n");
    }

    if(binarySearch(arr,0,n-1,search)){
        printf("%d element present in array using binary search\n",search);
    }else{
        printf("Element not found\n");
    }

    if(fibonacciSearch(arr,n,search)){
        printf("%d element present in array using fibonacci search\n",search);
    }else{
        printf("Element not found\n");
    }
    return 0;
}