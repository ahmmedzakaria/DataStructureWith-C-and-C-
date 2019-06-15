#include <stdio.h>
#include <stdlib.h>
int cash=100;
void play(int bet){
    char C[3]={'J','Q','K'};
    printf("Shuffling ....\n");
    srand(time(NULL));
    for (int i=0;i<5;i++){
        int temp;
        int x = rand()%3;
        int y = rand()%3;
        temp=C[x];
        C[x]=C[y];
        C[y]=temp;
    }
    int playerGuess;
    printf("What is the position of Queen | 1,2 or 3 ?\n");
    scanf("%d",&playerGuess);
    if(C[playerGuess-1]=='Q'){
        cash+=3*bet;
        printf("You Win ! Result = %c %c %c | total cash = %d\n",C[0],C[1],C[2],cash);
    }else{
        cash-=bet;
        printf("You Loose ! Result = %c %c %c | total cash = %d\n",C[0],C[1],C[2],cash);
    }
}
int main(){
    int bet;
    printf("Welcome to the Virtual Casino\n");
    printf("Total cash = %d\n",cash);
    while(cash>0){
        printf("What is your Bet?\n");
        scanf("%d",&bet);
        if(bet==0 || bet > cash) break;
        play(bet);
        printf("\n***********************************************\n");
    }
}
