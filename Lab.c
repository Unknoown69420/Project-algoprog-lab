#include <stdio.h>
#include <string.h>


struct Menu {
    int id;
    char nama[30];
    int harga;
};

void tampilMenu(struct Menu menu[], int n);
int hitungTotal(struct Menu menu[], int pilihan[], int jumlah[], int n);

int main() {

    struct Menu appetizer[] = {
        {1, "Spring Roll", 10000},
        {2, "French Fries", 12000}
    };

    struct Menu mainCourse[] = {
        {1, "Nasi Goreng", 15000},
        {2, "Mie Ayam", 12000},
        {3, "Ayam Geprek", 18000}
    };

    struct Menu drinks[] = {
        {1, "Es Teh", 5000},
        {2, "Jus Jeruk", 8000}
    };

    struct Menu dessert[] = {
        {1, "Ice Cream", 7000},
        {2, "Pudding", 6000}
    };

    int pilihan[20], jumlah[20];
    int hargaItem[20];
    char namaItem[20][30];
    int totalItem = 0;
    char lanjut;
    int kategori;

    do {
        printf("\n===== KATEGORI MENU =====\n");
        printf("1. Appetizer\n");
        printf("2. Main Course\n");
        printf("3. Drinks\n");
        printf("4. Dessert\n");
        printf("Pilih kategori (1-4): ");
        scanf("%d", &kategori);

        int pilihMenu, qty;

        switch (kategori) {
            case 1:
                tampilMenu(appetizer, 2);
                printf("Pilih menu: ");
                scanf("%d", &pilihMenu);
                printf("Jumlah: ");
                scanf("%d", &qty);

                strcpy(namaItem[totalItem], appetizer[pilihMenu-1].nama);
                hargaItem[totalItem] = appetizer[pilihMenu-1].harga;
                break;

            case 2:
                tampilMenu(mainCourse, 3);
                printf("Pilih menu: ");
                scanf("%d", &pilihMenu);
                printf("Jumlah: ");
                scanf("%d", &qty);

                strcpy(namaItem[totalItem], mainCourse[pilihMenu-1].nama);
                hargaItem[totalItem] = mainCourse[pilihMenu-1].harga;
                break;

            case 3:
                tampilMenu(drinks, 2);
                printf("Pilih menu: ");
                scanf("%d", &pilihMenu);
                printf("Jumlah: ");
                scanf("%d", &qty);

                strcpy(namaItem[totalItem], drinks[pilihMenu-1].nama);
                hargaItem[totalItem] = drinks[pilihMenu-1].harga;
                break;

            case 4:
                tampilMenu(dessert, 2);
                printf("Pilih menu: ");
                scanf("%d", &pilihMenu);
                printf("Jumlah: ");
                scanf("%d", &qty);

                strcpy(namaItem[totalItem], dessert[pilihMenu-1].nama);
                hargaItem[totalItem] = dessert[pilihMenu-1].harga;
                break;

            default:
                printf("Kategori tidak valid!\n");
                continue;
        }

        jumlah[totalItem] = qty;
        totalItem++;

        printf("Tambah pesanan? (y/n): ");
        scanf(" %c", &lanjut);

    } while (lanjut == 'y' || lanjut == 'Y');

    int totalHarga = 0;
    int *ptrTotal = &totalHarga;

    for (int i = 0; i < totalItem; i++) {
        *ptrTotal += hargaItem[i] * jumlah[i];
    }

    printf("\n===== RINGKASAN PESANAN =====\n");
    for (int i = 0; i < totalItem; i++) {
        printf("%s x %d = Rp %d\n",
               namaItem[i],
               jumlah[i],
               hargaItem[i] * jumlah[i]);
    }

    printf("-----------------------------\n");
    printf("TOTAL HARGA : Rp %d\n", *ptrTotal);

    return 0;
}

void tampilMenu(struct Menu menu[], int n) {
    printf("\n===== MENU =====\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %-15s Rp %d\n",
               menu[i].id,
               menu[i].nama,
               menu[i].harga);
    }
}
