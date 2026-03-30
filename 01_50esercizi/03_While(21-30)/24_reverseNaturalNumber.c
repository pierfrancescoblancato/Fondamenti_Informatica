#include <stdio.h>

int main() {
    printf("\n exercise n24 \n");
    int n, reverse = 0;

    printf("Enter a natural number greatest of 0: ");

    scanf("%d", &n);

    if (n > 0)
    {
        while (n != 0) {
        reverse = reverse * 10 + n % 10;
        // n % 10 prende l’ultima cifra di n
        // reverse * 10 sposta a sinistra le cifre già invertite
        // la somma aggiunge la nuova cifra in fondo

        n = n / 10;
        // Rimuove l’ultima cifra da n dividendo per 10
        // Il ciclo continua finché n non diventa 0
    }
    }else{
        printf("The number is not natural greater than 0.\n");
        return 1;
    }
    printf("Reverse number: %d\n", reverse);

    return 0;
}
