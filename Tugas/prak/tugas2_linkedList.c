#include <stdio.h>
#include <stdlib.h>

struct Song{
    char tittle[50];
    struct Song *next;
};

struct Song *createNode(char *inputText){
    struct Song *newSong = (struct Song*)malloc(sizeof(struct Song));
    if(!newSong){
        return NULL;
    }

    int i = 0;

    while(inputText[i] != '\0' && inputText[i] != '\n' && i < 49){
        newSong->tittle[i] = inputText[i];
        i++;
    }

    newSong->tittle[i] = '\0';

    newSong->next = NULL;
    return newSong;
}

void insertAtEnd(struct Song** head, char *inputText){
    struct Song *newSong = createNode(inputText);

    if(*head == NULL){
        *head = newSong;
        newSong->next = *head;
    }
    else{
        struct Song *temp = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        temp->next = newSong;
        newSong->next = *head;
    }
}

int main(){
    int N, M;
    char temp[100];
    char command[10];
    struct Song *head = NULL;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%s", temp);
        insertAtEnd(&head, temp);
    }

    scanf("%d", &M);

    struct Song *current = head;

    for(int i = 0; i < M; i++){
        scanf("%s", command);

        if(command[0] == 'S'){
            if(current != NULL){
                printf("%s\n", current->tittle);
            }
        }
        else if(command[0] == 'N'){
            if(current != NULL){
                current = current->next;
            }
        }
    }

    return 0;
}