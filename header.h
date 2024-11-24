#ifndef HEADER_H
#define HEADER_H

// Struktur Barang
typedef struct {
    int id;
    char nama[50];
    char kategori[30];
    float harga;
    int stok;
} Barang;

// Struktur Member
typedef struct {
    int id;
    char nama[50];
    int poin;
} Member;

// Fungsi untuk login
int login();

// Fungsi untuk membaca dan menulis barang
void bacaBarang(Barang *barang, int *count);
void tulisBarang(Barang *barang, int count);
void tambahBarang(Barang *barang, int *count);
void hapusBarang(Barang *barang, int *count, int id);
void lihatBarang(Barang *barang, int count);
void tambahStok(Barang *barang, int count, int id, int stok);

// Fungsi untuk laporan penjualan
void laporanPenjualan();

// Fungsi untuk mengelola member
void tambahMember(Member *member, int *count);
void tambahPoin(Member *member, int count, int id, int poin);

// Fungsi untuk pembayaran dan diskon
void pembayaran(float total, float diskon);

// Fungsi untuk melihat daftar member
void lihatMember(Member *member, int count);

#endif
