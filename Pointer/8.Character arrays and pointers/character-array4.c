#include <stdio.h>
#include <string.h>
main(){
    char C[]= {'O','P','U','\0'};
    //char C[]= {'O','P','U',}; //Print some extra garbage value
    printf("%s\n",C);
    int len= strlen(C);
    printf("Size=%d\n",sizeof(C));
    printf("Length=%d\n",len);
}
