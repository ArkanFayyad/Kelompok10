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

// Fungsi untuk menampilkan semua barang
void tampilanbarang() {
    printf("\nDaftar Barang di Toko:\n");
    if (itemCount == 0) {
        printf("Belum ada barang di toko.\n");
    } else {
        for (int i = 0; i < itemCount; i++) {
            printf("%d. %s - Kategori: %s - Harga: %.2f - Stok: %d\n", 
                   i + 1, store[i].name, store[i].category, store[i].price, store[i].stock);
        }
    }
    printf("\n");
}

// Fungsi untuk menambah stok barang
void tambahstock() {
    int index, additionalStock;
    tampilanbarang(); // Menampilkan daftar barang

    printf("Masukkan nomor barang yang ingin ditambah stoknya: ");
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Nomor barang tidak valid.\n");
        return;
    }

    printf("Masukkan jumlah stok yang ingin ditambahkan: ");
    scanf("%d", &additionalStock);

    store[index - 1].stock += additionalStock; // Menambah stok barang
    printf("Stok berhasil ditambahkan! Stok saat ini: %d\n", store[index - 1].stock);
}

// Menu utama
void menu() {
    int choice;

    while (1) {
        printf("\nMenu Toko:\n");
        printf("1. Tambah Stok Barang\n");
        printf("2. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                tambahstock();
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
