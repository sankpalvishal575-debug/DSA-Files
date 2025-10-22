#include <stdio.h>
#include <stdlib.h>

void display(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}

void countSort(int* a,int n){
    int max=0,k=0,j=0;
    for(int i=0;i<n;i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    int* count=(int*)malloc((max+1)*sizeof(int));
    for(int i=0;i<=max;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    while(k<=max){
        if(count[k]>0){
            a[j]=k;
            count[k]--;
            j++;
        }else{
            k++;
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
    countSort(a,n);
    printf("\nAfter Sort:-\n");
    display(a,n);
    return 0;
}