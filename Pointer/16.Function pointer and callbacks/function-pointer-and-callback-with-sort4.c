#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(const void* a, const void* b){
    int A=*((int*)a);
    int B=*((int*)b);
    return A-B;
    //return B-A;
    //return abs(A)-abs(B);
}

void printArray(int *A, int size){
    for(int i=0; i<size; i++) printf("%d ",A[i]);
    printf("\n");
}
int main(){
    int A[]={12,-11,-3,2,8,5,6,4,-7};
    int size=9;
    qsort(A,size,sizeof(int),compare);
    printArray(A,size);
}
