#include <stdio.h>
#include <stdlib.h>

struct Node{
    char text[100];
    struct Node* next;
    struct Node* prev;
};

Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


int main(){
    int N, startPos, stepsBack;
    



    return 0;
}