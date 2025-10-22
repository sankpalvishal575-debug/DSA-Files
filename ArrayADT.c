#include <stdio.h>
#include <stdlib.h>
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a,int tSize,int uSize){
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr= (int*) calloc(tSize,sizeof(int));
}

void showArray(struct myArray *a){
    for(int i=0;i< a->used_size;i++){
        printf("%d student marks is: %d\n",i+1,(a->ptr)[i]);
    }
}

void setArray(struct myArray *a){
    int n;
    for(int i=0;i< a->used_size;i++){
        printf("Enter %d student marks: ",i+1);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}

int main(){
    int total,class;
    struct myArray *ptr;
    struct myArray marks;
    ptr=&marks;
    printf("Total Students in Institute: ");
    scanf("%d",&total);
    printf("Total Students in your class: ");
    scanf("%d",&class);
    createArray(ptr,total,class);
    setArray(ptr);
    showArray(ptr);
    return 0;
}