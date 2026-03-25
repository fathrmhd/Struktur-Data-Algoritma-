#include <stdio.h>
#include <stdlib.h>

struct Node{
    char text[100];
    struct Node* next;
    struct Node* prev;
};

int main(){
    int N, startPos, stepsBack;
    struct Node *head = NULL;
    head = (struct Node *)malloc(sizeof(struct Node));

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        gets(head->text);
        head->next = 
    }



    return 0;
}