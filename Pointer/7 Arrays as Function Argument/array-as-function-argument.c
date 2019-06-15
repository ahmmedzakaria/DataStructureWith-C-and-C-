#include <stdio.h>
int SomeOfElement(int A[], int size){
    int sum=0;
    for(int i=0; i<size;i++){
        sum+=A[i];
    }
    return sum;
}
main(){
    int A[]={2,3,4,5,6};
    int size= sizeof(A)/sizeof(int);
    //size= sizeof(A)/sizeof(A[0]);
    int total=SomeOfElement(A,size);
    printf("Some Of Element: %d",total);
}
