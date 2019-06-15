#include <stdio.h>
#include <stdlib.h>

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
    Node* nodeBeforePos = head;
    for (int i=0; i<position-2; i++){
        nodeBeforePos=nodeBeforePos->next;
    }
    newNode->next=nodeBeforePos->next;
    nodeBeforePos->next=newNode;
}

void deleteNode(int position){
    if(position == 1){
        Node* arrayHead=head;
        head=arrayHead->next;
        free(arrayHead);
        return;
    }
    Node* nodeBeforePos=head;
    Node* nodeOnPos;
    for(int i=0; i<position-2; i++){
        nodeBeforePos=nodeBeforePos->next;
    }
    nodeOnPos=nodeBeforePos->next;
    nodeBeforePos->next=nodeOnPos->next;
    free(nodeOnPos);
}
void printLinkList(){
    Node* temp=head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp=temp->next;

    }
    printf("\n");
}

int takeUserInput(char str[]){
    printf(str);
    printf("\n");
    int n;
    scanf("%d",&n);
    return n;
}
main(){
    head=NULL;
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,2);
    printLinkList();
    int position=takeUserInput("Enter position for delete element");
    deleteNode(position);
    printLinkList();
}
