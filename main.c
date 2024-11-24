#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_MEMBERS 50

typedef struct {
    char name[50];
    char category[30];
    int stock;
    float price;
} Item;

typedef struct {
    char name[50];
    int points;
} Member;

Item store[MAX_ITEMS];
Member members[MAX_MEMBERS];
int itemCount = 0, memberCount = 0;
float totalSales = 0;

// Fungsi login
int login() {
    char username[100];
    char password[100];

    printf("Masukkan username Anda: ");
    scanf("%s", username);
    printf("Masukkan password Anda: ");
    scanf("%s", password);

    if ((strcmp(username, "kelompok4") == 0) && (strcmp(password, "admin123") == 0)) {
        printf("Selamat, Anda berhasil login!\n\n");
        return 1;
    } else {
        printf("Maaf, username atau password Anda salah.\n");
        return 0;
    }
}

// Menampilkan semua barang
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

// Menampilkan barang berdasarkan kategori
void barangKategori() {
    char kategori[30];
    printf("Masukkan kategori barang yang ingin dilihat: ");
    scanf(" %[^\n]", kategori);

    printf("\nBarang dalam kategori '%s':\n", kategori);
    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(store[i].category, kategori) == 0) {
            printf("%d. %s - Harga: %.2f - Stok: %d\n", 
                i + 1, store[i].name, store[i].price, store[i].stock);
            found = 1;
        }
    }

    if (!found) {
        printf("Tidak ada barang dalam kategori ini.\n");
    }
}

// Menambahkan barang baru
void tambahbarang() {
    if (itemCount >= MAX_ITEMS) {
        printf("Toko penuh, tidak bisa menambah barang baru.\n");
        return;
    }

    char name[50], category[30];
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

// Menghapus barang
void hapusbarang() {
    int index;
    tampilanbarang();
    printf("Masukkan nomor barang yang ingin dihapus: ");
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Nomor barang tidak valid.\n");
        return;
    }

    for (int i = index - 1; i < itemCount - 1; i++) {
        store[i] = store[i + 1];
    }
    itemCount--;
    printf("Barang berhasil dihapus!\n");
}

// Menambah stok barang
void tambahstock() {
    int index, additionalStock;
    tampilanbarang();
    printf("Masukkan nomor barang yang ingin ditambah stoknya: ");
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Nomor barang tidak valid.\n");
        return;
    }

    printf("Masukkan jumlah stok yang ingin ditambahkan: ");
    scanf("%d", &additionalStock);

    store[index - 1].stock += additionalStock;
    printf("Stok berhasil ditambahkan!\n");
}

// Mengurangi stok barang
void kurangiStok() {
    int index, reduceStock;
    tampilanbarang();
    printf("Masukkan nomor barang yang ingin dikurangi stoknya: ");
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Nomor barang tidak valid.\n");
        return;
    }

    printf("Masukkan jumlah stok yang ingin dikurangi: ");
    scanf("%d", &reduceStock);

    if (store[index - 1].stock >= reduceStock) {
        store[index - 1].stock -= reduceStock;
        printf("Stok berhasil dikurangi!\n");
    } else {
        printf("Stok tidak mencukupi!\n");
    }
}

// Melakukan pembayaran
void pembayaran() {
    int index, quantity;
    float discount = 0.0;
    tampilanbarang();

    printf("Masukkan nomor barang yang ingin dibeli: ");
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Nomor barang tidak valid.\n");
        return;
    }

    printf("Masukkan jumlah barang yang ingin dibeli: ");
    scanf("%d", &quantity);

    if (quantity > store[index - 1].stock) {
        printf("Stok tidak mencukupi.\n");
        return;
    }

    printf("Masukkan diskon (dalam persen): ");
    scanf("%f", &discount);

    float total = quantity * store[index - 1].price;
    total -= total * (discount / 100);

    store[index - 1].stock -= quantity;
    totalSales += total;

    printf("Pembayaran berhasil. Total yang harus dibayar: %.2f\n", total);
}

// Menambahkan member baru
void tambahMember() {
    if (memberCount >= MAX_MEMBERS) {
        printf("Jumlah member penuh.\n");
        return;
    }

    char name[50];
    printf("Masukkan nama member baru: ");
    scanf(" %[^\n]", name);

    strcpy(members[memberCount].name, name);
    members[memberCount].points = 0;
    memberCount++;
    printf("Member berhasil ditambahkan.\n");
}

// Menambah poin member
void tambahPoin() {
    char name[50];
    int points;

    printf("Masukkan nama member: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i].name, name) == 0) {
            printf("Masukkan poin yang ingin ditambahkan: ");
            scanf("%d", &points);
            members[i].points += points;
            printf("Poin berhasil ditambahkan untuk %s.\n", members[i].name);
            return;
        }
    }

    printf("Member tidak ditemukan.\n");
}

// Laporan penjualan
void laporanPenjualan() {
    printf("\nTotal Penjualan: %.2f\n", totalSales);
}

// Menu utama
void menu() {
    int choice;

    while (1) {
        printf("\nMenu Toko:\n");
        printf("1. Tampilkan Barang\n");
        printf("2. Tambah Barang Baru\n");
        printf("3. Hapus Barang\n");
        printf("4. Tambah Stok Barang\n");
        printf("5. Kurangi Stok Barang\n");
        printf("6. Lihat Barang Berdasarkan Kategori\n");
        printf("7. Pembayaran\n");
        printf("8. Tambah Member\n");
        printf("9. Tambah Poin Member\n");
        printf("10. Laporan Penjualan\n");
        printf("11. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: tampilanbarang(); break;
            case 2: tambahbarang(); break;
            case 3: hapusbarang(); break;
            case 4: tambahstock(); break;
            case 5: kurangiStok(); break;
            case 6: barangKategori(); break;
            case 7: pembayaran(); break;
            case 8: tambahMember(); break;
            case 9: tambahPoin(); break;
            case 10: laporanPenjualan(); break;
            case 11: printf("Terima kasih telah menggunakan program ini!\n"); return;
            default: printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
}

int main() {
    if (login()) {
        menu();
    }
    return 0;
}
