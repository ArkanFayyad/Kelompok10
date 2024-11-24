#include<stdio.h>

int main() {

    float totalbelanja;       
    float diskon;             
    float totalSetelahDiskon; 

  
    printf("Masukkan total belanja: ");
    scanf("%f", &totalbelanja);  

    if (totalbelanja >= 200000) {
        diskon = 0.10 * totalbelanja;  
        totalSetelahDiskon = totalbelanja - diskon;  
        printf("Anda mendapatkan diskon 10%%: -%.2f\n", diskon);
        printf("Total setelah diskon: %.2f\n", totalSetelahDiskon);
    } else {
        totalSetelahDiskon = totalbelanja; 
        printf("Total belanja: %.2f\n", totalSetelahDiskon);
    }

    return 0;
}
