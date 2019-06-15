#include <stdio.h>
int SomeOfElement(int A[]){
    int size= sizeof(A)/sizeof(A[0]);
    printf("SomeOfElement: Size of A: %d, size of A[0]=%d\n", sizeof(A),sizeof(A[0]));
    int sum=0;
    for(int i=0; i<size;i++){
        sum+=A[i];
    }
    return sum;
}
main(){
    int A[]={2,3,4,5,6,7};
    printf("Main: Size of A: %d, size of A[0]=%d\n", sizeof(A),sizeof(A[0]));
    //size= sizeof(A)/sizeof(A[0]);
    int total=SomeOfElement(A);
    printf("Some Of Element: %d",total);
}
