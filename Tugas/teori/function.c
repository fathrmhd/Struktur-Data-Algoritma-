#include "header.h"

struct Node* reverseAntara(struct Node* head, int kiri, int kanan){
    if(head == NULL || kiri == kanan){
        return head;
    }
    struct Node temp;
    temp.next = head;
    struct Node* prev = &temp;

    for(int i = 0; i < kiri - 1; i++){
        prev = prev->next;
    }

    struct Node* first = prev->next;
    struct Node* move = first->next;

    for(int i = 0; i < kanan - kiri; i++){
        first->next = move->next;
        move->next = prev->next;
        prev->next = move;
        move = first->next;
    }

    return temp.next;
};

struct Node* modifiedList(int *num, int numSize, struct Node* head){
    int delete[106] = {0};
    for(int i = 0; i < numSize; i++){
        delete[num[i]] = 1;
    }

    struct Node temp;
    temp.next = head;
    struct Node* current = &temp;

    while(current->next != NULL){
        if(delete[current->next->nilai]){
            struct Node* temp2 = current->next;
            current->next = current->next->next;
            free(temp2);
        }
        else{
            current = current->next;
        }
    }
    return temp.next;
}