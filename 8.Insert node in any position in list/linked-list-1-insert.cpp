#include <stdio.h>

struct Node{
    int data;
    Node* next;
public:
    void printNode(){
        printf("Data: %d. next: %d Address: %d\n",data,next,this);
    }
    void printNode(Node* head){
        printf("Data: %d\tnext: %d\t Address: %d\t Head: %d\n",data,next,this,head);
    }
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
    beforeNodePos->printNode(head);
    newNode->printNode(head);
}
void print(){
    Node* temp=head;
    while(temp != NULL){
        //temp->printNode(temp);
        printf("%d ",temp->data);
        temp=temp->next;

    }
    printf("\n");
}
main(){
    head=NULL;
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,2);
    print();
}
