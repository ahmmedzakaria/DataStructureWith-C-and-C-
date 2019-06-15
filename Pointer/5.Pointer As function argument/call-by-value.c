#include <stdio.h>

increment(int a){
    a=a+1;
}
main(){
    int a=10;
    increment(a);
    printf("Value of a is: %d\n",a);
}
