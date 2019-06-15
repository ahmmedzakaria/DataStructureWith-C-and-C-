#include <stdio.h>
#include <string.h>
main(){
    char C[5];
    C[0]='J';
    C[1]='O';
    C[2]='H';
    C[3]='N';
    C[4]='\0';
    printf("%s\n",C);
    int len= strlen(C);
    printf("Size=%d\n",sizeof(C));
    printf("Length=%d\n",len);
}
