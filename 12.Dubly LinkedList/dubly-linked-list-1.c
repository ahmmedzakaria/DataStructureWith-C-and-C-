#include <stdio.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head;
int length=0;

int takeUserInput(char str[]){
    printf(str);
    printf("\n");
    int n;
    scanf("%d",&n);
    return n;
}


void printDublyLinkList(){
    struct Node* temp=head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp=temp->next;

    }
    printf("\nLength: %d\n",length);
}
struct Node* getNewNode(int data){
    struct Node* newNodePtr=(struct Node*)malloc(sizeof(struct Node));
    newNodePtr->data=data;
    newNodePtr->prev=NULL;
    newNodePtr->next=NULL;
}

void insertNodeFirst(int data){
    struct Node* newNodePtr=getNewNode(data);
    if(head == NULL){
        head=newNodePtr;
        length++;
        return;
    }
    newNodePtr->next=head;
    head->prev=newNodePtr;
    head=newNodePtr;
    length++;
}

void insertNodeLast(int data){
    struct Node* newNodePtr=getNewNode(data);
    if(head == NULL){
        head=newNodePtr;
        length++;
        return;
    }
    struct Node* lastNodePtr=head;
    while(lastNodePtr->next != NULL){
        lastNodePtr=lastNodePtr->next;
    }

    lastNodePtr->next=newNodePtr;
    length++;
}
void insertNodeByPosition(int position){
    //int position=takeUserInput("\nEnter value position for inserting value\n");
    int data=takeUserInput("\nEnter value for insert\n");
    struct Node* newNodePtr=getNewNode(data);
    if(head == NULL){
        head=newNodePtr;
        length++;
        return;
    }
    struct Node* nodeAtPos=head;
    for(int i=0; i<position-1; i++){
        nodeAtPos=nodeAtPos->next;
    }
    newNodePtr->next=nodeAtPos->next;
    newNodePtr->prev=nodeAtPos->prev;
    nodeAtPos->prev->next=newNodePtr;
    free(nodeAtPos);
    length++;
}
main(){
    head=NULL;
    insertNodeFirst(3);
    insertNodeFirst(2);
    insertNodeFirst(1);

    insertNodeLast(4);
    insertNodeLast(5);
    printDublyLinkList();

    insertNodeByPosition(3);

    printDublyLinkList();
}
