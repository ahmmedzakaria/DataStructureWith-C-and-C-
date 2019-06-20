#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

void Reverse(char *C, int length){
    stack<char> charStack;
    for(int i=0; i<length; i++){
        charStack.push(C[i]);
    }

    for(int i=0; i<length; i++){
        C[i]=charStack.top();
        charStack.pop();
    }
}

int main(){
    char C[51];
    printf("Enter a String \n");
    gets(C);
    Reverse(C,strlen(C));
    printf("Output: %s",C);
}
