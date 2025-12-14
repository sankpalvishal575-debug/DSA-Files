#include <stdio.h>
#include <stdlib.h>

void countSortDigit(int *a, int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (a[i] / exp) % 10;
        count[digit]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }
}

void radixSort(int* a,int n){
    if (n <= 0) return;

    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSortDigit(a, n, exp);
    }
}

void display(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
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
    radixSort(a,n);
    printf("\nAfter Sort:-\n");
    display(a,n);
    return 0;
}
