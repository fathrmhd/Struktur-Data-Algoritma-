#include <stdio.h>
#include <stdlib.h>

struct Node{
    int nilai;
    struct Node *next;
};

struct Node* reverseAntara(struct Node* head, int kiri, int kanan);
struct Node* modifiedList(int *num, int numSize, struct Node* head);