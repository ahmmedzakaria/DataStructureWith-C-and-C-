#include <stdio.h>

struct Node{
    int data;
    Node* next;
};
struct Node* head;

void insert(int data, int position){
    Node* newNode=new Node();
    newNode->data=data;
    newNode->next=NULL;
    if(position == 1){
        newNode->next=head;
        head=newNode;
        return;
    }
    Node* beforeNodePos = head;
    for (int i=0; i<position-2; i++){
        beforeNodePos=beforeNodePos->next;
    }
    newNode->next=beforeNodePos->next;
    beforeNodePos->next=newNode;
}
void print(Node* ptr){
    if(ptr == NULL){
        printf("\n");
        return;
    }
    printf("%d ",ptr->data);
    print(ptr->next);
}
void printReverse(Node* ptr){
    if(ptr == NULL){
        printf("\nPrinting in Reverse\n");
        return;
    }
    printReverse(ptr->next);
    printf("%d ",ptr->data);
}
main(){
    head=NULL;
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,2);
    print(head);
    printReverse(head);
}

