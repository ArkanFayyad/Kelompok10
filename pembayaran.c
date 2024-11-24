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
void tampilanbarang() {
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
void tambahbarang() {
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

// Fungsi pembayaran - Mengurangi stok barang sesuai jumlah yang dibeli
void pembayaran() {
    int itemIndex, quantity;

    printf("\n===== PROSES PEMBAYARAN =====\n");
    tampilanbarang();  // Menampilkan daftar barang yang tersedia

    printf("Masukkan nomor barang yang ingin dibeli: ");
    scanf("%d", &itemIndex);

    if (itemIndex < 1 || itemIndex > itemCount) {
        printf("Nomor barang tidak valid.\n");
        return;
    }

    printf("Masukkan jumlah barang yang ingin dibeli: ");
    scanf("%d", &quantity);

    // Mengurangi stok barang sesuai jumlah yang dibeli
    if (quantity > store[itemIndex - 1].stock) {
        printf("Stok tidak cukup. Stok saat ini: %d\n", store[itemIndex - 1].stock);
        return;
    }

    store[itemIndex - 1].stock -= quantity;
    printf("Pembayaran berhasil! Stok barang yang tersisa: %d\n", store[itemIndex - 1].stock);
}

// Menu utama
void menu() {
    int choice;

    while (1) {
        printf("\nMenu Toko:\n");
        printf("1. Tampilkan Barang\n");
        printf("2. Tambah Barang Baru\n");
        printf("3. Proses Pembayaran\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                tampilanbarang();
                break;
            case 2:
                tambahbarang();
                break;
            case 3:
                pembayaran();
                break;
            case 4:
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
