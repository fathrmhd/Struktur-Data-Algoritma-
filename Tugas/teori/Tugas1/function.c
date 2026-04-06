#include "header.h"

//Daftar Function Yang diminta soal
//1
struct Node* gabungList(struct Node** list, int ukuraList) {
    int arr[100];
    int count = 0;
    for(int i=0; i<ukuraList; i++){
        struct Node*current = list[i];
        while(current != NULL){
            arr[count] = current->nilai;
            count++;
            current = current->next;

        }
    }
    for(int i=0;i<count-1;i++){
        for(int j=i+1;j<count;j++){
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    struct Node*head = NULL;
    struct Node*tail = NULL;
    for(int i=0; i<count;i++){
        struct Node*node =malloc(sizeof(struct Node));
        node->nilai = arr[i];
        node->next = NULL;
        if(head == NULL){
            head = node;
            tail = node;
        } else{
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

//2
struct Node* partisiList(struct Node* head, int x) {
    struct Node * current = head;
    struct Node *kecilHead = NULL;
    struct Node *kecilTail = NULL;
    struct Node *besarHead = NULL;
    struct Node *besarTail = NULL;
    
    while (current != NULL){
        struct Node *next = current->next;
        current->next = NULL;
        int nilai = current->nilai;
        if (x > nilai){
            if (kecilHead ==NULL){
                kecilHead = current;
                kecilTail = current; 
            } else {
                kecilTail->next = current; 
                kecilTail = current;
            }
            
        } else {
            if (besarHead ==NULL){
                besarHead = current;
                besarTail = current;
            } else {
                besarTail->next = current; 
                besarTail = current;
            }
        }
        current = next;
    }
    if (kecilTail != NULL){
        kecilTail->next = besarHead;
        return kecilHead;
    }
    return besarHead;
}

//3
struct Node* hapusDuplikasi(struct Node* head){
    struct Node* current = head;   

    while (current != NULL && current->next != NULL) { 
        if (current->nilai == current->next->nilai) {    
            struct Node* temp = current->next;       
            current->next = current->next->next;       
            free(temp);                                
        } 
        else {
            current = current->next;                   
        }
    }

    return head; 
}

//4
struct Node* hapusDariAkhir(struct Node* head, int n) {
    int panjang = 0;           
    struct Node* temp = head;  

    while (temp != NULL) {    
        panjang++;
        temp = temp->next;
    }

    int posisi = panjang - n;  
    if (posisi == 0) {         
        struct Node* hapus = head;
        head = head->next;    
        free(hapus);           
        return head;
    }

    temp = head;

    for (int i = 0; i < posisi - 1; i++) { 
        temp = temp->next;
    }

    struct Node* hapus = temp->next; 
    temp->next = hapus->next;        
    free(hapus);                   
    return head; 
}

//5
struct Node* ganjilGenaplist(struct Node *head){
    struct Node *gahead = NULL;
    struct Node *gatail = NULL;

    struct Node *gehead = NULL;
    struct Node *getail = NULL;

    struct Node *curr = head;
    
    while (curr != NULL) {

        if (curr->nilai % 2 != 0) {      
            if (gahead == NULL) {
                gahead = gatail = curr;
            } else {
                gatail->next = curr;
                gatail = curr;
            }
        } 
        else {                         
            if (gehead == NULL) {
                gehead = getail = curr;
            } else {
                getail->next = curr;
                getail = curr;
            }
        }

        curr = curr->next;
    }

    if (gahead == NULL) {
        if (getail != NULL) getail->next = NULL;
        return gehead;
    }

    if (gehead == NULL) {
        if (gatail != NULL) gatail->next = NULL;
        return gahead;
    }

    gatail->next = gehead;
    getail->next = NULL;

    return gahead;
}

//6
bool apaPalindrom(struct Node *head){
    if (head == NULL) return true;

    int arr[100000];
    int n = 0;

    struct Node *curr = head;

    while (curr != NULL) {
        arr[n++] = curr->nilai;
        curr = curr->next;
    }

    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (arr[left] != arr[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

//7
struct Node* hapusElemen(struct Node* head, int x) {
    while (head != NULL && head->nilai == x) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    struct Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->nilai == x) {
            struct Node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
    return head;
}

//8
void reorderList(struct Node* head) {
    if (!head || !head->next) 
	return;

    struct Node *pelan = head, *cepat = head;
    while (cepat->next && cepat->next->next) {
        pelan = pelan->next;
        cepat = cepat->next->next;
    }
    
    struct Node *prev = NULL, *curr = pelan->next, *nxt;
    pelan->next = NULL; 

    while (curr) {
        nxt = curr->next;  
        curr->next = prev;
        prev = curr;       
        curr = nxt;         
    }
    
    struct Node *p1 = head, *p2 = prev;
    while (p2) {
        struct Node *t1 = p1->next; 
        struct Node *t2 = p2->next; 

        p1->next = p2; 
        p2->next = t1;    
        p1 = t1; 
        p2 = t2; 
    } 

//9.
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

//10
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

//function untuk linked list
struct Node* buatNode(int nilai) {
    struct Node* nodeBaru = (struct Node*)malloc(sizeof(struct Node)); 
    nodeBaru->nilai = nilai;      
    nodeBaru->next = NULL;      
    return nodeBaru;           
}

void tambahNode(struct Node** head, int nilai) {
    struct Node* nodeBaru = buatNode(nilai); 

    if (*head == NULL) {        
        *head = nodeBaru;       
        return;
    }

    struct Node* temp = *head;  

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = nodeBaru;      
}

void tampilkanList(struct Node* head) {
    struct Node* temp = head;   

    while (temp != NULL) {      
        printf("%d ", temp->nilai);
        temp = temp->next;        
    }

    printf("\n"); 
}

void buatList(struct Node** head){
    int size, nilai;
    printf("Masukkan Ukuran Linked List yang ingin anda buat: ");
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        printf("Masukkan List ke %d: ", i + 1);
        scanf("%d", &nilai);
        tambahNode(head, nilai);
    }
}

void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current); 
        current = next;
    }
    
    *head = NULL;
}