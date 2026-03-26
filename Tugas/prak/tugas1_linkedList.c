#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char text[100];
    struct Node* next;
    struct Node* prev;
}Node;

Node *createNode(char *inputText){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        return NULL;
    }

    int i = 0;

    while(inputText[i] != '\0' && inputText[i] != '\n' && i < 99){
        newNode->text[i] = inputText[i];
        i++;
    }
    newNode->text[i] = '\0';

    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data){
    Node *newNode = createNode(data);

    if(*head == NULL){
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

int main(){
    int N, startPos, stepsBack;
    Node *head = NULL;  
    scanf("%d", &N);
    
    insertAtBeginning(&head, fgets(head->text, 100, stdin));
    for(int i = 1; i < N; i++){
        insertAtEnd(&head, fgets(head->text, 100, stdin));
    }
    

    return 0;
}