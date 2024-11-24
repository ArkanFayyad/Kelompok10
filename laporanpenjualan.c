#include <stdio.h>

// Fungsi untuk menampilkan laporan penjualan
void laporanPenjualan() {
    int itemIndex, quantity;
    float totalBayar = 0, diskon = 0, totalSetelahDiskon;

    // Daftar harga barang (contoh)
    float hargaBarang[] = {100000, 150000, 200000};
    int stokBarang[] = {10, 5, 3};

    printf("\n===== Laporan Penjualan =====\n");
    
    // Menampilkan daftar barang untuk dipilih
    printf("\nDaftar Barang:\n");
    printf("1. Barang A - Harga: 100000 - Stok: 10\n");
    printf("2. Barang B - Harga: 150000 - Stok: 5\n");
    printf("3. Barang C - Harga: 200000 - Stok: 3\n");

    printf("Masukkan nomor barang yang ingin dibeli: ");
    scanf("%d", &itemIndex);

    // Validasi input barang yang dipilih
    if (itemIndex < 1 || itemIndex > 3) {
        printf("Nomor barang tidak valid.\n");
        return;
    }

    printf("Masukkan jumlah barang yang ingin dibeli: ");
    scanf("%d", &quantity);

    // Validasi stok barang
    if (quantity > stokBarang[itemIndex - 1]) {
        printf("Stok tidak cukup.\n");
        return;
    }

    // Menghitung total harga
    totalBayar = hargaBarang[itemIndex - 1] * quantity;
    printf("Total harga untuk %d barang adalah: %.2f\n", quantity, totalBayar);

    // Cek diskon
    if (totalBayar >= 200000) {
        diskon = 0.10 * totalBayar;  // 10% diskon
        totalSetelahDiskon = totalBayar - diskon;
        printf("Anda mendapatkan diskon 10%%: -%.2f\n", diskon);
        printf("Total setelah diskon: %.2f\n", totalSetelahDiskon);
    } else {
        totalSetelahDiskon = totalBayar;
    }

    // Mengurangi stok barang
    stokBarang[itemIndex - 1] -= quantity;

    printf("Pembayaran berhasil! Stok barang yang tersisa: %d\n", stokBarang[itemIndex - 1]);
    printf("Total yang harus dibayar: %.2f\n", totalSetelahDiskon);

    // Menyimpan dan menampilkan laporan penjualan
    printf("\n===== LAPORAN PENJUALAN =====\n");
    printf("Barang yang terjual: %d x Barang %c\n", quantity, 'A' + itemIndex - 1);
    printf("Total penjualan: %.2f\n", totalSetelahDiskon);
    printf("Diskon: %.2f\n", diskon);
    printf("Total yang dibayar: %.2f\n", totalSetelahDiskon);
}

int main() {
    laporanPenjualan();  // Memanggil fungsi laporan penjualan
    return 0;
}
