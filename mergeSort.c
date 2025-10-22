#include <stdio.h>

void display(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}

void merge(int* a,int mid,int low,int high){
    int i,j,k,b[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;k++;
        }else{
            b[k]=a[j];
            j++;k++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
        i++;k++;
    }
    while(j<=high){
        b[k]=a[j];
        j++;k++;
    }
    for (int i=low;i<=high;i++){
        a[i]=b[i];
    }
    
}

void mergeSort(int* a,int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);   
        merge(a,mid,low,high);
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
    mergeSort(a,0,n-1);
    printf("\nAfter Sort:-\n");
    display(a,n);
    return 0;
}