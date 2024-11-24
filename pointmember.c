#include <stdio.h>

// Fungsi untuk menghitung poin member berdasarkan total belanja
float hitungPoinMember(float totalbelanja) {
    if (totalbelanja < 50000) {
        return 0;
    } else {
        return totalbelanja / 50000; // Poin berdasarkan setiap kelipatan 50.000
    }
}

int main() {
    float totalbelanja, PoinMember;

    // Meminta input total belanja dari pengguna
    printf("Masukkan Total Belanja: ");
    scanf("%f", &totalbelanja);

    // Menghitung poin member menggunakan fungsi hitungPoinMember
    PoinMember = hitungPoinMember(totalbelanja);

    // Menampilkan poin member
    printf("Poin Member: %.0f\n", PoinMember);

    return 0;
}
