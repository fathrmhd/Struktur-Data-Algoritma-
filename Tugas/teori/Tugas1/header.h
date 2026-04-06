#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int nilai;
    struct Node *next;
};

//deklarasi paramater function linked list
struct Node* buatNode(int data);
void tambahNode(struct Node** head, int data);
void tampilkanList(struct Node* head);
void buatList(struct Node** head);
void deleteList(struct Node** head);

//deklarasi parameter function soal
struct Node* gabungList(struct Node** list, int ukuraList);
struct Node* partisiList(struct Node* head, int x);
struct Node* hapusDuplikasi(struct Node* head);
struct Node* hapusDariAkhir(struct Node* head, int n);
struct Node* ganjilGenaplist(struct Node *head);
bool apaPalindrom(struct Node *head);
struct Node* hapusElemen(struct Node* head, int x);
void reorderList(struct Node* head);
struct Node* reverseAntara(struct Node* head, int kiri, int kanan);
struct Node* modifiedList(int *num, int numSize, struct Node* head);