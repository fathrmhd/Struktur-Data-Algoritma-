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

void insertAtEnd(Node** head, char *data){
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
    char temp[100];
    Node *head = NULL;  
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        scanf("%s", temp);
        insertAtEnd(&head, temp);
    }
    
    scanf("%d %d", &startPos, &stepsBack);
    
    Node *current = head;
    for(int i = 1; i < startPos && current != NULL; i++){
        current = current->next;
    }

    if(current != NULL){
        printf("Lompat ke node ke-%d: %s", startPos, current->text);
    }

    printf("\nMundur %d langkah:\n", stepsBack);

    int currentPos = startPos;

    for(int i = 0; i < stepsBack; i++){
        if(current->prev != NULL){
            current = current->prev;
            printf("%s\n", current->next);
            currentPos--;
        }
        else{
            printf("(Tidak bisa mundur lagi)\n");
            break;
        }
    }

    printf("\n posisi akhir: node ke-%d\n", currentPos);
    return 0;
}