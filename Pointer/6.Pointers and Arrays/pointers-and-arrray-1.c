#include <stdio.h>
main(){
int A[]={2,3,4,5,6,7};
printf("Start Address of Array A is: %d\n",A);
printf("Address of &A[0] is: %d\n",&A[0]);

printf("\n First Element of the array:\n");
printf("Printing Value Using A[0]: %d\n",A[0]);
printf("Printing Value Using *A: %d\n",*A);

printf("\nPrinting Array Address and value using &A[i],A[i]\n");
for(int i=0;i<6;i++){
    printf("Address: %d, Value: %d\n",&A[i],A[i]);
}

printf("\nPrinting Array Address and value using &A[i],A[i]\n");
for(int i=0;i<6;i++){
    printf("Address: %d, Value: %d\n",A+i,*(A+i));
}
//Note:
//sA++ //A++ is invalid
int* p=A;
p++ // After assigning Array pointer into another pointer variable increment is valid.
}
