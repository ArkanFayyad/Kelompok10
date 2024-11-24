#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int stock;
    char category[50]; // Kategori barang (misal: Elektronik, Pakaian, dll)
    float price;       // Harga barang
} Item;

Item store[MAX_ITEMS];
int itemCount = 0;

// Menambahkan barang baru
void tambahbarang() {
    if (itemCount >= MAX_ITEMS) {
        printf("Toko penuh, tidak bisa menambah barang baru.\n");
        return;
    }

    char name[50];
    char category[50];
    int stock;
    float price;

    printf("Masukkan nama barang: ");
    scanf(" %[^\n]", name);

    printf("Masukkan kategori barang: ");
    scanf(" %[^\n]", category);

    printf("Masukkan harga barang: ");
    scanf("%f", &price);

    printf("Masukkan jumlah stok awal: ");
    scanf("%d", &stock);

    strcpy(store[itemCount].name, name);
    strcpy(store[itemCount].category, category);
    store[itemCount].price = price;
    store[itemCount].stock = stock;
    itemCount++;

    printf("Barang berhasil ditambahkan!\n");
}

// Menu utama
void menu() {
    int choice;

    while (1) {
        printf("\nMenu Toko:\n");
        printf("1. Tambah Barang Baru\n");
        printf("2. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                tambahbarang();
                break;
            case 2:
                printf("Terima kasih telah menggunakan program ini!\n");
                return;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
