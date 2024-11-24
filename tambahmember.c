#include <stdio.h>

int main() {
    char nama[50];
    float totalbelanja;
    int notelp;

    printf("=====MASUKKAN MEMBER=====\n");

    // Input nama dengan fgets (membaca spasi juga)
    printf("\nMasukkan nama anda: ");
    fgets(nama, sizeof(nama), stdin);  // Menggunakan fgets untuk input nama (termasuk spasi)

    // Menghapus karakter newline jika ada setelah input nama
    size_t len = strlen(nama);
    if (len > 0 && nama[len - 1] == '\n') {
        nama[len - 1] = '\0';  // Menghapus karakter newline
    }

    // Input nomor HP
    printf("\nMasukkan No HP: ");
    scanf("%d", &notelp);

    // Mengosongkan buffer setelah scanf
    while (getchar() != '\n');  // Membersihkan karakter newline yang mungkin tersisa di buffer

    // Input total belanja
    printf("Masukkan Total Belanja: ");
    scanf("%f", &totalbelanja);

    // Menampilkan informasi member
    printf("=====SELAMAT DATANG MEMBER=====\n");
    printf("Nama            : %s\n", nama);
    printf("No HP           : %d\n", notelp);
    printf("Total Belanja   : %.2f\n", totalbelanja); 
    printf("================================\n");

    return 0;
}
