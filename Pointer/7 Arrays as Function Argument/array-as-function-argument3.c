#include <stdio.h>
void Double(int A[],int size){
    printf("Double: Size of A: %d, size of A[0]=%d\n", sizeof(A),sizeof(A[0]));
    for(int i=0; i<size;i++){
        A[i]=2*A[i];
    }
}
main(){
    int A[]={2,3,4,5,6,7};
    printf("Main: Size of A: %d, size of A[0]=%d\n", sizeof(A),sizeof(A[0]));
    int size= sizeof(A)/sizeof(A[0]);
    Double(A,size);
    for (int i=0; i<size; i++){
        printf("%d\n",A[i]);
    }
}
