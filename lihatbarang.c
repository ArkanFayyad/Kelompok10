#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// Struktur data untuk barang
typedef struct {
    char name[50];
    int stock;
    float price;
} Item;

Item store[MAX_ITEMS];
int itemCount = 0;  // Jumlah barang yang ada di toko

// Fungsi untuk menampilkan daftar barang yang ada
void melihatBarang() {
    printf("\nDaftar Barang di Toko:\n");
    if (itemCount == 0) {
        printf("Belum ada barang di toko.\n");
    } else {
        for (int i = 0; i < itemCount; i++) {
            printf("%d. %s - Harga: %.2f - Stok: %d\n", i + 1, store[i].name, store[i].price, store[i].stock);
        }
    }
}

// Fungsi untuk menambah barang baru
void tambahBarang() {
    if (itemCount >= MAX_ITEMS) {
        printf("Toko penuh, tidak bisa menambah barang baru.\n");
        return;
    }

    char name[50];
    int stock;
    float price;

    printf("Masukkan nama barang: ");
    scanf(" %[^\n]", name);

    printf("Masukkan harga barang: ");
    scanf("%f", &price);

    printf("Masukkan jumlah stok barang: ");
    scanf("%d", &stock);

    // Menambahkan barang ke dalam toko
    strcpy(store[itemCount].name, name);
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
        printf("1. Melihat Barang\n");
        printf("2. Tambah Barang Baru\n");
        printf("3. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                melihatBarang();
                break;
            case 2:
                tambahBarang();
                break;
            case 3:
                printf("Terima kasih telah menggunakan program ini!\n");
                return;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
}

int main() {
    menu();  // Memanggil menu utama
    return 0;
}
