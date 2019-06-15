#include <stdio.h>
void Hello(char* c){
    printf("Hello %s\n",c);
}
int main(){
    void (*p)(char*);
    p=Hello;
    p("Zakaria");

}
