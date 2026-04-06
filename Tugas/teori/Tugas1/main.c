#include "header.h"

int main(){
    int n, x, jumlahList, kiri, kanan, numSize;
    struct Node* head = NULL;

    do{
        printf("============List Fungsi============\n");
        printf("1. Gabung List\n");
        printf("2. Partisi List\n");
        printf("3. Hapus Duplikasi\n");
        printf("4. Hapus Dari Akhir\n");
        printf("5. Ganjil Genap List\n");
        printf("6. Apa Palindrom\n");
        printf("7. Hapus Elemen\n");
        printf("8. Reoder List\n");
        printf("9. Reverse Antara\n");
        printf("10. Modified List\n");
        printf("11. Keluar dari program\n");
        printf("Fungsi mana yang ingin Anda jalankan: ");
        scanf("%d", &n);

        if(n < 1 || n > 10){
            break;
        }

        switch (n){
        case 1:
            deleteList(&head);
            printf("Berapa banyak list yang ingin dibuat: ");
            scanf("%d", &jumlahList);

            struct Node** daftarList = malloc(jumlahList * sizeof(struct Node*));

            for(int i = 0; i < jumlahList; i++){
                daftarList[i] = NULL;
                printf("Membuat List ke %d\n", i + 1);
                buatList(&daftarList[i]);
            }
            head = gabungList(daftarList, jumlahList);
            printf("Return: ");
            tampilkanList(head);

            free(daftarList);
            getchar();
            getchar();
            break;
        
        case 2:
            deleteList(&head);
            buatList(&head);
            printf("Masukkan Nilai x : ");
            scanf("%d", &x);
            head = partisiList(head, x);
            printf("Return: ");
            tampilkanList(head);
            getchar();
            getchar();
            break;

        case 3: 
            deleteList(&head);
            buatList(&head);
            head = hapusDuplikasi(head);
            printf("Return: ");
            tampilkanList(head);
            getchar();
            getchar();
            break;

        case 4:
            deleteList(&head);
            buatList(&head);
            printf("Masukkan Nilai n: ");
            scanf("%d", &n);
            head = hapusDariAkhir(head, n);
            printf("Return: ");
            tampilkanList(head);
            getchar();
            getchar();
            break;

        case 5:
            deleteList(&head);
            buatList(&head);
            head = ganjilGenaplist(head);
            printf("Return: ");
            tampilkanList(head);
            getchar();
            getchar();
            break;

        case 6:
            deleteList(&head);
            buatList(&head);
            if(apaPalindrom(head)){
                printf("Return : True");
            }
            else{
                printf("Return : False");
            }
            getchar();
            getchar();
            break;

        case 7:
            deleteList(&head);
            buatList(&head);
            printf("Masukkan Nilai x : ");
            scanf("%d", &x);
            head = hapusElemen(head, x);
            printf("Return: ");
            tampilkanList(head);
            getchar();
            getchar();
            break;
            
        case 8:
            deleteList(&head);
            buatList(&head);
            reorderList(head);
            printf("Return: ");
            tampilkanList(head);
            getchar();
            getchar();
            break;

        case 9:
            deleteList(&head);
            buatList(&head);
            printf("Masukkan Nilai Kiri: ");
            scanf("%d", &kiri);
            printf("Masukkan Nilai Kanan: ");
            scanf("%d", &kanan);
            head = reverseAntara(head, kiri, kanan);
            printf("Return : ");
            tampilkanList(head);
            getchar();
            getchar();
            break;

        case 10:
            deleteList(&head);
            printf("Masukkan numSize: ");
            scanf("%d", &numSize);

            int *num = malloc(numSize * sizeof(int));
            printf("Masukkan %d angka untuk num: ", numSize);
            for(int i = 0; i < numSize; i++){
                scanf("%d", &num[i]);
            }

            buatList(&head);
            head = modifiedList(num, numSize, head);
            printf("Return : ");
            tampilkanList(head);
            
            free(num);
            getchar();
            getchar();
            break;
        
        default:
            break;
        }
    }while(n >= 1 &&  n <= 10);
    
    return 0;
}