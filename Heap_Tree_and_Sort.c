#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int* arr, int* size, int val){
    int i = *size;      // position to insert new value
    arr[i] = val;
    (*size)++;          // increase heap size
    // heapify-up (max-heap)
    while(i > 0){
        int parent = (i - 1) / 2;   // 0-based parent
        if(arr[parent] > arr[i]){
            swap(&arr[parent], &arr[i]);
            i = parent;
        }else{
            break;
        }
    }
}

int deleteRoot(int* arr, int* size){
    if (*size <= 0){
        return -1;
    } 

    int root = arr[0];
    arr[0] = arr[*size - 1];
    (*size)--;

    int i = 0;
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < *size && arr[left] < arr[smallest])
            smallest = left;
        if (right < *size && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&arr[i], &arr[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
    return root;
}

void heapSort(int* arr, int n){
    int heap[n];
    int size = 0;
    for(int i = 0; i < n; i++){
        insert(heap, &size, arr[i]);
    }
    for(int i = 0; i < n; i++){
        arr[i] = deleteRoot(heap, &size);
    }
}


void display(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Before Sort:-\n");
    display(arr,n);
    heapSort(arr,n);
    printf("After Sort:-\n");
    display(arr,n);
    return 0;
}