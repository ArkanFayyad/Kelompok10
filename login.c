#include <stdio.h>
#include <string.h>

int login() {
    char username[20], password[20];
    const char correct_user[] = "kasir";
    const char correct_pass[] = "1234";

    printf("Masukkan Username: ");
    scanf("%19s", username); // Use %19s to prevent buffer overflow
    printf("Masukkan Password: ");
    scanf("%19s", password); // Use %19s to prevent buffer overflow

    if (strcmp(username, correct_user) == 0 && strcmp(password, correct_pass) == 0) {
        printf("Login berhasil!\n");
        return 1;
    } else {
        printf("Username atau Password salah!\n");
        return 0;
    }
}
