#include <stdio.h>
int compare(int a, int b){
    return (a>b)?-1:1;
}
void BubbleSort(int *A, int size, int (*compare)(int,int)){
    int temp=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(compare(A[j],A[j+1])>0){
                temp =A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
        //printArray(A,size);
    }
}
void printArray(int *A, int size){
    for(int i=0; i<size; i++) printf("%d ",A[i]);
    printf("\n");
}
int main(){
    int A[]={22,11,3,2,1,5,6,4,7};
    int size=9;
    BubbleSort(A,size,compare);
    printArray(A,size);
}
