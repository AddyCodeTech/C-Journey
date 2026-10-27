#include<stdio.h>

int main(){
    int size, ar[100];
    printf("Enter the size of an array: ");
    scanf("%d",&size);
    printf("\nEnter the elements: \n");
    for(int i=0;i<size;i++){
        scanf("%d",&ar[i]);
    }
    printf("\nDisplaying: ");
    for(int i=0;i<size;i++){
        printf("%d ",ar[i]);
    }
    int max=ar[0];
    for(int i=0;i<size;i++){
        if(ar[i]>max){
            max=ar[i];
        }
    }
    int count[max+1];
    int output[size];
    for(int i=0;i<=max;i++){
        count[i]=0;
    }
    for(int i=0;i<size;i++){
        count[ar[i]]++;
    }
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
    for(int i=size-1;i>=0;i++){
        output[count[ar[i]]]=ar[i];
        count[ar[i]]--;
    }
    printf("\nSorted Array: ");
    for(int i=0;i<size;i++){
        printf("%d ",ar[i]);
    }
    return 0;
}
