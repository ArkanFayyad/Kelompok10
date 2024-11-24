#include <stdio.h>

// Fungsi untuk mengurangi stok barang
void kurangiStock() {
    int index, quantityToReduce;

    tampilanbarang();  // Menampilkan semua barang yang ada di toko

    printf("Masukkan nomor barang yang ingin dikurangi stoknya: ");
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Nomor barang tidak valid.\n");
        return;
    }

    printf("Masukkan jumlah stok yang ingin dikurangi: ");
    scanf("%d", &quantityToReduce);

    if (quantityToReduce > store[index - 1].stock) {
        printf("Jumlah pengurangan stok melebihi stok yang ada. Stok saat ini: %d\n", store[index - 1].stock);
        return;
    }

    store[index - 1].stock -= quantityToReduce;
    printf("Stok barang berhasil dikurangi. Stok tersisa: %d\n", store[index - 1].stock);
}
